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
                Jogador(sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f), sf::Vector2f tam = sf::Vector2f(0.0f, 0.0f), sf::Vector2f velocidade = sf::Vector2f(0.0f, 0.0f));
                ~Jogador();
                void executar();
                void desenhar();
                void mover(sf::Keyboard::Key tecla);
        };
    }
}