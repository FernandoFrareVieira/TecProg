#pragma once 

#include "Lista.hpp"
#include "Observadores/Observador.hpp"
#include "SFML/Graphics.hpp"

namespace Listas {
    class ListaObservadores {
    private:
        Lista<Observadores::Observador> LO;
    public:
        ListaObservadores();
        ~ListaObservadores();
        void add(Observadores::Observador* observador);
        void removerObservador(Observadores::Observador* observador);
        void removerObservador(int pos);
        int getTam();
        Observadores::Observador* operator[](int pos);
        void notificarTeclaPressionada(const sf::Keyboard::Key tecla);

    };
}
