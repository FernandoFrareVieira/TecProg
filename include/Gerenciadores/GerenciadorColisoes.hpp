#pragma once
#include "Entidades/Entidade.hpp"
#include "Entidades/Personagens/Personagem.hpp"
#include "Listas/ListaEntidades.hpp"

namespace Gerenciadores {
    class GerenciadorColisoes {
    private:
        Listas::ListaEntidades* listaEntidades;
    public:
        GerenciadorColisoes(Listas::ListaEntidades* LE);
        ~GerenciadorColisoes();
        void colisao(Entidades::Entidade* ente1, Entidades::Entidade* ente2);
        void gerenciar();

               
    };
}