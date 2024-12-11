#include "Jogo.hpp"

Jogo::Jogo():
pGG(Gerenciadores::GerenciadorGrafico::getInstancia()),
pGE(Gerenciadores::GerenciadorEventos::getInstancia())
{
    executar();
}

Jogo::~Jogo()
{}

void Jogo::executar()
{
    while(pGG->janelaAberta()) {
        pGG->limpar();
        pGE->executar();
        pGG->mostrar();
    }
}