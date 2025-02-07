#pragma once

#include "Inimigo.hpp"
#include "Animacoes/Animacao.hpp"
#include "Entidades/Projetil.hpp"
#include "Listas/ListaEntidades.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class Arqueiro : public Inimigo
        {
            private:
                sf::Texture* texturaParado;
                
                Animacoes::Animacao animacao;

                Listas::ListaEntidades* listaProjeteis;
                
                sf::Clock relogio;

            public:
                Arqueiro(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, Jogador* jogador);
                ~Arqueiro();
                void executar();
                void desenhar();

                //Métodos animações
                void atualizarAnimacao(float dt);
                void adicionarAnimacoes();

                //Método atacar
                void atacar();

                void setListaProjeteis(Listas::ListaEntidades* LP);
        };
    }
}