#include "Menus/MenuPrincipal.hpp"
#include "Observadores/MenuObservador.hpp"

namespace Menus {
    MenuPrincipal::MenuPrincipal(int id):
    Menu(6,id)
    {
        this->corpo.setSize(sf::Vector2f(LARGURA,ALTURA));
        opcoes[0]->setTexto("Iniciar");
        opcoes[0]->setBotao(Menus::BOTOES::iniciar);
        opcoes[0]->mudarCor();
        opcoes[1]->setBotao(dois_jogadores);
        opcoes[1]->setTexto("Iniciar 2 Jogadores");
        opcoes[2]->setBotao(carregar);
        opcoes[2]->setTexto("Carregar");
        opcoes[3]->setBotao(leaderboard);
        opcoes[3]->setTexto("Leaderboard");
        opcoes[4]->setBotao(sair);
        opcoes[4]->setTexto("Sair");
        corpo.setFillColor(sf::Color::White);
    }
    MenuPrincipal::~MenuPrincipal() {
        if (pMenuObservador) {
            delete pMenuObservador;
        }
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