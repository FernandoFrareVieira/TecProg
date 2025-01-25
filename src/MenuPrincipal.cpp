#include "Menus/MenuPrincipal.hpp"
#include "Observadores/MenuObservador.hpp"

namespace Menus {
    MenuPrincipal::MenuPrincipal(int id):
    Menu(2,id) 
    {
        this->corpo.setSize(sf::Vector2f(LARGURA,ALTURA));
        opcoes[0]->setTexto("Iniciar");
        opcoes[0]->mudarCor();
        opcoes[1]->setTexto("Sair");
        
        corpo.setFillColor(sf::Color::White);
    }
    MenuPrincipal::~MenuPrincipal() {
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

    Observadores::MenuObservador* MenuPrincipal::getObservador() {
        return pMenuObservador;
    }

}