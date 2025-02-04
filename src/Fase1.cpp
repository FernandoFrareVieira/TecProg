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
        carregarMapa("include/Tilemap/Pantano.json","include/Tilemap/SwampTiles.png");

        Entidades::Personagens::Esqueleto* esqueleto1 = new Entidades::Personagens::Esqueleto(sf::Vector2f(1612.0f, 270.0f), sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2.0f, 2.0f), pJogador1);
        adicionarInimigos(static_cast<Entidades::Entidade*>(esqueleto1));

        Entidades::Personagens::Esqueleto* esqueleto2 = new Entidades::Personagens::Esqueleto(sf::Vector2f(1714.0f, 870.0f), sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2.0f, 2.0f), pJogador1);
        adicionarInimigos(static_cast<Entidades::Entidade*>(esqueleto2));
            
        Entidades::Personagens::Arqueiro* arqueiro = new Entidades::Personagens::Arqueiro(sf::Vector2f(1136.0f, 400.0f), sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2.0f, 2.0f), pJogador1);
        adicionarInimigos(static_cast<Entidades::Entidade*>(arqueiro));
        arqueiro->setListaProjeteis(&listaProjeteis);

        //criarInimigos("include/Tilemap/Tiles.json",posicoes,pJogador1);
        pGC.setInimigos(&listaInimigos);

        Entidades::Obstaculos::Gosma* gosma = new Entidades::Obstaculos::Gosma(sf::Vector2f(300.0f, 1015.0f), sf::Vector2f(100.0f, 20.0f));
        adicionarObstaculos(static_cast<Entidades::Entidade*>(gosma));

        //Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(sf::Vector2f(500.0f, 400.0f), sf::Vector2f(400.0f, 100.0f), sf::Vector2f(0.0f, 0.0f));
        //adicionarObstaculos(static_cast<Entidades::Entidade*>(plataforma));
        //listaObstaculos = tilemap->criarMapa(listaObstaculos);
        pGC.setObstaculos(&listaObstaculos);

        Entidades::Projetil* projetil = new Entidades::Projetil(sf::Vector2f(400.0f, 500.0f), sf::Vector2f(64.0f, 64.0f), sf::Vector2f(5.0f, 5.0f));
        adicionarProjetil(static_cast<Entidades::Entidade*>(projetil));
        projetil->setListaProjeteis(&listaProjeteis);

        pGC.setProjeteis(&listaProjeteis);

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
            case 11: {
                Entidades::Obstaculos::Gosma* gosma = new Entidades::Obstaculos::Gosma(posicao, tamanho, sf::Vector2f(0,0));
                gosma->setTextura("assets/plataformas/grama11.png");
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
            case 15: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
                plataforma->setTextura("assets/plataformas/grama15.png");
                adicionarObstaculos(plataforma);
            }
            case 22: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
                plataforma->setTextura("assets/plataformas/grama22.png");
                adicionarObstaculos(plataforma);
            }
            case 23: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
                plataforma->setTextura("assets/plataformas/grama23.png");
                adicionarObstaculos(plataforma);
            }
            case 21: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
                plataforma->setTextura("assets/plataformas/grama21.png");
                adicionarObstaculos(plataforma);
            }
            case 33: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
                plataforma->setTextura("assets/plataformas/grama33.png");
                adicionarObstaculos(plataforma);
            }
            case 34: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
                plataforma->setTextura("assets/plataformas/grama34.png");
                adicionarObstaculos(plataforma);
            }
            case 35: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
                plataforma->setTextura("assets/plataformas/grama35.png");
                adicionarObstaculos(plataforma);
            }
            case 45: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
                plataforma->setTextura("assets/plataformas/grama45.png");
                adicionarObstaculos(plataforma);
            }
            // case 47: {
            //     Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            //     plataforma->setTextura("assets/plataformas/grama47.png");
            //     adicionarObstaculos(plataforma);
            // }
            // case 48: {
            //     Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
            //     plataforma->setTextura("assets/plataformas/grama48.png");
            //     adicionarObstaculos(plataforma);
            // }
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