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
        pGG->desenhar((this->corpo));
        for (int i = 0; i < num_opcoes; i++) {
            opcoes[i]->desenhar();
        }
    }
}