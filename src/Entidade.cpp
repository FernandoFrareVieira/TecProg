#include "Entidades/Entidade.hpp"

namespace Entidades
{
    int Entidade::contador = 0;

    Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam):
        Ente(),
        id(contador++),
        posicao(pos),
        tamanho(tam)
    {}

    Entidade::~Entidade()
    {}
}