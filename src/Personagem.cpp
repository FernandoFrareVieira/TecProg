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
            sf::Vector2f posicao = corpo.getPosition();
            sf::Vector2f tamanho = corpo.getSize();

            sf::Vector2f posicaoEntidade = pPersonagem->getCorpo()->getPosition();
            sf::Vector2f tamanhoEntidade = pPersonagem->getCorpo()->getSize();
            sf::Vector2f velocidadeEntidade = pPersonagem->getVelocidade();

            sf::Vector2f novaVelocidadeEntidade = velocidadeEntidade;

            if (ds.x < ds.y) {
                if (posicaoEntidade.x < posicao.x) {
                    // pPersonagem está à esquerda do personagem atual
                    pPersonagem->getCorpo()->setPosition(
                        posicao.x - tamanhoEntidade.x,
                        posicaoEntidade.y
                    );

                    novaVelocidadeEntidade.x = 0.0f;
                } else {
                    // pPersonagem está à direita do personagem atual
                    pPersonagem->getCorpo()->setPosition(
                        posicao.x + tamanho.x,
                        posicaoEntidade.y
                    );

                    novaVelocidadeEntidade.x = 0.0f;
                }
            } else {
                if (posicaoEntidade.y < posicao.y) {
                    // pPersonagem está acima do personagem atual
                    pPersonagem->getCorpo()->setPosition(
                        posicaoEntidade.x,
                        posicao.y - tamanhoEntidade.y
                    );

                    pPersonagem->setPodePular(true);
                } else {
                    // pPersonagem está abaixo do personagem atual
                    pPersonagem->getCorpo()->setPosition(
                        posicaoEntidade.x,
                        posicao.y + tamanho.y
                    );
                }
            }
        }

        void Personagem::tomarDano(int dano)
        {
            pontosDeVida = pontosDeVida - dano;

            if (pontosDeVida <= 0)
            {
                vivo = false;
            }

            std::cout << "Pontos de vida: " << pontosDeVida << std::endl;
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