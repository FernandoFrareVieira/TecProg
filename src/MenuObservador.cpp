#include "Observadores/MenuObservador.hpp" 

namespace Observadores {
    MenuObservador::MenuObservador():
    Observador()
    {
        pFaseObservador = Observadores::FaseObservador::getInstancia();
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
        if (tecla == sf::Keyboard::Escape) {
            removerObservador();
        }
        if (tecla == sf::Keyboard::Key::Enter) {
            if (pMenu->getBotao() == Menus::BOTOES::singleplayer && pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_principal){
                removerObservador();
                pGEstados->setMultiplayer(false);
                pGEstados->removerEstado();
                pGEstados->adicionarEstado(6);
            }
            else if (pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_principal && pMenu->getBotao() == Menus::BOTOES::multiplayer) {
                pGEstados->setMultiplayer(true);
                removerObservador();
                pGEstados->removerEstado();
                pGEstados->adicionarEstado(6);
            }
            else if (pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_fases && pMenu->getBotao() == Menus::BOTOES::voltar) {
                removerObservador();
                pGEstados->removerEstado();
                pGEstados->adicionarEstado(0);
            }
            else if (pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_fases && pMenu->getBotao() == Menus::BOTOES::pantanal) {
                removerObservador();
                pGEstados->removerEstado();
                pGEstados->adicionarEstado(1);
            }
            else if (pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_fases && pMenu->getBotao() == Menus::BOTOES::nether) {
                removerObservador();
                pGEstados->removerEstado();
                pGEstados->adicionarEstado(3);
            }
            else if (pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_principal && pMenu->getBotao() == Menus::BOTOES::carregar) {
                pGEstados->removerEstado();
                pGEstados->adicionarEstado(1);
                pFaseObservador->notificarCarregamento();
            }
            else if (pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_pause && pMenu->getBotao() == Menus::BOTOES::salvar) {
                pFaseObservador->notificarSalvamento();
            }
            else if (pMenu->getBotao() == Menus::BOTOES::continuar && pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_pause){
                pGEstados->removerEstado();
            }
            else if (pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::leaderboard && pMenu->getBotao() == Menus::BOTOES::voltar) {
                pGEstados->removerEstado();
                removerObservador();
                pGEstados->adicionarEstado(0);
                fflush(stdout);
            }
            else if (pMenu->getBotao() == Menus::BOTOES::sair && pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_principal) {
                pGG->fechar();
            }
            else if (pMenu->getBotao() == Menus::BOTOES::menu_principal && pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_pause){
                removerObservador();
                pGEstados->removerEstado();
                pGEstados->removerEstado();
                pGEstados->adicionarEstado(0);
            }
            else if (pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::menu_principal && pMenu->getBotao() == Menus::BOTOES::leaderboard) {
                removerObservador();
                pGEstados->removerEstado();
                pGEstados->adicionarEstado(5);
            }
            if (pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::game_over && pMenu->getBotao() == Menus::BOTOES::menu_principal) {
                removerObservador();
                pGEstados->removerEstado();
                pGEstados->adicionarEstado(0);
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

