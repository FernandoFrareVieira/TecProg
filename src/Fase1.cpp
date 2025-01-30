#include "Fases/Fase1.hpp"

namespace Fases
{
    Fase1::Fase1(int id):
        Fase(id),
        maxEsqueletos(3),
        maxPlataformas(3)
    {
        //Iniciar corpo

        // TODO - Arrumar a lógica da criaçao dos objetos
        carregarMapa("include/Tilemap/Tiles.json","include/Tilemap/SwampTiles.png");

        for(int i = 0; i < 1; i++) {
            Entidades::Personagens::Esqueleto* esqueleto = new Entidades::Personagens::Esqueleto(sf::Vector2f(200.0f + (i*100.0f), 920.0f), sf::Vector2f(50.0f, 50.0f), sf::Vector2f(2.0f, 2.0f), pJogador1);
            adicionarInimigos(static_cast<Entidades::Entidade*>(esqueleto));
        }
        criarInimigos("include/Tilemap/Tiles.json",posicoes,pJogador1);
        pGC.setInimigos(&listaInimigos);

        //Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(sf::Vector2f(500.0f, 400.0f), sf::Vector2f(400.0f, 100.0f), sf::Vector2f(0.0f, 0.0f));
        //adicionarObstaculos(static_cast<Entidades::Entidade*>(plataforma));
        //listaObstaculos = tilemap->criarMapa(listaObstaculos);
        pGC.setObstaculos(&listaObstaculos);
    }

    Fase1::~Fase1()
    {
        
    }


    void Fase1::desenhar()
    {
        if(!background.loadFromFile("assets/cenarios/Background.png")){ //Está dando seg fault"
            std::cerr << "Erro ao carregar a textura do mapa" << std::endl;
            return;
        }
        sf::Sprite backgroundSprite(background);
        backgroundSprite.setScale(4,3.2);
        backgroundSprite.setOrigin(sf::Vector2f(50,-30));
        pGG->desenharOutros(backgroundSprite);
        pGG->centralizarCamera(pJogador1->getCorpo()->getPosition());
    }   

    void Fase1::criarEntidade(sf::Vector2f posicao, sf::Vector2f tamanho, int tipo)
    {
        
        switch (tipo){  
            case 1 : { //plataforma
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas/grama1.png");
            adicionarObstaculos(plataforma);
            }
            case 2: {
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas/grama2.png");
            adicionarObstaculos(plataforma);
            }
            case 3: {
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas/grama3.png");
            adicionarObstaculos(plataforma);
            }
            case 5: {
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas/grama5.png");
            adicionarObstaculos(plataforma);
            }
            case 10: {
            Entidades::Obstaculos::Gosma* gosma = new Entidades::Obstaculos::Gosma(posicao, tamanho, sf::Vector2f(0,0));
            gosma->setTextura("assets/plataformas/gosma.png");
            adicionarObstaculos(gosma);
            }
            case 12: {
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas/grama12.png");
            adicionarObstaculos(plataforma);
            }
            case 13: {
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            plataforma->setTextura("assets/plataformas/grama13.png");
            adicionarObstaculos(plataforma);
            }
        }
        /*
            case 2 : //plataforma sprite 1
                return new Plataforma(posicao, tamanho, tipo);
                break;
            case 3 : //plataforma sprite 2
                return new Plataforma(posicao, tamanho, tipo);
                break;
            ...
        }
        - ASSIM POR DIANTE PARA CADA TIPO DE ENTIDADE QUE VC NECESSITA CRIAR
        */
    }

}