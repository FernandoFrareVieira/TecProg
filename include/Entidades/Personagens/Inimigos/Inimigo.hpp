#pragma once

#include "Entidades/Personagens/Personagem.hpp"
#include "Entidades/Personagens/Jogador.hpp"

#define DISTANCIA_PERSEGUIR_X 200.0f
#define DISTANCIA_PERSEGUIR_Y 200.0f

namespace Entidades
{
    namespace Personagens
    {
        namespace Inimigos
        {
            class Inimigo : public Personagem
            {
                protected:
                    Jogador* pjogador;
                    int dano;
                private:
                    int direcaoAleatoria;
                    sf::Clock relogio;

                public:
                    Inimigo(sf::Vector2f pos, sf::Vector2f tam , sf::Vector2f vel, Jogador* jogador, ID identificador);
                    ~Inimigo();
                    virtual void executar() = 0;
                    virtual void desenhar() = 0;
                    void mover();

                    void colidir(Entidade* entidade2, sf::Vector2f ds);

                    virtual void adicionarAnimacoes() = 0;
                    virtual void atualizarAnimacao(float dt) = 0;

                    void atualizarLadoOlhando();
            };
        }
    }
}