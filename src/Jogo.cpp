#include "Jogo.hpp"
#include "Observadores/MenuObservador.hpp"

Jogo::Jogo():
pGG(Gerenciadores::GerenciadorGrafico::getInstancia())
{
    //Solução terrível e provisoria
    //TODO - implementar a lógica do jogador de mover dentro de uma função no próprio jogador, não dependendo do gerenciador de eventos
    pGE = Gerenciadores::GerenciadorEventos::getInstancia();
    GE = Gerenciadores::GerenciadorEstados::getInstancia();
    GE->addEstado(0);
    executar();
}

Jogo::~Jogo()
{
   
}

void Jogo::executar()
{  
    while(pGG->getJanelaAberta()) {
        pGG->limpar();
        pGE->executar();

        //Teste - Centralizar camera no jogador, não sei se é assim que faz, tá bem estranho
        pGG->atualizarTempo();

        GE->executar();

        pGG->mostrar();
    }
}