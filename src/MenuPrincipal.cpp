#include "Menus/MenuPrincipal.hpp"

namespace Menus {
    MenuPrincipal::MenuPrincipal():
    pMenuObservador(nullptr),
    Menu(2) 
    {
        this->corpo.setSize(sf::Vector2f(LARGURA,ALTURA));
        opcoes[0]->setTexto("Iniciar");
        opcoes[0]->mudarCor();
        opcoes[1]->setTexto("Sair");
        
        corpo.setFillColor(sf::Color::White);
        pMenuObservador = new Observadores::MenuObservador;
        if (pMenuObservador != nullptr) {
            pMenuObservador->setMenu(this);     
        }
    }
    MenuPrincipal::~MenuPrincipal() {
        if (pMenuObservador)
            delete pMenuObservador;
        pMenuObservador = nullptr;
    }


    void MenuPrincipal::desenhar() {
        corpo.setFillColor(sf::Color::White);
        pGG->desenhar((corpo));
        if (num_opcoes > 0) {
            for (int i = 0; i < num_opcoes; i++) {
            opcoes[i]->desenhar();
            }
        }
    }

    void MenuPrincipal::executar() {
        desenhar();
    }
}