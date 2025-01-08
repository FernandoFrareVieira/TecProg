#pragma once
#include "Entidades/Entidade.hpp"
#include "Entidades/Personagens/Personagem.hpp"
#include "Listas/ListaEntidades.hpp"

namespace Gerenciadores {
    class GerenciadorColisoes {
    private:
        Listas::ListaEntidades* listaObstaculos;
        Listas::ListaEntidades* listaInimigos;
        Listas::ListaEntidades* listaJogadores;
    public:
        GerenciadorColisoes();
        ~GerenciadorColisoes();

        void setObstaculos(Listas::ListaEntidades* LO);
        void setInimigos(Listas::ListaEntidades* LI);
        void setJogadores(Listas::ListaEntidades* LJ);

        void colisao(Entidades::Entidade* ente1, Entidades::Entidade* ente2);
        void gerenciar();
        void colisaoPersonagens(Entidades::Entidade* ente1, Entidades::Entidade* ente2, float overlap_x, float overlap_y, float dist_x, float dist_y);

               
    };
}