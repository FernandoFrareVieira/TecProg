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
        if (tecla == sf::Keyboard::Down)
            printf("DOWN\n");
        if (tecla == sf::Keyboard::Key::Enter) {
            printf("ENTER\n");
            if (pMenu->getBotao() == Menus::BOTOES::iniciar && pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_principal){
                pGEstados->setMultiplayer(false);
                removerObservador();
                pGEstados->removerEstado();
                pGEstados->addEstado(1);
            }
            else if (pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_principal && pMenu->getBotao() == Menus::BOTOES::multiplayer) {
                pGEstados->setMultiplayer(true);
                removerObservador();
                pGEstados->removerEstado();
                pGEstados->addEstado(1);
            }
            else if (pMenu->getBotao() == Menus::BOTOES::continuar && pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_pause){
                removerObservador();
                pGEstados->removerEstado();
            }
            else if (pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::leaderboard && pMenu->getBotao() == Menus::BOTOES::voltar) {
                pGEstados->removerEstado();
                removerObservador();
                pGEstados->addEstado(0);
                fflush(stdout);
            }
            else if (pMenu->getBotao() == Menus::BOTOES::sair && pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_principal) {
                pGG->fechar();
            }
            else if (pMenu->getBotao() == Menus::BOTOES::menu_principal && pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_pause){
                removerObservador();
                pGEstados->removerEstado();
                pGEstados->removerEstado();
                pGEstados->addEstado(0);
            }
            else if (pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_principal && pMenu->getBotao() == Menus::BOTOES::leaderboard) {
                removerObservador();
                pGEstados->removerEstado();
                pGEstados->addEstado(5);
            }
            if (pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::game_over && pMenu->getBotao() == Menus::BOTOES::menu_principal) {
                removerObservador();
                pGEstados->removerEstado();
                pGEstados->addEstado(0);
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

