#include "Entidades/Obstaculos/Obstaculo.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Obstaculo::Obstaculo(sf::Vector2f pos, sf::Vector2f tam):
            Entidade(pos, tam)
        {}

        Obstaculo::~Obstaculo()
        {}
    }
}