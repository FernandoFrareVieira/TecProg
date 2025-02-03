#include "Observadores/MenuObservador.hpp" 

namespace Observadores {
    MenuObservador::MenuObservador():
    Observador()
    {
    }

    MenuObservador::~MenuObservador() {
        if (pMenu)
            pMenu = nullptr;
    }

    void MenuObservador::setMenu(Menus::Menu* pM) {
        if (pM) {
            pMenu = pM;
        }
    }

    void MenuObservador::notificarPressionada(sf::Keyboard::Key tecla) {
        if (!pMenu)
            return;
        if (tecla == sf::Keyboard::Key::Enter) {
            if (pMenu->getIndice() == 0 && pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_principal){
                pGEstados->removerEstado();
                pGEstados->addEstado(1);
            }
            else if (pMenu->getIndice() == 1 && pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_principal) {
                pGG->fechar();
            }
            else if (pMenu->getIndice() == 0 && pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_pause){
                pGEstados->removerEstado();
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
        else if (tecla == sf::Keyboard::Key::Enter) {
            if (pMenu->getIndice() == 1 && pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_pause){
                pGEstados->removerEstado();
                pGEstados->removerEstado();
                pGEstados->addEstado(0);
            }
            else if (pGEstados->getEstadoAtual()->getID() == Estados::ID_Estado::game_over && pMenu->getIndice() == 0) {
                pGEstados->removerEstado();
                pGEstados->addEstado(5);
            }
        }
    }
}

