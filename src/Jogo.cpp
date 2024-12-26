#include "Jogo.hpp"

Jogo::Jogo():
pGG(Gerenciadores::GerenciadorGrafico::getInstancia()),
pGC(new Gerenciadores::GerenciadorColisoes()) 
{
    jogador = new Entidades::Personagens::Jogador(sf::Vector2f(600.0f, 200.0f), sf::Vector2f(50.0f, 50.0f), sf::Vector2f(30.0f, 30.0f));
    esqueleto = new Entidades::Personagens::Esqueleto(sf::Vector2f(100.0f, 200.0f), sf::Vector2f(50.0f, 50.0f), sf::Vector2f(5.0f, 5.0f), jogador);
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
        esqueleto->executar();
        jogador->desenhar();
        pGG->mostrar();
    }
}