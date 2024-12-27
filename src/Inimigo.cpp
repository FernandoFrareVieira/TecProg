#include "Entidades/Personagens/Inimigo.hpp"
#include <cmath>

namespace Entidades
{
    namespace Personagens
    {
        Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, Jogador *jogador, int identificador) : Personagem(pos, tam, vel, identificador)
        {
            pjogador = jogador;
            srand(time(NULL));
            direcaoAleatoria = rand() % 4;
        }

        Inimigo::~Inimigo() {}

        void Inimigo::mover() {
            sf::Vector2f posicaoJogador = pjogador->getCorpo().getPosition();
            sf::Vector2f posicaoInimigo = corpo.getPosition();

            if (fabs(posicaoJogador.x - posicaoInimigo.x) <= DISTANCIA_PERSEGUIR_X && 
                fabs(posicaoJogador.y - posicaoInimigo.y) <= DISTANCIA_PERSEGUIR_Y) {

                float diferencaX = posicaoJogador.x - posicaoInimigo.x;
                float diferencaY = posicaoJogador.y - posicaoInimigo.y;

                sf::Vector2f movimento(0.0f, 0.0f);

                if (fabs(diferencaX) > 0.0f) {
                    movimento.x = (diferencaX > 0.0f ? velocidade.x : -velocidade.x);
                    if (fabs(diferencaX) < fabs(movimento.x)) {
                        movimento.x = diferencaX;
                    }
                }

                if (fabs(diferencaY) > 0.0f) {
                    movimento.y = (diferencaY > 0.0f ? velocidade.y : -velocidade.y);
                    if (fabs(diferencaY) < fabs(movimento.y)) {
                        movimento.y = diferencaY;
                    }
                }

                corpo.move(movimento);
            } else {
                if (direcaoAleatoria == 0) {
                    corpo.move(velocidade.x, 0.0f);
                } else if (direcaoAleatoria == 1) {
                    corpo.move(-velocidade.x, 0.0f);
                } else if (direcaoAleatoria == 2) {
                    corpo.move(0.0f, velocidade.y);
                } else if (direcaoAleatoria == 3) {
                    corpo.move(0.0f, -velocidade.y);
                }
            }

            // Atualiza direção aleatória periodicamente
            float tempoQuePassou = relogio.getElapsedTime().asSeconds();
            if (tempoQuePassou >= 1.0f) {
                direcaoAleatoria = rand() % 4;
                relogio.restart();
            }
        }
    }
}