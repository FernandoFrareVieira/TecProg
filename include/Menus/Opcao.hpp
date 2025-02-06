#pragma once

#include "Gerenciadores/GerenciadorGrafico.hpp"

namespace Menus {
    enum BOTOES {
        vazio,
        iniciar,
        sair,
        continuar,
        salvar,
        menu_principal,
        voltar,
        carregar,
        multiplayer,
        leaderboard,
    };
    class Opcao {
        private:
            BOTOES botao;
            sf::Font fonte;
            sf::RectangleShape corpo;
            sf::Text texto;
            Gerenciadores::GerenciadorGrafico* pGG;
        public:
            Opcao();
            ~Opcao();
            void desenhar();
            void setPosicao(sf::Vector2f posicao);
            void setTexto(const std::string text);
            void mudarCor();
            void setBotao(BOTOES b) {botao = b;}
            BOTOES getBotao() {return botao;}
    };
}