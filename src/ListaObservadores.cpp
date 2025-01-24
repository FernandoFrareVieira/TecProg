#include "Listas/ListaObservadores.hpp"
namespace Listas {
    ListaObservadores::ListaObservadores():
    LO()
    {

    }

    ListaObservadores::~ListaObservadores() {
        LO.limpar();
    }

    void ListaObservadores::add(Observadores::Observador* observador) {
        LO.incluir(observador);
    }

    void ListaObservadores::removerObservador(Observadores::Observador* observador) {
        LO.remover(observador);
    }

    int ListaObservadores::getTam() {
        return LO.getTamanho();
    }

    Observadores::Observador* ListaObservadores::operator[](int pos) {
        return LO.operator[](pos);
    }

    void ListaObservadores::notificarTeclaPressionada(const sf::Keyboard::Key tecla) {
        for (int i = 0; i < LO.getTamanho(); i++) {
            Observadores::Observador* observador = LO.operator[](i);
            if(observador->getAtivar()) {
                observador->notificar(tecla);
            }
            observador = nullptr;
        }
    }
}