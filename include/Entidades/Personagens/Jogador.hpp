#pragma once

#include "Personagem.hpp"
#include "Animacoes/Animacao.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class Jogador : public Personagem
        {
            private:
                int pontos;
                int dano;
                sf::Texture* textura;

                Animacoes::Animacao animacao;
            public:
                Jogador(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel = sf::Vector2f(0.0f, 0.0f));
                ~Jogador();
                void executar();
                void desenhar();

                // Métodos de Animação
                void atualizarAnimacao(float dt);

                //Métodos movimetação e colisão
                void mover();
                void colidir(Entidade* entidade2, sf::Vector2f ds);
        };
    }
}