#pragma once

#include "Gerenciadores/GerenciadorGrafico.hpp"

namespace Menus {
    class Opcao {
        private:
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
    };
}