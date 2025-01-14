#pragma once

#include "Obstaculo.hpp"
#include "Entidades/Personagens/Jogador.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Plataforma : public Obstaculo
        {
            private:

            public:
                Plataforma(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel = sf::Vector2f(0.0f, 0.0f));
                ~Plataforma();
                void executar();
                void desenhar();
                void obstacular(Personagens::Jogador* jogador);
                void setTextura(std::string caminhoTextura);
        };
    }   
}