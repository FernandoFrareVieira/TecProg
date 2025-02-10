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
        posicoesFogos.clear();

        carregarMapa("include/Tilemap/Nether.json","include/Tilemap/NetherTiles.png");


        //Entidades::Personagens::Esqueleto* esqueleto = new Entidades::Personagens::Esqueleto(sf::Vector2f(1006.0f, 860.0f), sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2.0f, 2.0f), pJogador1);
        //adicionarInimigo(static_cast<Entidades::Entidade*>(esqueleto));

        //Entidades::Personagens::Arqueiro* arqueiro = new Entidades::Personagens::Arqueiro(sf::Vector2f(1304.0f, 860.0f), sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2.0f, 2.0f), pJogador1);
        //adicionarInimigo(static_cast<Entidades::Entidade*>(arqueiro));
        //arqueiro->setListaProjeteis(&listaProjeteis);

        //Entidades::Personagens::Samurai* samurai = new Entidades::Personagens::Samurai(sf::Vector2f(1000.0f, 3000.f), sf::Vector2f(90.0f, 128.0f), sf::Vector2f(2.0f, 2.0f), pJogador1);
        //adicionarInimigo(static_cast<Entidades::Entidade*>(samurai)); //os inimigos estao dando seg fault
        setPosicoesAleatorias();
        
        instanciaAleatorias(posicoesEspinhos,Entidades::ID::espinho);
        instanciaAleatorias(posicoesArqueiros,Entidades::ID::arqueiro);
        instanciaAleatorias(posicoesSamurais,Entidades::ID::samurai);
        instanciaAleatorias(posicoesFogos,Entidades::ID::fogo);
        

        pGC.setJogadores(&listaJogadores);
        pGC.setObstaculos(&listaObstaculos);
        pGC.setInimigos(&listaInimigos);
        pGC.setProjeteis(&listaProjeteis);
        //Entidades::Personagens::Samurai* samurai = new Entidades::Personagens::Samurai(sf::Vector2f(1000.0f, 250.0f), sf::Vector2f(50.0f, 128.0f), sf::Vector2f(0.0f, 0.0f), pJogador1);
        //adicionarInimigo(static_cast<Entidades::Entidade*>(samurai));
        //samurai->setListaProjeteis(&listaProjeteis);
    }

    Nether::~Nether() {

    }


    void Nether::desenhar() {
        if(!imagemDeFundo.loadFromFile("assets/cenarios/Nether.png")){ //Está dando seg fault"
            std::cerr << "Erro ao carregar a textura do mapa" << std::endl;
            return;
        }
        sf::Sprite backgroundSprite(imagemDeFundo);
        backgroundSprite.setScale(6.5,3);
        backgroundSprite.setOrigin(sf::Vector2f(80,-20));
        pGG->desenharOutros(backgroundSprite);
    }

    void Nether::criarObstaculo(sf::Vector2f posicao, sf::Vector2f tamanho, int tipo) {
        switch (tipo){  
            case 1 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_01.png");
            adicionarObstaculo(plataforma);
            }
            case 2 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_02.png");
            adicionarObstaculo(plataforma);
            }
            case 3 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_03.png");
            adicionarObstaculo(plataforma);
            }
            case 4 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_04.png");
            adicionarObstaculo(plataforma);
            }
            case 9 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_09.png");
            adicionarObstaculo(plataforma);
            }
            case 10 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_10.png");
            adicionarObstaculo(plataforma);
            }
            case 11 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_11.png");
            adicionarObstaculo(plataforma);
            }
            case 13 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_13.png");
            adicionarObstaculo(plataforma);
            }
            case 19 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_19.png");
            adicionarObstaculo(plataforma);
            }
            case 20 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_20.png");
            adicionarObstaculo(plataforma);
            }
            case 21 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_21.png");
            adicionarObstaculo(plataforma);
            }
            case 22 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas2/Tile_22.png");
            adicionarObstaculo(plataforma);
            }
        }
    }
    void Nether::setPosicoesAleatorias()
    {
            posicoesEspinhos.push_back(sf::Vector2f(490,1040));
            posicoesEspinhos.push_back(sf::Vector2f(1115,465));
            posicoesEspinhos.push_back(sf::Vector2f(1775,336));
            posicoesEspinhos.push_back(sf::Vector2f(1688,820));
            posicoesEspinhos.push_back(sf::Vector2f(2537,1040));
            //posicoesEspinhos.push_back(sf::Vector2f(1115,459));
            //posicoesEspinhos.push_back(sf::Vector2f(1115,467));

            posicoesArqueiros.push_back(sf::Vector2f(983,300));
            posicoesArqueiros.push_back(sf::Vector2f(2480,900));
            posicoesArqueiros.push_back(sf::Vector2f(1600,570));
            posicoesArqueiros.push_back(sf::Vector2f(1600,220));

            posicoesSamurais.push_back(sf::Vector2f(2959,900));
            posicoesSamurais.push_back(sf::Vector2f(1735,680));
            posicoesSamurais.push_back(sf::Vector2f(1805,180));
            posicoesSamurais.push_back(sf::Vector2f(2753,700));
            posicoesSamurais.push_back(sf::Vector2f(71,800));

            posicoesFogos.push_back(sf::Vector2f(172,1007));
            posicoesFogos.push_back(sf::Vector2f(2368,1007));
            posicoesFogos.push_back(sf::Vector2f(2778,1007));
            posicoesFogos.push_back(sf::Vector2f(1678,303));


    }
}
