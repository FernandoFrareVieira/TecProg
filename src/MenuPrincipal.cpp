#include "Menus/MenuPrincipal.hpp"
#include "Observadores/MenuObservador.hpp"

namespace Menus {
    MenuPrincipal::MenuPrincipal(int id):
    Menu(5,id)
    {
        if (!fonte.loadFromFile("assets/fontes/DungeonFont.ttf")) {
            std::cerr << "Erro ao carregar a fonte Ubuntu!" << std::endl;
        }
        teste.setFont(fonte);
        teste.setCharacterSize(80);
        teste.setFillColor(sf::Color::Yellow);
        teste.setPosition(430,30);
        teste.setString("SHADOW BLADE");
        this->corpo.setSize(sf::Vector2f(LARGURA,ALTURA));
        opcoes[0]->setTexto("Singleplayer");
        opcoes[0]->setBotao(Menus::BOTOES::singleplayer);
        opcoes[0]->mudarCor();
        opcoes[1]->setTexto("Multiplayer");
        opcoes[1]->setBotao(Menus::BOTOES::multiplayer);
        opcoes[2]->setBotao(Menus::BOTOES::carregar);
        opcoes[2]->setTexto("Carregar");
        opcoes[3]->setBotao(Menus::BOTOES::leaderboard);
        opcoes[3]->setTexto("Leaderboard");
        opcoes[4]->setBotao(Menus::BOTOES::sair);
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
        pGG->desenharOutros((teste));
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