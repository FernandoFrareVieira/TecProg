#include "Fases/Fase1.hpp"

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
        carregarMapa("include/Tilemap/Tiles.json","include/Tilemap/Tileset.png");
        jogador = new Entidades::Personagens::Jogador(sf::Vector2f(0.0f, 720.0f), sf::Vector2f(50.0f, 50.0f), sf::Vector2f(30.0f, 30.0f));
        adicionarJogador(static_cast<Entidades::Entidade*>(jogador));
        pGC.setJogadores(&listaJogadores);

        for(int i = 0; i < 3; i++) {
            Entidades::Personagens::Esqueleto* esqueleto = new Entidades::Personagens::Esqueleto(sf::Vector2f(100.0f + (i*100.0f), 200.0f), sf::Vector2f(50.0f, 50.0f), sf::Vector2f(2.0f, 2.0f), jogador);
            adicionarInimigos(static_cast<Entidades::Entidade*>(esqueleto));
        }
        criarInimigos("include/Tilemap/Tiles.json",posicoes,jogador);
        pGC.setInimigos(&listaInimigos);

        //Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(sf::Vector2f(500.0f, 400.0f), sf::Vector2f(400.0f, 100.0f), sf::Vector2f(0.0f, 0.0f));
        //adicionarObstaculos(static_cast<Entidades::Entidade*>(plataforma));
        //listaObstaculos = tilemap->criarMapa(listaObstaculos);
        pGC.setObstaculos(&listaObstaculos);
    }

    Fase1::~Fase1()
    {
        
    }

    void Fase1::executar()
    {
        desenhar();
        listaObstaculos.executar();
        listaInimigos.executar();
        listaJogadores.executar();

        pGC.gerenciar();
    }

    void Fase1::desenhar()
    {
        if(!background.loadFromFile("assets/cenarios/Background.png")){ //Está dando seg fault"
            std::cerr << "Erro ao carregar a textura do mapa" << std::endl;
            return;
        }
        sf::Sprite backgroundSprite(background);
        backgroundSprite.setScale(4,4);
        backgroundSprite.setOrigin(sf::Vector2f(50,50));
        pGG->desenharOutros(backgroundSprite);
        pGG->centralizarCamera(jogador->getCorpo()->getPosition());
    }   
}