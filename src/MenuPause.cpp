#include "Menus/MenuPause.hpp"

namespace Menus {
    MenuPause::MenuPause(int id):
    Menu(2,id) {
        this->corpo.setSize(sf::Vector2f(LARGURA,ALTURA));
        
        opcoes[0]->setTexto("Continuar");
        opcoes[0]->mudarCor();
        opcoes[1]->setTexto("Menu Principal");
        corpo.setFillColor(sf::Color::White);
    }

    MenuPause::~MenuPause(){}

    void MenuPause::desenhar() {
        corpo.setFillColor(sf::Color::White);
        pGG->desenhar(corpo);
        if (num_opcoes > 0) {
            for (int i = 0; i < num_opcoes; i++) {
            opcoes[i]->desenhar();
            }
        }
    }

    void MenuPause::executar() {
        desenhar();
    }

}