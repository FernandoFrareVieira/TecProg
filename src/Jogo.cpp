#include "Jogo.hpp"

Jogo::Jogo():
pGG(Gerenciadores::GerenciadorGrafico::getInstancia()),
pGC(new Gerenciadores::GerenciadorColisoes()) 
{
    jogador = new Entidades::Personagens::Jogador(sf::Vector2f(600.0f, 200.0f), sf::Vector2f(50.0f, 50.0f), sf::Vector2f(30.0f, 30.0f));
    //Loop para testar vários inimigos
    for(int i = 0; i < 3; i++) {
        esqueleto = new Entidades::Personagens::Esqueleto(sf::Vector2f(100.0f + (i*100.0f), 200.0f), sf::Vector2f(50.0f, 50.0f), sf::Vector2f(2.0f, 2.0f), jogador);
        personagens.push_back(static_cast<Entidades::Personagens::Personagem*>(esqueleto));
    }

    personagens.push_back(static_cast<Entidades::Personagens::Personagem*>(jogador));

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
        pGC->colisao(jogador, esqueleto);   
        
        //Loop no vetor para teste de jogador e inimigo em uma lista    
        for(int i = 0; i < personagens.size(); i++) {
            personagens[i]->executar();
        }
        pGG->mostrar();
    }
}