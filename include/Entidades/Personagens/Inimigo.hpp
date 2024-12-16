#pragma once

#include "Personagem.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class Inimigo : public Personagem
        {
            private:
                int dano;
            public:
                Inimigo(sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f), sf::Vector2f tam = sf::Vector2f(0.0f, 0.0f), sf::Vector2f velocidade = sf::Vector2f(0.0f, 0.0f));
                ~Inimigo();
                virtual void executar() = 0;
                virtual void desenhar() = 0;
                virtual void mover() = 0;
        };
    }
}