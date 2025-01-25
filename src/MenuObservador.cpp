#include "Observadores/MenuObservador.hpp"
#include "Menus/MenuPrincipal.hpp" 

namespace Observadores {
    MenuObservador::MenuObservador():
    Observador()
    {
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

    void MenuObservador::notificarPressionada(sf::Keyboard::Key tecla) {
        if (!pMenu)
            return;
        if (tecla == sf::Keyboard::Key::Enter) {
            printf("ENTER RECEBIDO\n");
            fflush(stdout);
            pMenu->selecionar(); //jogo fecha
            if (pMenu->getIndice() == 0 && pGEstados->getEstadoAtual()->getID() == 0){
                pGEstados->removerEstado();
                fflush(stdout);
            }
        }
        
    }

    void MenuObservador::notificarSolta(sf::Keyboard::Key tecla) {
        if (!pMenu)
            return;
        if (tecla == sf::Keyboard::Key::Down) {
                pMenu->moverCima();
                pMenu->desenhar();
        }
        else if (tecla == sf::Keyboard::Key::Up) {
                pMenu->moverBaixo();
                pMenu->desenhar();
        }
    }
}

