#pragma once

#include "Observador.hpp"  // Classe base para MenuObservador
#include "Menus/MenuPrincipal.hpp"
#include <SFML/Window/Keyboard.hpp>

namespace Observadores {
    class MenuObservador : public Observador {
    private:
        Menus::MenuPrincipal* pMenu;
    public:
        MenuObservador();
        ~MenuObservador();
        void notificar(sf::Keyboard::Key tecla);
        void setMenu(Menus::MenuPrincipal *pM);
    };
}       
