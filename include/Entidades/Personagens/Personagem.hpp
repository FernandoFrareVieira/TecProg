    #pragma once

#include "../Entidade.hpp"

namespace Entidades
{
    namespace Personagens 
    {
        class Personagem : public Entidade
        {
            protected:
                int vida;
                bool vivo;
            public:
                Personagem(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, ID identificador = vazio);
                ~Personagem();
                virtual void executar() = 0;
                virtual void desenhar() = 0;
                void tomarDano(int dano);

                virtual void colidir(Entidade* entidade2, sf::Vector2f ds) = 0;
        };
    }
}