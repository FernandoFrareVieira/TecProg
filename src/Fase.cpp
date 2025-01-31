#include "Fases/Fase.hpp"

namespace Fases
{
    Observadores::FaseObservador* Fases::Fase::pObservadorFase = nullptr;

    Fase::Fase(int id):
        Estado(id),
        listaObstaculos(),
        listaInimigos(),
        listaJogadores(),
        corpo(),
        pGC()
    {
        pGEstados = Gerenciadores::GerenciadorEstados::getInstancia();
        pJogador1 = new Entidades::Personagens::Jogador(sf::Vector2f(200.0f, 920.0f), sf::Vector2f(50.0f, 50.0f), 1, sf::Vector2f(0.0f, 0.0f));
        adicionarJogador(static_cast<Entidades::Entidade*>(pJogador1));

        pJogador2 = new Entidades::Personagens::Jogador(sf::Vector2f(100.0f, 920.0f), sf::Vector2f(50.0f, 50.0f), 2, sf::Vector2f(0.0f, 0.0f));
        adicionarJogador(static_cast<Entidades::Entidade*>(pJogador2));
        pGEstados->setListaJogadores(&listaJogadores);
        pGC.setJogadores(&listaJogadores);
        
        pGC.setObstaculos(&listaObstaculos);
        pGC.setInimigos(&listaInimigos);
        pGC.setJogadores(&listaJogadores);

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

    void Fase::mudarFase() {
        if (pJogador1->getPosicao().x > 1920) {
            pObservadorFase->notificarMudarFase();
        }
    }

    void Fase::executar() {
        desenhar();
        pGG->centralizarCamera(pJogador1->getCorpo()->getPosition());
        listaObstaculos.executar();
        listaInimigos.executar();
        listaJogadores.executar();

        pGC.gerenciar();
        if (!pJogador1->getVivo())
            pObservadorFase->notificarGameOver();
        mudarFase();
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
        Entidades::Personagens::Esqueleto* inimigo = new Entidades::Personagens::Esqueleto(posicoes_inimigos[pos],tamanho,sf::Vector2f(0,0),jogador);
        adicionarInimigos(inimigo);
    } 

}