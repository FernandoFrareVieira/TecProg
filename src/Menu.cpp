#include "Menus/Menu.hpp"

namespace Menus {
    Menu::Menu(int n_opcoes):
    cor_normal(sf::Color::White),
    cor_selecao(sf::Color::Green),
    num_opcoes(n_opcoes)
    {
        pGG = Gerenciadores::GerenciadorGrafico::getInstancia();
    }

    Menu::~Menu() {

    }

    void Menu::desenhar() {
        for (int i = 0; i < num_opcoes; i++) {
            opcoes[i]->desenhar();
        }
    }

    void Menu::addOpcao(Opcao* op) {
        if (op)
            opcoes.push_back(op);
    }

    int Menu::getIndice() const {
        return indice_selecionado;
    }
}