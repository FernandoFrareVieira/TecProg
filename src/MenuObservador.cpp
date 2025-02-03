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
            if (pMenu->getBotao() == Menus::BOTOES::iniciar && pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_principal){
                pGEstados->removerEstado();
                pGEstados->addEstado(1);
            }
            else if (pMenu->getBotao() == Menus::BOTOES::sair && pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_principal) {
                pGG->fechar();
            }
            else if (pMenu->getBotao() == Menus::BOTOES::continuar && pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_pause){
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
            if (pMenu->getBotao() == Menus::BOTOES::menu_principal && pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_pause){
                pGEstados->removerEstado();
                pGEstados->removerEstado();
                pGEstados->addEstado(0);
            }
            else if (pGEstados->getEstadoAtual()->getID() == Estados::ID_Estado::game_over && pMenu->getBotao() == Menus::BOTOES::menu_principal) {
                pGEstados->removerEstado();
                pGEstados->addEstado(0);
            }
        }
    }
}

