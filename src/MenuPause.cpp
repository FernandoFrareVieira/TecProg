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

}