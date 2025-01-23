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
                sf::Texture* textura;

                Animacoes::Animacao animacao;

                //Atributo pontuação
                static int pontos;

            public:
                Jogador(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel = sf::Vector2f(0.0f, 0.0f));
                ~Jogador();
                void executar();
                void desenhar();

                //Métodos de Animação
                void atualizarAnimacao(float dt);

                //Métodos movimetação e colisão
                void mover();
                void colidir(Entidade* entidade2, sf::Vector2f ds);

                //Métodos pontuação
                void ganharPontos(int pts);
                void perderPontos(int pts);
                int getPontuacao();
        };
    }
}