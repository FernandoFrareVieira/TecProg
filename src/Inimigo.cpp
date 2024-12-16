#include "Entidades/Personagens/Inimigo.hpp"

namespace Entidades
{
    namespace Personagens
    {
        Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel):
            Personagem(pos, tam, vel)
        {}
        Inimigo::~Inimigo() {}
    }
}