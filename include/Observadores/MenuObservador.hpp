#pragma once

#include "Observador.hpp"  
#include "Menus/MenuPrincipal.hpp"
#include <SFML/Window/Keyboard.hpp>
#include "Observadores/FaseObservador.hpp"

namespace Observadores {
    class MenuObservador : public Observador {
    private:
        Menus::Menu* pMenu;
        Observadores::FaseObservador* pFaseObservador;
    public:
        MenuObservador();
        ~MenuObservador();
        void notificarSolta(sf::Keyboard::Key tecla);
        void notificarPressionada(sf::Keyboard::Key tecla);
        void setMenu(Menus::Menu *pM);
    };
}       
