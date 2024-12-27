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
                sf::Texture* textura;

                Animacoes::Animacao animacao;
            public:
                Jogador(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f velocidade);
                ~Jogador();
                void executar();
                void desenhar();
                void atualizar(float dt);
                void mover(sf::Keyboard::Key tecla);
        };
    }
}