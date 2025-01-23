#include "Jogo.hpp"
#include "Observadores/MenuObservador.hpp"

Jogo::Jogo():
pGG(Gerenciadores::GerenciadorGrafico::getInstancia()),
fase1(new Fases::Fase1())
{
    //Solução terrível e provisoria
    //TODO - implementar a lógica do jogador de mover dentro de uma função no próprio jogador, não dependendo do gerenciador de eventos
    pGE = Gerenciadores::GerenciadorEventos::getInstancia();
    GE = Gerenciadores::GerenciadorEstados::getInstancia();
    GE->addEstado(fase1);

    executar();
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{  
    while(pGG->janelaAberta()) {
        pGG->limpar();
        pGE->executar();

        //Teste - Centralizar camera no jogador, não sei se é assim que faz, tá bem estranho
        pGG->atualizarTempo();

        GE->executar();

        pGG->mostrar();
    }
}