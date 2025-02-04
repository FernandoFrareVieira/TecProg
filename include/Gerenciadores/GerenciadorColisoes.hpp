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
        Listas::ListaEntidades* listaProjeteis;
        
    public:
        GerenciadorColisoes();
        ~GerenciadorColisoes();

        void setObstaculos(Listas::ListaEntidades* LO);
        void setInimigos(Listas::ListaEntidades* LI);
        void setJogadores(Listas::ListaEntidades* LJ);
        void setProjeteis(Listas::ListaEntidades* LP);

        void gerenciar();
        sf::Vector2f calculaColisao(Entidades::Entidade* entidade1, Entidades::Entidade* entidade2);
        void reiniciaPulo();
    };
}