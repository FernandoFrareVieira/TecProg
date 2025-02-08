#include "Menus/MenuFases.hpp"

namespace Menus {
    MenuFases::MenuFases(int id):
    Menu(3,id)
    {
        opcoes[0]->setTexto("Pantanal");
        opcoes[0]->setBotao(Menus::BOTOES::pantanal);
        opcoes[0]->mudarCor();
        opcoes[1]->setTexto("Nether");
        opcoes[1]->setBotao(Menus::BOTOES::nether);
        opcoes[2]->setTexto("Voltar");
        opcoes[2]->setBotao(Menus::BOTOES::voltar);

    }
    
    MenuFases::~MenuFases() {
        /*if (pMenuObservador) {
            delete pMenuObservador;
        }
        pMenuObservador = nullptr;*talvez colocar*/
    }

    void MenuFases::desenhar() {
        corpo.setFillColor(sf::Color::White);
        pGG->desenhar((corpo));
        if (num_opcoes > 0) {
            for (int i = 0; i < num_opcoes; i++) {
            opcoes[i]->desenhar();
            }
        }
    }

    void MenuFases::executar() {
        desenhar();
    }
}