#include "Entidades/Personagens/Inimigos/Inimigo.hpp"
#include <cmath>

namespace Entidades
{
    namespace Personagens
    {
        namespace Inimigos
        {
            Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, Jogador *jogador, ID identificador): 
            Personagem(pos, tam, vel, identificador)
            {
                pjogador = jogador;
                olhandoParaDireita = false;
            }

            Inimigo::~Inimigo() {}

            void Inimigo::mover() {
                sf::Vector2f posicaoJogador = pjogador->getCorpo()->getPosition();
                sf::Vector2f posicaoInimigo = corpo.getPosition();
                sf::Vector2f movimento(0.0f, 0.0f);

                //Adiciona gravidade
                float dt = pGG->getTempo(); 
                if (!podePular) {
                    velocidade.y += gravidade * dt;
                }

                movimento.y += velocidade.y * dt;
                corpo.move(movimento);            
            }

            void Inimigo::colidir(Entidade* entidade2, sf::Vector2f ds)
            {
                switch(entidade2->getId()) {
                    case(ID::jogador):
                    {       
                        Personagem* pPersonagem = static_cast<Personagem*>(entidade2);             
                        
                        // Verifica se a colisão é no eixo X (ou seja, jogador está à direita ou à esquerda do inimigo)
                        if (ds.x < ds.y) {
                            atacar();
                            if (estaAtacando) {
                                if (this->getId() != ID::arqueiro)
                                    pPersonagem->tomarDano(dano);
                                dano = 0;
                            } else {
                                if (this->getId() == ID::esqueleto) {
                                    dano = 10;
                                } else if (this->getId() == ID::samurai) {
                                    dano = 20;
                                }
                            }
                        }

                        if (!vivo) {
                            Jogador* jogador = static_cast<Jogador*>(entidade2);
                            if (jogador) {
                                if(this->getId() == ID::samurai) {
                                    jogador->ganharPontos(20);
                                }else {
                                    jogador->ganharPontos(10);
                                }
                            }
                        }

                        colisaoPersonagem(pPersonagem, ds);
                    }
                    break;

                    case(ID::plataforma):
                    {
                        // Lógica de colisão com plataforma (se necessário)
                    }
                    break;

                    default:
                    {
                        // Outras interações (se necessário)
                    }
                    break;
                }
            }

            void Inimigo::atualizarLadoOlhando()
            {
                if(pjogador->getCorpo()->getPosition().x <= this->getCorpo()->getPosition().x) {
                    olhandoParaDireita = false;
                }else {
                    olhandoParaDireita = true;
                }
            }
        }
    }
}