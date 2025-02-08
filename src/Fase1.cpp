#include "Fases/Fase1.hpp"
#include <iostream>

namespace Fases
{
    Fase1::Fase1(int id, bool dois_jogadores):
        Fase(id,dois_jogadores),
        maxEsqueletos(5),
        maxArqueiros(5),
        maxGosmas(5),
        posicoesEsqueleto(),
        posicoesArqueiros(),
        posicoesGosmas()
    {
        //Iniciar corpo

        posicoesArqueiros.clear();
        posicoesEsqueleto.clear();
        posicoesGosmas.clear();

        // TODO - Arrumar a lógica da criaçao dos objetos
        carregarMapa("include/Tilemap/Pantano.json","include/Tilemap/SwampTiles.png");


        Entidades::Personagens::Esqueleto* esqueleto1 = new Entidades::Personagens::Esqueleto(sf::Vector2f(1612.0f, 270.0f), sf::Vector2f(80.0f, 80.0f), sf::Vector2f(0.0f, 0.0f), pJogador1);
        adicionarInimigos(static_cast<Entidades::Entidade*>(esqueleto1));

        Entidades::Personagens::Esqueleto* esqueleto2 = new Entidades::Personagens::Esqueleto(sf::Vector2f(1714.0f, 870.0f), sf::Vector2f(80.0f, 80.0f), sf::Vector2f(0.0f, 0.0f), pJogador1);
        adicionarInimigos(static_cast<Entidades::Entidade*>(esqueleto2));
            
        Entidades::Personagens::Arqueiro* arqueiro = new Entidades::Personagens::Arqueiro(sf::Vector2f(1136.0f, 400.0f), sf::Vector2f(80.0f, 80.0f), sf::Vector2f(0.0f, 0.0f), pJogador1);
        adicionarInimigos(static_cast<Entidades::Entidade*>(arqueiro));
        arqueiro->setListaProjeteis(&listaProjeteis);

        setPosicoes();
        instanciaAleatorias(posicoesGosmas, Entidades::ID::gosma);
        instanciaAleatorias(posicoesGosmas, Entidades::ID::arqueiro);

        pGC.setJogadores(&listaJogadores);
        pGC.setObstaculos(&listaObstaculos);        
        pGC.setInimigos(&listaInimigos);
        pGC.setProjeteis(&listaProjeteis);
    }

    Fase1::~Fase1()
    {
        
    }


    void Fase1::desenhar()
    {
        if(!background.loadFromFile("assets/cenarios/Background.png")){ 
            std::cerr << "Erro ao carregar a textura do mapa" << std::endl;
            return;
        }
        sf::Sprite backgroundSprite(background);
        backgroundSprite.setScale(7,3.4);
        backgroundSprite.setOrigin(sf::Vector2f(50,-20));
        pGG->desenharOutros(backgroundSprite);
    }   

    void Fase1::criarEntidade(sf::Vector2f posicao, sf::Vector2f tamanho, int tipo)
    {
        
        switch (tipo){  
            case 1 : { //plataforma
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0), tipo);
                plataforma->setTextura("assets/plataformas/grama1.png");
                adicionarObstaculos(plataforma);
            }break;
            case 2: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0), tipo);
                plataforma->setTextura("assets/plataformas/grama2.png");
                adicionarObstaculos(plataforma);
            }break;
            case 3: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0), tipo);
                plataforma->setTextura("assets/plataformas/grama3.png");
                adicionarObstaculos(plataforma);
            }break;
            case 5: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0), tipo);
                plataforma->setTextura("assets/plataformas/grama5.png");
                adicionarObstaculos(plataforma);
            }break;
            case 11: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0), tipo);
                plataforma->setTextura("assets/plataformas/grama11.png");
                adicionarObstaculos(plataforma);
            }break;
            
            case 12: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0), tipo);
                plataforma->setTextura("assets/plataformas/grama12.png");
                adicionarObstaculos(plataforma);
            }break;
            case 13: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0), tipo);
                plataforma->setTextura("assets/plataformas/grama13.png");
                adicionarObstaculos(plataforma);
            }break;
            case 22: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0), tipo);
                plataforma->setTextura("assets/plataformas/grama22.png");
                adicionarObstaculos(plataforma);
            }break;
            case 23: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0), tipo);
                plataforma->setTextura("assets/plataformas/grama23.png");
                adicionarObstaculos(plataforma);
            }break;
            case 21: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0), tipo);
                plataforma->setTextura("assets/plataformas/grama21.png");
                adicionarObstaculos(plataforma);
            }break;
            case 31: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0), tipo);
                plataforma->setTextura("assets/plataformas/grama31.png");
                adicionarObstaculos(plataforma);
            }break;
        }
    }

    void Fase1::setPosicoes() 
    {
        posicoesGosmas.push_back(sf::Vector2f(1663,563));
        posicoesGosmas.push_back(sf::Vector2f(1630,1043));
        posicoesGosmas.push_back(sf::Vector2f(2068,1043));
        posicoesGosmas.push_back(sf::Vector2f(2439,915));
        posicoesGosmas.push_back(sf::Vector2f(2442,339));
        posicoesGosmas.push_back(sf::Vector2f(450,1011));

        posicoesArqueiros.push_back(sf::Vector2f(1979,290));
    }
 
}