#include "Entidades/Entidade.hpp"

namespace Entidades
{
    int Entidade::contador = 0;

    Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, ID identificador):
        Ente(),
        id(identificador),
        velocidade(vel)
    {
        corpo.setPosition(pos);
        corpo.setSize(tam);

        contador++;
    }

    Entidade::~Entidade()
    {}

    sf::RectangleShape* Entidade::getCorpo()
    {
        return &corpo;
    }

    ID Entidade::getId()
    {
        return id;
    }

    sf::Vector2f Entidade::getVelocidade()
    {
        return velocidade;
    }
}