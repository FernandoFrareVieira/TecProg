#include "Fases/Pantanal.hpp"
#include <iostream>

namespace Fases
{
    Pantanal::Pantanal(int id, bool dois_jogadores):
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
        posicoesFogos.clear();

        // TODO - Arrumar a lógica da criaçao dos objetos
        carregarMapa("include/Tilemap/Pantano.json","include/Tilemap/SwampTiles.png");


        // Entidades::Personagens::Arqueiro* arqueiro = new Entidades::Personagens::Arqueiro(sf::Vector2f(1136.0f, 400.0f), sf::Vector2f(80.0f, 80.0f), sf::Vector2f(2.0f, 2.0f), pJogador1);
        // adicionarInimigo(static_cast<Entidades::Entidade*>(arqueiro));
        // arqueiro->setListaProjeteis(&listaProjeteis);

        setPosicoes();
        instanciaAleatorias(posicoesGosmas, Entidades::ID::gosma);
        instanciaAleatorias(posicoesArqueiros, Entidades::ID::arqueiro);
        instanciaAleatorias(posicoesEsqueleto, Entidades::ID::esqueleto);
        instanciaAleatorias(posicoesFogos, Entidades::ID::fogo);

        pGC.setJogadores(&listaJogadores);
        pGC.setObstaculos(&listaObstaculos);        
        pGC.setInimigos(&listaInimigos);
        pGC.setProjeteis(&listaProjeteis);
    }

    Pantanal::~Pantanal()
    {
        
    }


    void Pantanal::desenhar()
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

    void Pantanal::criarObstaculo(sf::Vector2f posicao, sf::Vector2f tamanho, int tipo)
    {
        
        switch (tipo){  
            case 1 : { //plataforma
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0), tipo);
                plataforma->setTextura("assets/plataformas/grama1.png");
                adicionarObstaculo(plataforma);
            }break;
            case 2: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0), tipo);
                plataforma->setTextura("assets/plataformas/grama2.png");
                adicionarObstaculo(plataforma);
            }break;
            case 3: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0), tipo);
                plataforma->setTextura("assets/plataformas/grama3.png");
                adicionarObstaculo(plataforma);
            }break;
            case 5: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0), tipo);
                plataforma->setTextura("assets/plataformas/grama5.png");
                adicionarObstaculo(plataforma);
            }break;
            case 11: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0), tipo);
                plataforma->setTextura("assets/plataformas/grama11.png");
                adicionarObstaculo(plataforma);
            }break;
            
            case 12: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0), tipo);
                plataforma->setTextura("assets/plataformas/grama12.png");
                adicionarObstaculo(plataforma);
            }break;
            case 13: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0), tipo);
                plataforma->setTextura("assets/plataformas/grama13.png");
                adicionarObstaculo(plataforma);
            }break;
            case 22: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0), tipo);
                plataforma->setTextura("assets/plataformas/grama22.png");
                adicionarObstaculo(plataforma);
            }break;
            case 23: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0), tipo);
                plataforma->setTextura("assets/plataformas/grama23.png");
                adicionarObstaculo(plataforma);
            }break;
            case 21: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0), tipo);
                plataforma->setTextura("assets/plataformas/grama21.png");
                adicionarObstaculo(plataforma);
            }break;
            case 31: {
                Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0), tipo);
                plataforma->setTextura("assets/plataformas/grama31.png");
                adicionarObstaculo(plataforma);
            }break;
        }
    }

    void Pantanal::setPosicoes() 
    {
        posicoesGosmas.push_back(sf::Vector2f(1663,563));
        posicoesGosmas.push_back(sf::Vector2f(1630,1043));
        posicoesGosmas.push_back(sf::Vector2f(2068,1043));
        posicoesGosmas.push_back(sf::Vector2f(2439,915));
        posicoesGosmas.push_back(sf::Vector2f(2442,339));
        posicoesGosmas.push_back(sf::Vector2f(450,1011));

        posicoesArqueiros.push_back(sf::Vector2f(1979,330));
        posicoesArqueiros.push_back(sf::Vector2f(2382,835));
        posicoesArqueiros.push_back(sf::Vector2f(2997,689));
        posicoesArqueiros.push_back(sf::Vector2f(1136, 400));
        
        posicoesEsqueleto.push_back(sf::Vector2f(1918,1000));
        posicoesEsqueleto.push_back(sf::Vector2f(2539,220));
        posicoesEsqueleto.push_back(sf::Vector2f(1540,420));
        posicoesEsqueleto.push_back(sf::Vector2f(2514,800));
        posicoesEsqueleto.push_back(sf::Vector2f(1640,850));
        
        posicoesFogos.push_back(sf::Vector2f(102,975));
        posicoesFogos.push_back(sf::Vector2f(1859,1007));
        posicoesFogos.push_back(sf::Vector2f(2166,1007));
        posicoesFogos.push_back(sf::Vector2f(1215,1601));
    }   

 
}