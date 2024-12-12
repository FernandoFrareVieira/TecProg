#include "Entidades/Entidade.hpp"

namespace Entidades
{
    int Entidade::contador = 0;

    Entidade::Entidade():
        Ente(),
        id(contador++)
    {}

    Entidade::~Entidade()
    {}
}
