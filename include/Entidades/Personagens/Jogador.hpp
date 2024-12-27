#pragma once

#include "Personagem.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class Jogador : public Personagem
        {
            private:
                int pontos;
                sf::Texture* textura;
            public:
                Jogador(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f velocidade, int identificador);
                ~Jogador();
                void executar();
                void desenhar();
                void mover(sf::Keyboard::Key tecla);
        };
    }
}