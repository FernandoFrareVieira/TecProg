#include "Menus/Menu.hpp"

namespace Menus {
    Menu::Menu(int n_opcoes):
    Ente(),
    opcoes(),
    indice_selecionado(0),
    num_opcoes(n_opcoes)
    {
        pGG = Gerenciadores::GerenciadorGrafico::getInstancia();

        for (int i = 0; i < num_opcoes; i++) {
            Opcao* op = new Opcao();
            op->setPosicao(sf::Vector2f(LARGURA/1.5,600 + 200*i));
            addOpcao(op);

        }
        corpo.setSize(sf::Vector2f(LARGURA,ALTURA));
    }

    Menu::~Menu() {
        for (int i = 0; i < num_opcoes; i++) {
            delete opcoes[i];
        }
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

    void Menu::moverBaixo() {
        if (indice_selecionado > 0) {
            opcoes[indice_selecionado]->mudarCor();
            indice_selecionado--;
            opcoes[indice_selecionado]->mudarCor();
        }
    }

    void Menu::moverCima() {
        if (indice_selecionado < num_opcoes - 1) {
            opcoes[indice_selecionado]->mudarCor();
            indice_selecionado++;
            opcoes[indice_selecionado]->mudarCor();
        }
    }

    void Menu::executar() {
        desenhar();
    }
}