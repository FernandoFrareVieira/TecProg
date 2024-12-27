#include "Entidades/Obstaculos/Plataforma.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam):
        Obstaculo(pos, tam)
        {
            corpo.setFillColor(sf::Color::Green);
        }

        Plataforma::~Plataforma(){}

        void Plataforma::executar()
        {
            desenhar();
        }

        void Plataforma::desenhar()
        {
            pGG->desenhar(corpo);
        }

        void Plataforma::obstacular(Personagens::Jogador* jogador)
        {
            //Quando tiver colisão
        }
    }
}