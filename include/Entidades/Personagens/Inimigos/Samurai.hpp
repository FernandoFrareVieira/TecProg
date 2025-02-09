#pragma once

#include "Inimigo.hpp"
#include "Animacoes/Animacao.hpp"
#include "Entidades/Projetil.hpp"
#include "Listas/ListaEntidades.hpp"

namespace Entidades
{
    namespace Personagens
    {
        namespace Inimigos
        {
            class Samurai : public Inimigo
            {
                private:                    
                    Animacoes::Animacao animacao;

                    Listas::ListaEntidades* listaProjeteis;
                    
                    sf::Clock relogioAtaque;
                    sf::Clock relogioAnimacao;

                public:
                    Samurai(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, Jogador* jogador);
                    ~Samurai();
                    void executar();
                    void desenhar();

                    //Métodos animações
                    void atualizarAnimacao(float dt);
                    void adicionarAnimacoes();

                    //Método atacar
                    void atacarProjetil();

                    void setListaProjeteis(Listas::ListaEntidades* LP);
            };
        }
    }
}