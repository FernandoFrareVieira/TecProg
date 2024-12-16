#pragma once

#include "Inimigo.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class Esqueleto : public Inimigo
        {
            private:
                sf::Texture* textura;
            public:
                Esqueleto(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel);
                ~Esqueleto();
                void executar();
                void desenhar();
                void mover();
        };
    }
    }
