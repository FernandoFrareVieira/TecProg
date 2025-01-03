#include "Jogo.hpp"

Jogo::Jogo():
pGG(Gerenciadores::GerenciadorGrafico::getInstancia()),
pGC(new Gerenciadores::GerenciadorColisoes(&listaEntidades)) 
{
    //Adicionando jogador listaTemplate
    jogador = new Entidades::Personagens::Jogador(sf::Vector2f(600.0f, 200.0f), sf::Vector2f(50.0f, 50.0f), sf::Vector2f(30.0f, 30.0f));
    listaEntidades.adicionarEntidade(static_cast<Entidades::Entidade*>(jogador));

    //Adicionar Inimigos lista Template
    for(int i = 0; i < 3; i++) {
        Entidades::Personagens::Esqueleto* esqueleto = new Entidades::Personagens::Esqueleto(sf::Vector2f(100.0f + (i*100.0f), 200.0f), sf::Vector2f(50.0f, 50.0f), sf::Vector2f(2.0f, 2.0f), jogador);
        listaEntidades.adicionarEntidade(static_cast<Entidades::Entidade*>(esqueleto));
    }

    Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(sf::Vector2f(0.0f, 600.0f), sf::Vector2f(100.0f, 30.0f), sf::Vector2f(0.0f, 0.0f));
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
        //Teste - Centralizar camera no jogador, não sei se é assim que faz
        //pGG->cententralizarCamera(jogador->getCorpo().getPosition());
        pGG->atualizarTempo();

        listaEntidades.executar();
        pGG->mostrar();
    }
}