#include "Fases/Fase.hpp"
#include "Fases/Fase.hpp"

namespace Fases
{
    Fase::Fase(int id, bool dois_jogadores):
        Estado(id),
        listaObstaculos(),
        listaInimigos(),
        listaJogadores(),
        listaProjeteis(),
        corpo(),
        pGC(),
        multiplayer(dois_jogadores)
    {
        pGEstados = Gerenciadores::GerenciadorEstados::getInstancia();
        pJogador1 = new Entidades::Personagens::Jogador(sf::Vector2f(400.0f, 700.0f), sf::Vector2f(60.0f, 110.0f), 1, sf::Vector2f(0.0f, 0.0f));
        adicionarJogador(static_cast<Entidades::Entidade*>(pJogador1));

        pJogador2 = new Entidades::Personagens::Jogador(sf::Vector2f(300.0f, 700.0f), sf::Vector2f(40.0f, 100.0f), 2, sf::Vector2f(0.0f, 0.0f));
        adicionarJogador(static_cast<Entidades::Entidade*>(pJogador2));
        pGEstados->setListaJogadores(&listaJogadores);
        if (!multiplayer) {
            pJogador2->getCorpo()->setPosition(sf::Vector2f(-200,0));
        }
        pObservadorFase = Observadores::FaseObservador::getInstancia();
        pObservadorFase->setFase(this);
    }

    Fase::~Fase()
    {

        if (pJogador1) {
            delete(pJogador1);
            pJogador1 = nullptr;
        }
        
    }

    void Fase::adicionarObstaculos(Entidades::Entidade* obstaculo)
    {
        if(obstaculo) {
            listaObstaculos.adicionarEntidade(obstaculo);
        }
    }

    void Fase::adicionarInimigos(Entidades::Entidade* inimigo)
    {
        if(inimigo) {
            listaInimigos.adicionarEntidade(inimigo);
        }
    }

    void Fase::adicionarJogador(Entidades::Entidade* jogador)
    {
        if(jogador) {
            listaJogadores.adicionarEntidade(jogador);
        }
    }

    void Fase::adicionarProjetil(Entidades::Entidade* projetil)
    {
        if(projetil) {
            listaProjeteis.adicionarEntidade(projetil);
        }
    }

    void Fase::mudarFase() {
        if (pJogador1->getPosicao().x > 3091) {
            pObservadorFase->notificarMudarFase();
        }
    }

