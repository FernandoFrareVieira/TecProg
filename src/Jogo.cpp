#include "Jogo.hpp"
#include "Observadores/MenuObservador.hpp"

Jogo::Jogo():
pGG(Gerenciadores::GerenciadorGrafico::getInstancia()),
fase1()
{
    //Solução terrível e provisoria
    //TODO - implementar a lógica do jogador de mover dentro de uma função no próprio jogador, não dependendo do gerenciador de eventos
    pGE = Gerenciadores::GerenciadorEventos::getInstancia(fase1.getJogador());

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
        //pGG->cententralizarCamera(jogador->getCorpo().getPosition());
        pGG->atualizarTempo();

        fase1.executar();

        pGG->mostrar();
    }
}