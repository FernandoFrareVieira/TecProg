#pragma once

#include "Observador.hpp"  
#include "Menus/MenuPrincipal.hpp"
#include <SFML/Window/Keyboard.hpp>

namespace Menus {
    class MenuPrincipal;
}

namespace Observadores {
    class MenuObservador : public Observador {
    private:
        Menus::MenuPrincipal* pMenu;
    public:
        MenuObservador();
        ~MenuObservador();
        void atualizar(sf::Keyboard::Key tecla);
        void setMenu(Menus::MenuPrincipal *pM);
    };
}       
