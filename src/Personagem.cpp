#include "Entidades/Personagens/Personagem.hpp"
#include <iostream>

namespace Entidades
{
    namespace Personagens
    {
        Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, ID identificador):
            Entidade(pos, tam, vel, identificador),
            vivo(true),
            pontosDeVida(100),
            estaAtacando(false),
            podeAtacar(true),
            tempoAtacarNovamente(1.0f),
            tempoDesdeUltimoAtaque(0.0f),
            dano(10),
            podePular(false),
            gravidade(500.0f),
            velocidadePulo(-300.f)
        {}

        Personagem::~Personagem()
        {

        }

        void Personagem::tomarDano(int dano)
        {
            pontosDeVida = pontosDeVida - dano;

            std::cout << pontosDeVida << std::endl;

            if(pontosDeVida <= 0) {
                vivo = false;
            }
        }

        void Personagem::atacar()
        {
            if(podeAtacar) {
                iniciarAtaque();
                podeAtacar = false;
                tempoDesdeUltimoAtaque = 0.0f;
            }
        }

        void Personagem::atualizarAtaque()
        {
            float dt = pGG->getTempo();

            if(!podeAtacar) {
                tempoDesdeUltimoAtaque = tempoDesdeUltimoAtaque + dt;
                if(tempoDesdeUltimoAtaque >= tempoAtacarNovamente) {
                    podeAtacar = true;
                }
                
                if(getId() == ID::jogador) {
                    corpo.setFillColor(sf::Color::Green);
                }else {
                    corpo.setFillColor(sf::Color::Blue);
                }
            }else {
                if(getId() == ID::jogador) {
                    corpo.setFillColor(sf::Color::Red);
                }else {
                    corpo.setFillColor(sf::Color::White);
                }
            }
        }

        void Personagem::iniciarAtaque()
        {
            estaAtacando = true;
        }

        void Personagem::atualizarPosicao()
        {
            float dt = pGG->getTempo(); 

            if (!podePular)
            {
                velocidade.y += gravidade * dt;
            }

            corpo.move(0, velocidade.y * dt);
        }

        void Personagem::pular()
        {
            if (podePular)
            {
                float velocidade_x = getVelocidade().x;
                setVelocidade(sf::Vector2f(velocidade.x, velocidadePulo));
                podePular = false;    
            }
        }

        void Personagem::setPodePular(bool pPular)
        {
            podePular = pPular;
        }
    }
}