#include "Entidades/Personagens/Esqueleto.hpp"

namespace Entidades
{
    namespace Personagens
    {
        Esqueleto::Esqueleto(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, Jogador* jogador):
            Inimigo(pos, tam, vel, jogador, ID::esqueleto),
            animacao(&corpo, 0.1f)
        {
            vivo = true;
            pontosDeVida = 40;
            dano = 10;

            texturaParado = pGG->carregarTextura("assets/esqueletoGuerreiro/Idle.png");

            corpo.setTexture(texturaParado);

            adicionarAnimacoes();
        }

        Esqueleto::~Esqueleto() {}

        void Esqueleto::executar() {
            float dt = pGG->getTempo();

            atualizarAnimacao(dt);
            atualizarAtaque();
            atualizarPosicao();
            desenhar();
            mover();            
        }

        void Esqueleto::desenhar() {
            if(vivo) {
                pGG->desenhar(corpo);
            }
         }

        void Esqueleto::atualizarAnimacao(float dt)
        {
            animacao.atualizar(dt);
        }

        void Esqueleto::adicionarAnimacoes()
        {
            int numFramesParado = 7;
            std::vector<sf::IntRect> framesParado(numFramesParado);
            for (int i = 0; i < numFramesParado; i++)
            {
                framesParado[i] = sf::IntRect(40 + 128 * i, 65, 55, 60);
            }

            animacao.adicionarAnimacao("parado", framesParado);

            animacao.setAnimacao("parado");
        }
    }
}