
#include "Observadores/MenuObservador.hpp"
#include "Menus/MenuPrincipal.hpp" 

namespace Observadores {
    MenuObservador::MenuObservador() {

    }

    MenuObservador::~MenuObservador() {
        if (pMenu)
            pMenu = nullptr;
    }

    void MenuObservador::setMenu(Menus::MenuPrincipal* pM) {
        if (pM) {
            pMenu = pM;
        }
    }

    void MenuObservador::atualizar(sf::Keyboard::Key tecla) {
        if (!pMenu)
            return;
        if (tecla == sf::Keyboard::Key::Up) {
                pMenu->moverCima();
        }
        else if (tecla == sf::Keyboard::Key::Down) {
                pMenu->moverBaixo();
        }
    }
}

