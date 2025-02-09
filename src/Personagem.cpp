#include "Entidades/Personagens/Personagem.hpp"
#include "Entidades/Personagens/Jogador.hpp"
#include "Entidades/Personagens/Inimigos/Inimigo.hpp"
#include <iostream>

namespace Entidades
{
    namespace Personagens
    {
        Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, ID identificador) : 
            Entidade(pos, tam, vel, identificador),
            pontosDeVida(100),
            estaAtacando(false),
            podeAtacar(true),
            tempoAtacarNovamente(1.0f),
            tempoDesdeUltimoAtaque(0.0f),
            dano(10),
            aceleracaoHorizontal(400.0f),
            desaceleracaoHorizontal(300.0f),
            velocidadeMaximaHorizontal(350.0f),
            velocidadePulo(-470.0f),
            texturaParado(nullptr),
            texturaAndando(nullptr),
            texturaAtacando(nullptr),
            tempoAnimacaoAtaque(0.5f),
            olhandoParaDireita(true)
        {
        }

        Personagem::~Personagem()
        {
        }

        void Personagem::colisaoPersonagem(Personagem* pPersonagem, sf::Vector2f ds) 
        {
            
        }

        void Personagem::tomarDano(int dano)
        {
            pontosDeVida = pontosDeVida - dano;

            if (pontosDeVida <= 0)
            {
                vivo = false;
            }

            std::cout << "Pontos de vida: " << pontosDeVida << std::endl;

            // if (this->getId() == ID::jogador)
            // {
            //     sf::Vector2f velocidade = this->getVelocidade();
            //     if(velocidade.x > 0.0f) {
            //         this->setVelocidade(sf::Vector2f(-(velocidade.x - 100.0f), velocidade.y));
            //     }else {
            //         this->setVelocidade(sf::Vector2f(-(velocidade.x + 100.0f), velocidade.y));
            //     }
            // }
        }

        void Personagem::atacar()
        {
            if (podeAtacar)
            {
                iniciarAtaque();
                podeAtacar = false;
                tempoDesdeUltimoAtaque = 0.0f;
            }
        }

        void Personagem::atualizarAtaque()
        {
            float dt = pGG->getTempo();

            if (!podeAtacar)
            {
                tempoDesdeUltimoAtaque = tempoDesdeUltimoAtaque + dt;
                if (tempoDesdeUltimoAtaque >= tempoAtacarNovamente)
                {
                    podeAtacar = true;
                }

                if (estaAtacando && tempoDesdeUltimoAtaque >= tempoAnimacaoAtaque)
                {
                    estaAtacando = false;
                }
            }
        }

        void Personagem::iniciarAtaque()
        {
            estaAtacando = true;
        }

        int Personagem::getPontosDeVida()
        {
            return pontosDeVida;
        }

        void Personagem::setPontosDeVida(int vida)
        {
            pontosDeVida = vida;
        }

        void Personagem::pular()
        {
            if (podePular)
            {
                float dt = pGG->getTempo();

                velocidade.y = velocidadePulo;
                corpo.move(0.0f, velocidade.y * dt);
                podePular = false;
            }
        }
    }
}