#include "Jogo.hpp"

Jogo::Jogo():
pGG(Gerenciadores::GerenciadorGrafico::getInstancia()),
pGC(new Gerenciadores::GerenciadorColisoes(&listaEntidades)) 
{
    //Adicionando jogador listaTemplate
    jogador = new Entidades::Personagens::Jogador(sf::Vector2f(600.0f, 200.0f), sf::Vector2f(50.0f, 50.0f), sf::Vector2f(30.0f, 30.0f), 0);
    listaEntidades.adicionarEntidade(static_cast<Entidades::Entidade*>(jogador));

    //Adicionar Inimigos lista Template
    for(int i = 0; i < 3; i++) {
        Entidades::Personagens::Esqueleto* esqueleto = new Entidades::Personagens::Esqueleto(sf::Vector2f(100.0f + (i*100.0f), 200.0f), sf::Vector2f(50.0f, 50.0f), sf::Vector2f(2.0f, 2.0f), jogador, 1);
        listaEntidades.adicionarEntidade(static_cast<Entidades::Entidade*>(esqueleto));
    }

    Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(sf::Vector2f(800.0f, 700.0f), sf::Vector2f(200.0f, 40.0f), 2);
    listaEntidades.adicionarEntidade(static_cast<Entidades::Entidade*>(plataforma));

    pGE = Gerenciadores::GerenciadorEventos::getInstancia(jogador);

    executar();
}

Jogo::~Jogo()
{
    delete jogador;
}

void Jogo::executar()
{  
    while(pGG->janelaAberta()) {
        pGG->limpar();
        pGE->executar();

        pGC->gerenciar();
        
        listaEntidades.executar();
        pGG->mostrar();
    }
}