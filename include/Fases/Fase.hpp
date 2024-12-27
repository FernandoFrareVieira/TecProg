#pragma once

#include "Ente.hpp"
#include "Listas/ListaEntidades.hpp"
#include "Entidades/Personagens/Jogador.hpp"

namespace Fases
{
    class Fase : public Ente
    {
        protected:
            Listas::ListaEntidades listaObstaculos;
            Listas::ListaEntidades listaPersonagens;
        public:
            Fase();
            ~Fase();
            virtual void executar() = 0;
            virtual void desenhar() = 0;
    };
}