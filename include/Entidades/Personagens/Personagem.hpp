#pragma once

#include "../Entidade.hpp"

namespace Entidades
{
    namespace Personagens 
    {
        class Personagem : public Entidade
        {
            protected:
                sf::RectangleShape corpo;
                sf::Vector2f velocidade;
                int vida;
            public:
                Personagem();
                ~Personagem();
                virtual void executar() = 0;
                virtual void desenhar() = 0;
                void tomarDano(int dano);
        };
    }
}