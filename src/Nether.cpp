#include "Fases/Nether.hpp"

namespace Fases {

    Nether::Nether(int id, bool dois_jogadores):
        Fase(id,dois_jogadores),
        maxArqueiros(5),
        maxSamurais(4),
        maxEspinhos(5),
        posicoesArqueiros(),
        posicoesSamurais(),
        posicoesEspinhos()
    {
        posicoesArqueiros.clear();
        posicoesSamurais.clear();
        posicoesEspinhos.clear();

        carregarMapa("include/Tilemap/Nether.json","include/Tilemap/NetherTiles.png");


        //Entidades::Personagens::Esqueleto* esqueleto = new Entidades::Personagens::Esqueleto(sf::Vector2f(1006.0f, 860.0f), sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2.0f, 2.0f), pJogador1);
        //adicionarInimigos(static_cast<Entidades::Entidade*>(esqueleto));

        //Entidades::Personagens::Arqueiro* arqueiro = new Entidades::Personagens::Arqueiro(sf::Vector2f(1304.0f, 860.0f), sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2.0f, 2.0f), pJogador1);
        //adicionarInimigos(static_cast<Entidades::Entidade*>(arqueiro));
        //arqueiro->setListaProjeteis(&listaProjeteis);

        //Entidades::Personagens::Samurai* samurai = new Entidades::Personagens::Samurai(sf::Vector2f(1000.0f, 3000.f), sf::Vector2f(90.0f, 128.0f), sf::Vector2f(2.0f, 2.0f), pJogador1);
        //adicionarInimigos(static_cast<Entidades::Entidade*>(samurai)); //os inimigos estao dando seg fault
        pGC.setJogadores(&listaJogadores);
        pGC.setObstaculos(&listaObstaculos);
        pGC.setInimigos(&listaInimigos);
        pGC.setProjeteis(&listaProjeteis);
<<<<<<< HEAD


        Entidades::Personagens::Samurai* samurai = new Entidades::Personagens::Samurai(sf::Vector2f(1000.0f, 250.0f), sf::Vector2f(50.0f, 128.0f), sf::Vector2f(0.0f, 0.0f), pJogador1);
        adicionarInimigos(static_cast<Entidades::Entidade*>(samurai));
        samurai->setListaProjeteis(&listaProjeteis);
=======
>>>>>>> 09814f8e83c643f6618642843ef6936a22fe9727
    }

    Nether::~Nether() {

    }


    void Nether::desenhar() {
        if(!background.loadFromFile("assets/cenarios/Nether.png")){ //Está dando seg fault"
            std::cerr << "Erro ao carregar a textura do mapa" << std::endl;
            return;
        }
        sf::Sprite backgroundSprite(background);
        backgroundSprite.setScale(6.5,3);
        backgroundSprite.setOrigin(sf::Vector2f(80,-20));
        pGG->desenharOutros(backgroundSprite);
        //pGG->centralizarCamera(jogador->getCorpo()->getPosition());
    }

    void Nether::criarEntidade(sf::Vector2f posicao, sf::Vector2f tamanho, int tipo) {
        switch (tipo){  
            case 1 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_01.png");
            adicionarObstaculos(plataforma);
            }
            case 2 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_02.png");
            adicionarObstaculos(plataforma);
            }
            case 3 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_03.png");
            adicionarObstaculos(plataforma);
            }
            case 4 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_04.png");
            adicionarObstaculos(plataforma);
            }
            case 9 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_09.png");
            adicionarObstaculos(plataforma);
            }
            case 10 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_10.png");
            adicionarObstaculos(plataforma);
            }
            case 11 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_11.png");
            adicionarObstaculos(plataforma);
            }
            case 13 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_13.png");
            adicionarObstaculos(plataforma);
            }
            case 19 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_19.png");
            adicionarObstaculos(plataforma);
            }
            case 20 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_20.png");
            adicionarObstaculos(plataforma);
            }
            case 21 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_21.png");
            adicionarObstaculos(plataforma);
            }
            case 22 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_22.png");
            adicionarObstaculos(plataforma);
            }
        }
    }
    void Nether::setPosicoes()
    {
            
    }
}
