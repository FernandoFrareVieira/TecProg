#include "Menus/Leaderboard.hpp"

namespace Menus {
    Leaderboard::Leaderboard(int id):
    Menu(9,id),
    jogadores()
    {
        int i = 0;
        for (auto it = jogadores.begin(); it !=  jogadores.end(); it++) {
            opcoes[i]->setTexto(it->first);
            opcoes[i]->setPosicao(sf::Vector2f(1050,700 + 100*i));
            i++;
        }
        i = 0;
        for (auto it = jogadores.begin(); it !=  jogadores.end(); it++) {
            opcoes[i]->setTexto(it->second);
            opcoes[i]->setPosicao(sf::Vector2f(1050 + 50*i,700 + 100*i));
            i++;
        }
        opcoes[8]->setTexto("Voltar");
        opcoes[8]->setPosicao(sf::Vector2f(1050,1500));
    }

    Leaderboard::~Leaderboard() {

    }

    void Leaderboard::desenhar() {
        corpo.setFillColor(sf::Color::White);
        pGG->desenhar((corpo));
        if (num_opcoes > 0) {
            for (int i = 0; i < num_opcoes; i++) {
            opcoes[i]->desenhar();
            }
        }
    }

    void Leaderboard::executar() {
        desenhar();
    }
}