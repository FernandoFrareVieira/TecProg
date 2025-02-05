#include "Fases/Fase.hpp"

namespace Fases
{
    Observadores::FaseObservador* Fases::Fase::pObservadorFase = nullptr;

    Fase::Fase(int id):
        Estado(id),
        listaObstaculos(),
        listaInimigos(),
        listaJogadores(),
        listaProjeteis(),
        corpo(),
        pGC()
    {
        pGEstados = Gerenciadores::GerenciadorEstados::getInstancia();
        pJogador1 = new Entidades::Personagens::Jogador(sf::Vector2f(400.0f, 700.0f), sf::Vector2f(60.0f, 110.0f), 1, sf::Vector2f(0.0f, 0.0f));
        adicionarJogador(static_cast<Entidades::Entidade*>(pJogador1));

        pJogador2 = new Entidades::Personagens::Jogador(sf::Vector2f(300.0f, 700.0f), sf::Vector2f(40.0f, 100.0f), 2, sf::Vector2f(0.0f, 0.0f));
        adicionarJogador(static_cast<Entidades::Entidade*>(pJogador2));
        pGEstados->setListaJogadores(&listaJogadores);
        
        pGC.setJogadores(&listaJogadores);
        
        pGC.setObstaculos(&listaObstaculos);
        pGC.setInimigos(&listaInimigos);
        pGC.setProjeteis(&listaProjeteis);

        if (pObservadorFase == nullptr) {
            pObservadorFase = new Observadores::FaseObservador();
        }
    }

    Fase::~Fase()
    {
        if(pObservadorFase != nullptr){
            delete(pObservadorFase);
            pObservadorFase = nullptr;
        }

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
        desenhar();
        pGG->centralizarCamera(pJogador1->getCorpo()->getPosition());
        listaObstaculos.executar();
        listaInimigos.executar();
        listaJogadores.executar();
        listaProjeteis.executar();

        pGC.gerenciar();
        if (!pJogador1->getVivo())
            pObservadorFase->notificarGameOver();
        mudarFase();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
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
        std::ofstream arquivo(caminhoArquivo, std::ios::binary);

        if(!arquivo.is_open()) {
            std::cout << "Erro ao salvar o jogo";
            return;
        }

        //Salvar jogadores

        sf::Vector2f posJogador1 = pJogador1->getCorpo()->getPosition();
        arquivo.write(reinterpret_cast<char*>(&posJogador1), sizeof(sf::Vector2f));

        sf::Vector2f posJogador2 = pJogador2->getCorpo()->getPosition();
        arquivo.write(reinterpret_cast<char*>(&posJogador2), sizeof(sf::Vector2f));

        //Salvar inimigos
        int numInimigos = listaInimigos.getTamanho();
        arquivo.write(reinterpret_cast<char*>(&numInimigos), sizeof(int));

        Entidades::Entidade* inimigoEntidade;

        for (int i = 0; i < numInimigos; i++) {
            inimigoEntidade = listaInimigos.operator[](i);

            sf::Vector2f pos = inimigoEntidade->getCorpo()->getPosition();
            arquivo.write(reinterpret_cast<char*>(&pos), sizeof(sf::Vector2f));
        }

        //Salvar obstaculos
        int numObstaculos = listaObstaculos.getTamanho();
        arquivo.write(reinterpret_cast<char*>(&numObstaculos), sizeof(int));

        Entidades::Entidade* obstaculoEntidade;

        for (int i = 0; i < numObstaculos; i++) {
            obstaculoEntidade = listaObstaculos.operator[](i);

            sf::Vector2f pos = obstaculoEntidade->getCorpo()->getPosition();
            arquivo.write(reinterpret_cast<char*>(&pos), sizeof(sf::Vector2f));
        }

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
        arquivo.read(reinterpret_cast<char*>(&posJogador1), sizeof(sf::Vector2f));
        arquivo.read(reinterpret_cast<char*>(&posJogador2), sizeof(sf::Vector2f));

        pJogador1->getCorpo()->setPosition(posJogador1);
        pJogador2->getCorpo()->setPosition(posJogador2);

        // Carregar inimigos
        int numInimigos;
        arquivo.read(reinterpret_cast<char*>(&numInimigos), sizeof(int));

        listaInimigos.limpar();
        for (int i = 0; i < numInimigos; i++) {
            sf::Vector2f pos;
            arquivo.read(reinterpret_cast<char*>(&pos), sizeof(sf::Vector2f));
            Entidades::Personagens::Esqueleto* esqueleto = new Entidades::Personagens::Esqueleto(pos, sf::Vector2f(50, 50), sf::Vector2f(2.0f, 2.0f), pJogador1);
            adicionarInimigos(esqueleto);
        }

        // Carregar obstáculos
        int numObstaculos;
        arquivo.read(reinterpret_cast<char*>(&numObstaculos), sizeof(int));

        listaObstaculos.limpar();
        for (int i = 0; i < numObstaculos; i++) {
            sf::Vector2f pos;
            arquivo.read(reinterpret_cast<char*>(&pos), sizeof(sf::Vector2f));
            Entidades::Obstaculos::Plataforma* obstaculo = new Entidades::Obstaculos::Plataforma(pos, sf::Vector2f(50, 50));
            adicionarObstaculos(obstaculo);
        }

        arquivo.close();
    }

}