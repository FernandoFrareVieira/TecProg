#include "Menus/GameOver.hpp"

namespace Menus {
    GameOver::GameOver(int id):
    Menus::Menu(2,id)
    {
        this->corpo.setSize(sf::Vector2f(LARGURA,ALTURA));
        corpo.setFillColor(sf::Color::White);
    }

    GameOver::~GameOver() {

    }

    void GameOver::desenhar() {
        corpo.setFillColor(sf::Color::White);
        pGG->desenhar((corpo));
        if (num_opcoes > 0) {
            for (int i = 0; i < num_opcoes; i++) {
            opcoes[i]->desenhar();
            }
        }
    }
}