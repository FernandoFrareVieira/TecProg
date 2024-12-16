#include "Jogo.hpp"

Jogo::Jogo():
pGG(Gerenciadores::GerenciadorGrafico::getInstancia())
{
    jogador = new Entidades::Personagens::Jogador(sf::Vector2f(200.0f, 200.0f), sf::Vector2f(200.0f, 200.0f), sf::Vector2f(10.0f, 10.0f));
    esqueleto = new Entidades::Personagens::Esqueleto(sf::Vector2f(100.0f, 200.0f), sf::Vector2f(100.0f, 100.0f), sf::Vector2f(10.0f, 10.0f));
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
        jogador->desenhar();
        esqueleto->desenhar();
        pGG->mostrar();
    }
}