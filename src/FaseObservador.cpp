#include "Observadores/FaseObservador.hpp"
#include "Gerenciadores/GerenciadorEstados.hpp"

namespace Observadores {
    FaseObservador::FaseObservador():
    Observador()
    {

    }

    FaseObservador::~FaseObservador() {

    }

    void FaseObservador::notificarMudarFase() {
        if (pGEstados->getEstadoAtual()->getID() == 1) {
            pGEstados->removerEstado();
            pGEstados->addEstado(3);
        }
    }

    void FaseObservador::notificarGameOver() {
        pGEstados->removerEstado();
        pGEstados->addEstado(4);
    }

    void FaseObservador::notificarPressionada(sf::Keyboard::Key tecla){

    }

    void FaseObservador::notificarSolta(sf::Keyboard::Key tecla) {

    }

}