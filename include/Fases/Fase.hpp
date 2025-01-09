#pragma once

#include "Ente.hpp"
#include "Listas/ListaEntidades.hpp"
#include "Entidades/Personagens/Jogador.hpp"
#include "Gerenciadores/GerenciadorColisoes.hpp"

namespace Fases
{
    class Fase : public Ente
    {
        protected:
            Listas::ListaEntidades listaObstaculos;
            Listas::ListaEntidades listaInimigos;
            Listas::ListaEntidades listaJogadores;

            sf::RectangleShape corpo;

            Gerenciadores::GerenciadorColisoes pGC;
        public:
            Fase();
            ~Fase();
            virtual void executar() = 0;
            virtual void desenhar() = 0;

            void adicionarInimigos(Entidades::Entidade* inimigo);
            void adicionarObstaculos(Entidades::Entidade* obstaculo);
            void adicionarJogador(Entidades::Entidade* jogador);
            
    };
}