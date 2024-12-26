#include "Entidades/Entidade.hpp"

namespace Entidades
{
    int Entidade::contador = 0;

    Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam):
        Ente(),
        id(contador++)
    {
        corpo.setPosition(pos);
        corpo.setSize(tam);
    }

    Entidade::~Entidade()
    {}

    const sf::RectangleShape Entidade::getCorpo() const
    {
        return corpo;
    }
}