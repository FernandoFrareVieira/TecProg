#pragma once

#include "Entidades/Entidade.hpp"
#include "Entidades/Personagens/Jogador.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Obstaculo : public Entidade
        {
            protected:   
                bool nocivo;
            public:
                Obstaculo(sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f), sf::Vector2f tam = sf::Vector2f(0.0f, 0.0f));
                ~Obstaculo();
                virtual void executar() = 0;
                virtual void desenhar() = 0;
                virtual void obstacular(Personagens::Jogador* pJogador) = 0;
        };
    }
}