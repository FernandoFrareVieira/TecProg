#include "Jogo.hpp"

Jogo::Jogo():
pGG(Gerenciadores::GerenciadorGrafico::getInstancia()),
pGE(Gerenciadores::GerenciadorEventos::getInstancia())
{
    jogador = new Entidades::Personagens::Jogador;
    executar();
}

Jogo::~Jogo()
{}

void Jogo::executar()
{  
    while(pGG->janelaAberta()) {
        pGG->limpar();
        pGE->executar();
        jogador->desenhar();
        pGG->mostrar();
    }
}