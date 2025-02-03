#include "Entidades/Personagens/Esqueleto.hpp"

namespace Entidades
{
    namespace Personagens
    {
        Esqueleto::Esqueleto(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, Jogador* jogador):
            Inimigo(pos, tam, vel, jogador)
        {
            vivo = true;
            pontosDeVida = 20;
            estaAtacando = false;
            podeAtacar = true;
            tempoAtacarNovamente = 2.0f; 
            tempoDesdeUltimoAtaque = 0.0f;
            dano = 10;

            corpo.setFillColor(sf::Color::White);

            //textura = pGG->carregarTextura("assets/inimigos/esqueleto.png");
            //corpo.setTextureRect(sf::IntRect(10,15,32,30));
            //corpo.setSize(sf::Vector2f(LARGURA/17.0f,ALTURA/7.50f));
            //corpo.setTexture(textura);    
        }

        Esqueleto::~Esqueleto() {}

        void Esqueleto::executar() {
            atualizarPosicao();
            atualizarAtaque();
            desenhar();
            mover();
        }

        void Esqueleto::desenhar() {
            if(vivo) {
                pGG->desenhar(corpo);
            }
            
         }
    }
}