    void Fase::executar() {
        //printf("%2.f, %2.f\n", pJogador1->getCorpo()->getPosition().x, pJogador1->getCorpo()->getPosition().y);
        if (pObservadorFase) {
            //printf("NÃO É NULO\n");
        }
        else {
            //printf("EH NULO\n");
        }
        desenhar();
        if (pJogador1->getVivo())
            pGG->centralizarCamera(pJogador1->getCorpo()->getPosition());
        else {
            pGG->centralizarCamera(pJogador2->getCorpo()->getPosition());
        }
        listaObstaculos.executar();
        listaInimigos.executar();
        listaJogadores.executar();
        listaProjeteis.executar();

        pGC.gerenciar();
        
        if (multiplayer) {
            if (!pJogador1->getVivo() && !pJogador2->getVivo())
                pObservadorFase->notificarGameOver();
        }
        else {
            if (!pJogador1->getVivo())
                pObservadorFase->notificarGameOver();
        }
        mudarFase();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
            salvar("saves/save.dat");
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
            carregar("saves/save.dat");
        }
    }


    void Fase::carregarMapa(std::string mapJson, std::string caminhoImagem) {
        std::ifstream arquivo(mapJson);
        
        if(!arquivo.is_open()){
            std::cerr << "Erro ao abrir o mapa " << mapJson <<std::endl;
            return;
        }

        if (!tilesetTextura.loadFromFile(caminhoImagem)) {
            std::cerr <<"Erro ao abrir textura " << std::endl;
        }

        arquivo >> mapa;
        
        int sizeTiled = mapa["tilewidth"];
        int width = mapa["width"];
        int height = mapa["height"];

        int indice = 0;

        //loop de entidades com tamanho fixo (sizeTiled x sizeTiled)
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
            int tileId = mapa["layers"][0]["data"][indice++];
                if(tileId != 0){
                    sf::Vector2f posicao(x * sizeTiled, y * sizeTiled);
                    sf::Vector2f tamanho(sizeTiled, sizeTiled);
                    criarEntidade(posicao,tamanho, tileId);
                }
            }
        }
        
    }

    void Fase::criarInimigos(std::string mapJson, std::vector<sf::Vector2f> posicoes_inimigos, Entidades::Personagens::Jogador* jogador) {
        std::ifstream arquivo(mapJson);
        
        if(!arquivo.is_open()){
            std::cerr << "Erro ao abrir o mapa " << mapJson <<std::endl;
            return;
        }

        arquivo >> mapa;
        
        int sizeTiled = mapa["tilewidth"];
        int width = mapa["width"];
        int height = mapa["height"];

        int indice = 0;
        int firstgid = mapa["tilesets"][0]["firstgid"];
        auto tileset = mapa["tilesets"][0]; 
        for (const auto& objeto : mapa["layers"]) {
            if (objeto["type"] == "objectgroup") {
                for (const auto& objetoDetalhes : objeto["objects"]) {
                    std::string nomeObjeto = objetoDetalhes["name"];
                    if (nomeObjeto == "inimigo") {
                        sf::Vector2f posicao(
                            static_cast<float>(objetoDetalhes["x"]),
                            static_cast<float>(objetoDetalhes["y"])
                        );
                        posicoes_inimigos.push_back(posicao);
                    }
                }
            }
        }

        int tam = posicoes_inimigos.size();
        int pos = rand() % tam;
        sf::Vector2f tamanho(sizeTiled, sizeTiled);
        /*for (int i = 0; i <  quantidade de inimigos a colocar; i++) {
            Entidades::Personagens::Esqueleto* inimigo = new Entidades::Personagens::Esqueleto(posicoes_inimigos[pos],tamanho,sf::Vector2f(0,0),jogador);
            adicionarInimigos(inimigo);
            posicoes_inimigos.erase(posicoes_inimigos.begin() + pos);
            tam--;
            pos = rand() % tam;
        } 
        */ 
        //Entidades::Personagens::Esqueleto* inimigo = new Entidades::Personagens::Esqueleto(posicoes_inimigos[pos],tamanho,sf::Vector2f(0,0),jogador);
        //adicionarInimigos(inimigo);
    } 


    void Fase::salvar(const std::string& caminhoArquivo)
    {
        printf("SALVOU");
        fflush(stdout);
        std::ofstream arquivo(caminhoArquivo, std::ios::binary);
        if(!arquivo.is_open()) {
            std::cout << "Erro ao salvar o jogo";
            return;
        }

        //Salvar jogadores
        sf::Vector2f posJogador1 = pJogador1->getCorpo()->getPosition();
        int vidaJogador1 = pJogador1->getPontosDeVida();

        arquivo.write(reinterpret_cast<char*>(&posJogador1), sizeof(sf::Vector2f));
        arquivo.write(reinterpret_cast<char*>(&vidaJogador1), sizeof(int));

        sf::Vector2f posJogador2 = pJogador2->getCorpo()->getPosition();
        int vidaJogador2 = pJogador2->getPontosDeVida();

        arquivo.write(reinterpret_cast<char*>(&posJogador2), sizeof(sf::Vector2f));
        arquivo.write(reinterpret_cast<char*>(&vidaJogador2), sizeof(int));

        //Salvar inimigos
        int numInimigos = listaInimigos.getTamanho();
        arquivo.write(reinterpret_cast<char*>(&numInimigos), sizeof(int));
        Entidades::Entidade* inimigoEntidade;
        
        for (int i = 0; i < numInimigos; i++) {
            inimigoEntidade = listaInimigos.operator[](i);
            sf::Vector2f pos = inimigoEntidade->getCorpo()->getPosition();
            Entidades::ID id = inimigoEntidade->getId();

            arquivo.write(reinterpret_cast<char*>(&pos), sizeof(sf::Vector2f));
            arquivo.write(reinterpret_cast<char*>(&id), sizeof(Entidades::ID));
        }

        //Salvar obstaculos
        int numObstaculos = listaObstaculos.getTamanho();
        arquivo.write(reinterpret_cast<char*>(&numObstaculos), sizeof(int));

        Entidades::Entidade* obstaculoEntidade;
        for (int i = 0; i < numObstaculos; i++) {
            obstaculoEntidade = listaObstaculos.operator[](i);
            sf::Vector2f pos = obstaculoEntidade->getCorpo()->getPosition();
            Entidades::ID id = obstaculoEntidade->getId();

            arquivo.write(reinterpret_cast<char*>(&pos), sizeof(sf::Vector2f));
            arquivo.write(reinterpret_cast<char*>(&id), sizeof(Entidades::ID));
        }

        //Salvar projeteis
        int numProjeteis = listaProjeteis.getTamanho();
        arquivo.write(reinterpret_cast<char*>(&numProjeteis), sizeof(int));

        Entidades::Entidade* projetilEntidade;
        for(int i = 0; i < numProjeteis; i++) {
            projetilEntidade = listaProjeteis.operator[](i);

            sf::Vector2f pos = projetilEntidade->getCorpo()->getPosition();
            sf::Vector2f vel = projetilEntidade->getVelocidade();

            arquivo.write(reinterpret_cast<char*>(&pos), sizeof(sf::Vector2f));
            arquivo.write(reinterpret_cast<char*>(&vel), sizeof(sf::Vector2f));
        }
        
        //salvar id da fase
        arquivo.write(reinterpret_cast<char*>(&id), sizeof(int));

        arquivo.close();
    }

    void Fase::carregar(const std::string& caminhoArquivo)
    {
        std::ifstream arquivo(caminhoArquivo, std::ios::binary);
        if (!arquivo.is_open()) {
            std::cerr << "Erro ao carregar o jogo.\n";
            return;
        }

        // Carregar jogadores
        sf::Vector2f posJogador1, posJogador2;
        int vidaJogador1, vidaJogador2;

        arquivo.read(reinterpret_cast<char*>(&posJogador1), sizeof(sf::Vector2f));
        arquivo.read(reinterpret_cast<char*>(&vidaJogador1), sizeof(int));

        arquivo.read(reinterpret_cast<char*>(&posJogador2), sizeof(sf::Vector2f));

        arquivo.read(reinterpret_cast<char*>(&vidaJogador2), sizeof(int));

        pJogador1->getCorpo()->setPosition(posJogador1);
        pJogador2->getCorpo()->setPosition(posJogador2);

        pJogador1->setPontosDeVida(vidaJogador1);
        pJogador2->setPontosDeVida(vidaJogador2);

        // Carregar inimigos
        int numInimigos;
        arquivo.read(reinterpret_cast<char*>(&numInimigos), sizeof(int));
        listaInimigos.limpar();

        for (int i = 0; i < numInimigos; i++) {
            sf::Vector2f pos;
            Entidades::ID id;

            arquivo.read(reinterpret_cast<char*>(&pos), sizeof(sf::Vector2f));
            arquivo.read(reinterpret_cast<char*>(&id), sizeof(Entidades::ID));

            if(id == Entidades::ID::esqueleto) {
                Entidades::Personagens::Esqueleto* esqueleto = new Entidades::Personagens::Esqueleto(pos, sf::Vector2f(80.0f, 80.0f), sf::Vector2f(0, 0), pJogador1);
                adicionarInimigos(static_cast<Entidades::Entidade*>(esqueleto));
                
            }else if(id == Entidades::ID::arqueiro){
                Entidades::Personagens::Arqueiro* arqueiro = new Entidades::Personagens::Arqueiro(pos, sf::Vector2f(80.0f, 80.0f), sf::Vector2f(0, 0), pJogador1);
                arqueiro->setListaProjeteis(&listaProjeteis);
                adicionarInimigos(static_cast<Entidades::Entidade*>(arqueiro));

            }else if(id == Entidades::ID::samurai) {
                Entidades::Personagens::Samurai* Samurai = new Entidades::Personagens::Samurai(pos, sf::Vector2f(80.0f, 80.0f), sf::Vector2f(0, 0), pJogador1);
                Samurai->setListaProjeteis(&listaProjeteis);
                adicionarInimigos(static_cast<Entidades::Entidade*>(Samurai));
            }
        }

        // Carregar obstáculos
        int numObstaculos;
        arquivo.read(reinterpret_cast<char*>(&numObstaculos), sizeof(int));

        listaObstaculos.limpar();
        for (int i = 0; i < numObstaculos; i++) {
            sf::Vector2f pos;
            Entidades::ID id;

            arquivo.read(reinterpret_cast<char*>(&pos), sizeof(sf::Vector2f));
            arquivo.read(reinterpret_cast<char*>(&id), sizeof(Entidades::ID));

            if(id == Entidades::ID::gosma) {
                Entidades::Obstaculos::Gosma* gosma = new Entidades::Obstaculos::Gosma(pos, sf::Vector2f(100.0f, 20.0f));
                adicionarObstaculos(static_cast<Entidades::Entidade*>(gosma));
            }else if(id == Entidades::ID::espinho) {
                Entidades::Obstaculos::Espinho* espinho = new Entidades::Obstaculos::Espinho(pos, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(0.0f, 0.0f));
                adicionarObstaculos(static_cast<Entidades::Entidade*>(espinho));
            }
        }

        //Carregar projeteis

        int numProjeteis;
        arquivo.read(reinterpret_cast<char*>(&numProjeteis), sizeof(int));

        listaProjeteis.limpar();
        
        for(int i = 0; i < numProjeteis; i++) {
            sf::Vector2f pos;
            sf::Vector2f vel;

            arquivo.read(reinterpret_cast<char*>(&pos), sizeof(sf::Vector2f));
            arquivo.read(reinterpret_cast<char*>(&vel), sizeof(sf::Vector2f));

            Entidades::Projetil* projetil = new Entidades::Projetil(pos ,sf::Vector2f(64.0f, 64.0f), sf::Vector2f(5.0f, 5.0f));
            projetil->setVelocidade(vel);

            adicionarProjetil(static_cast<Entidades::Entidade*>(projetil));
        }

        int id;
        arquivo.read(reinterpret_cast<char*>(&id), sizeof(int));

        if(id == 1) {
            carregarMapa("include/Tilemap/Pantano.json","include/Tilemap/SwampTiles.png");
        }else {
            carregarMapa("include/Tilemap/Nether.json","include/Tilemap/NetherTiles.png");
        }
            

        arquivo.close();
    }

    void Fase::instanciaAleatorias(std::vector<sf::Vector2f> posicoes, Entidades::ID id) {
        int random = static_cast<int>(std::min<size_t>(3 + rand() % (posicoes.size() - 2), posicoes.size()));

        std::vector<int> indicesUsados;

        for (int i = 0; i < random; i++) {
            if (indicesUsados.size() == posicoes.size()) {
                break; // Evita loop infinito se todos os índices já foram usados
            }

            int index;
            do {
                index = rand() % posicoes.size(); // Sorteia um índice aleatório do vetor
            } while (std::find(indicesUsados.begin(), indicesUsados.end(), index) != indicesUsados.end());

            indicesUsados.push_back(index); // Armazena o índice já utilizado

            std::cout << posicoes[index].y << std::endl;

            if (id == Entidades::ID::gosma) {
                auto* gosma = new Entidades::Obstaculos::Gosma(posicoes[index], sf::Vector2f(100.0f, 20.0f));
                adicionarObstaculos(static_cast<Entidades::Entidade*>(gosma));
            }
            else if (id == Entidades::ID::arqueiro) {
                Entidades::Personagens::Arqueiro* arqueiro = new Entidades::Personagens::Arqueiro(posicoes[index], sf::Vector2f(80.0f, 80.0f), sf::Vector2f(2.0f, 2.0f), pJogador1);
                adicionarInimigos(static_cast<Entidades::Entidade*>(arqueiro));
            }
            else if (id == Entidades::ID::esqueleto) {
                Entidades::Personagens::Esqueleto* esqueleto = new Entidades::Personagens::Esqueleto(posicoes[index], sf::Vector2f(80.0f, 80.0f), sf::Vector2f(2.0f, 2.0f), pJogador1);
                adicionarInimigos(static_cast<Entidades::Entidade*>(esqueleto));
            }
            else if (id == Entidades::ID::samurai) {
                Entidades::Personagens::Esqueleto* samurai = new Entidades::Personagens::Esqueleto(posicoes[index], sf::Vector2f(80.0f, 80.0f), sf::Vector2f(2.0f, 2.0f), pJogador1);
                adicionarInimigos(static_cast<Entidades::Entidade*>(samurai));
            }
        }
    }
}