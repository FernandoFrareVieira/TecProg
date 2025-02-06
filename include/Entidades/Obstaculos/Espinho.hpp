#pragma once

#include "Obstaculo.hpp"
#include "Entidades/Personagens/Jogador.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Espinho : public Obstaculo
        {
            private:
                int dano;
            public:
                Espinho(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel = sf::Vector2f(0.0f, 0.0f));
                ~Espinho();
                void executar();
                void desenhar();
                void obstacular(Personagens::Jogador* pJogador);
                void colidir(Entidade* entidade2, sf::Vector2f ds);
        };
    }
}