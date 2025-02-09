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
        void adicionarObservador(Observadores::Observador* observador);
        void removerObservador(Observadores::Observador* observador);
        int getTam();
        Observadores::Observador* operator[](int pos);
        void notificarTeclaPressionada(const sf::Keyboard::Key tecla);
        void notificarTeclaSolta(const sf::Keyboard::Key tecla);

    };
}
