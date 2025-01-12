#include "Fases/Fase1.hpp"
#include "Tilemap/Tilemap.hpp"

namespace Fases
{
    Fase1::Fase1():
        maxEsqueletos(3),
        maxPlataformas(3),
        Fase()
    {
        //Iniciar corpo
        // TODO - Achaar o sprite do background da fase 1

        // TODO - Arrumar a lógica da criaçao dos objetos
        Tilemap* tilemap = new Tilemap("include/Tilemap/teste2.json");
        jogador = new Entidades::Personagens::Jogador(sf::Vector2f(600.0f, 200.0f), sf::Vector2f(50.0f, 50.0f), sf::Vector2f(30.0f, 30.0f));
        adicionarJogador(static_cast<Entidades::Entidade*>(jogador));
        pGC.setJogadores(&listaJogadores);

        for(int i = 0; i < 3; i++) {
            Entidades::Personagens::Esqueleto* esqueleto = new Entidades::Personagens::Esqueleto(sf::Vector2f(100.0f + (i*100.0f), 200.0f), sf::Vector2f(50.0f, 50.0f), sf::Vector2f(2.0f, 2.0f), jogador);
            adicionarInimigos(static_cast<Entidades::Entidade*>(esqueleto));
        }
        pGC.setInimigos(&listaInimigos);

        //Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(sf::Vector2f(0.0f, 600.0f), sf::Vector2f(100.0f, 30.0f), sf::Vector2f(0.0f, 0.0f));
        //adicionarObstaculos(static_cast<Entidades::Entidade*>(plataforma));
        tilemap->criarMapa(&listaObstaculos);
        pGC.setObstaculos(&listaObstaculos);
    }

    Fase1::~Fase1()
    {
        
    }

    void Fase1::executar()
    {
        listaObstaculos.executar();
        listaInimigos.executar();
        listaJogadores.executar();

        pGC.gerenciar();

        //desenhar();
    }

    void Fase1::desenhar()
    {
        pGG->desenhar(corpo);
    }

    Entidades::Personagens::Jogador* Fase1::getJogador()
    {
        return jogador;
    }
}