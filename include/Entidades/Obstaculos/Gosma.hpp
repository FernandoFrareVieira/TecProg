#pragma once

#include "Obstaculo.hpp"
#include "Entidades/Personagens/Jogador.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Gosma : public Obstaculo
        {
            private:

            public:
                Gosma(sf::Vector2f pos, sf::Vector2f tam);
                ~Gosma();
                void executar();
                void desenhar();
                void obstacular(Personagens::Jogador* pJogador);
                
        };
    }
}