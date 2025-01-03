#include "Entidades/Obstaculos/Obstaculo.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Obstaculo::Obstaculo(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel):
            Entidade(pos, tam, vel, ID::obstaculo)
        {}

        Obstaculo::~Obstaculo()
        {}
    }
}