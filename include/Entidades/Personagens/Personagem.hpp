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
                bool vivo;
            public:
                Personagem(sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f), sf::Vector2f tam = sf::Vector2f(0.0f, 0.0f), sf::Vector2f velocidade = sf::Vector2f(0.0f, 0.0f));
                ~Personagem();
                virtual void executar() = 0;
                virtual void desenhar() = 0;
                void tomarDano(int dano);
                sf::RectangleShape& getCorpo();
        };
    }
}