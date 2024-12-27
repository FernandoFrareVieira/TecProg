#include "Entidades/Entidade.hpp"

namespace Entidades
{
    int Entidade::contador = 0;

    Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, int identificador):
        Ente(),
        id(identificador)
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

    int Entidade::getId()
    {
        return id;
    }
}