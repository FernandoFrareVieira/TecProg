#pragma once

#include "Entidades/Personagens/Personagem.hpp"
#include "Animacoes/Animacao.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class Jogador : public Personagem
        {
            private:
                Animacoes::Animacao animacao;

                //Atributo pontuação
                static int pontos;
                
                //Atributo para identificar o jogador
                int id;

                //Atributo para inverter corpo
                bool olhandoParaDireita;

            public:
                Jogador(sf::Vector2f pos, sf::Vector2f tam, int idJogador, sf::Vector2f vel = sf::Vector2f(0.0f, 0.0f));
                ~Jogador();
                void executar();
                void desenhar();

                //Métodos de Animação
                void atualizarAnimacao(float dt);
                void adicionarAnimacoes();

                //Métodos movimentação
                void mover();
                void atualizarVelocidadeHorizontal();
                void atualizarVelocidadeVertical();
                void aplicarDesaceleracao(float dt);

                //Métodos colisão
                void colidir(Entidade* entidade2, sf::Vector2f ds);

                //Métodos pontuação
                void ganharPontos(int pts);
                int getPontuacao();
        };
    }
}