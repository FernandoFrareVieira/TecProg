#pragma once

#include "Obstaculo.hpp"
#include "Entidades/Personagens/Jogador.hpp"
#include "Entidades/Personagens/Inimigos/Inimigo.hpp"
#include "Entidades/Projetil.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Plataforma : public Obstaculo
        {
            private:
                float atrito;
            public:
                Plataforma(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel = sf::Vector2f(0.0f, 0.0f), int tipoPlataforma = 1);
                ~Plataforma();
                void executar();
                void desenhar();
                void obstacular(Personagens::Jogador* jogador);
                void colidir(Entidade* entidade2, sf::Vector2f ds);
        };
    }   
}