#include "Entidades/Personagens/Personagem.hpp"
#include "Entidades/Personagens/Jogador.hpp"
#include "Entidades/Personagens/Inimigo.hpp"
#include <iostream>

namespace Entidades
{
    namespace Personagens
    {
        Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, ID identificador):
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
            velocidadePulo(-470.0f)
        {}

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

            sf::Vector2f novaVelocidade = velocidade;
            sf::Vector2f novaVelocidadeEntidade = velocidadeEntidade;

            if (ds.x < ds.y) {
                // Colisão horizontal
                if (posicaoEntidade.x < posicao.x) {
                    // O objeto colidido está à esquerda
                    corpo.setPosition(posicaoEntidade.x + tamanhoEntidade.x, posicao.y);
                } else {
                    // O objeto colidido está à direita
                    corpo.setPosition(posicaoEntidade.x - tamanho.x, posicao.y);
                }
                novaVelocidade.x = 0.0f;

            } else {
                // Colisão vertical
                if (posicaoEntidade.y < posicao.y) {
                    // O objeto colidido está acima
                    corpo.setPosition(posicao.x, posicaoEntidade.y + tamanhoEntidade.y);
                    novaVelocidade.y = 0.0f;
                } else {
                    // O objeto colidido está abaixo
                    corpo.setPosition(posicao.x, posicaoEntidade.y - tamanho.y);
                    novaVelocidade.y = 0.0f;

                    // Permitir pulo, pois está no chão
                    setPodePular(true);
                }
            } 

            // Apenas atualiza a velocidade do objeto atual
            setVelocidade(novaVelocidade);
            pPersonagem->setVelocidade(novaVelocidade);
        }

        void Personagem::tomarDano(int dano)
        {
            pontosDeVida = pontosDeVida - dano;

            if(pontosDeVida <= 0) {
                vivo = false;
            }

            std::cout << "Pontos de vida: " << pontosDeVida << std::endl;

            if(this->getId() == ID::jogador) {
                sf::Vector2f velocidade = this->getVelocidade();
                this->setVelocidade(sf::Vector2f(-abs(velocidade.x - 100.0f), velocidade.y));
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

                if(estaAtacando && tempoDesdeUltimoAtaque >= 0.5f) {
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