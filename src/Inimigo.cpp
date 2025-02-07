#include "Entidades/Personagens/Inimigo.hpp"
#include <cmath>

namespace Entidades
{
    namespace Personagens
    {
        Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, Jogador *jogador, ID identificador): 
            Personagem(pos, tam, vel, identificador)
        {
            pjogador = jogador;
            srand(time(NULL));
            direcaoAleatoria = rand() % 9;
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

            // //Perseguição
            // if (fabs(posicaoJogador.x - posicaoInimigo.x) <= DISTANCIA_PERSEGUIR_X && 
            //     fabs(posicaoJogador.y - posicaoInimigo.y) <= DISTANCIA_PERSEGUIR_Y) {

            //     float diferencaX = posicaoJogador.x - posicaoInimigo.x;
            //     float diferencaY = posicaoJogador.y - posicaoInimigo.y;

            //     if (fabs(diferencaX) > 0.0f) {
            //         movimento.x = (diferencaX > 0.0f ? velocidade.x : -velocidade.x);
            //         if (fabs(diferencaX) < fabs(movimento.x)) {
            //             movimento.x = diferencaX;
            //         }
            //     }

            //     //Apenas altera movimento.y se estiver no chão ou próximo ao jogador
            //     if (podePular) {
            //         movimento.y = (diferencaY > 0.0f ? velocidade.y : -velocidade.y);
            //         if (fabs(diferencaY) < fabs(movimento.y)) {
            //             movimento.y = diferencaY;
            //         }
            //     }

            // } else {
               
            //     //Movimento aleatório
            //     if(direcaoAleatoria == 0 && podePular) {
            //         pular();
            //     }else if(direcaoAleatoria < 5) {
            //         //Move para a direita
            //         movimento.x = velocidade.x;
            //     }else{
            //         //Move para a esquerda
            //         movimento.x = -velocidade.x;
            //     }
            // }

            //Adiciona o efeito da gravidade ao movimento
            movimento.y += velocidade.y * dt;
            corpo.move(movimento);

            //Atualiza direção aleatória
            float tempoQuePassou = relogio.getElapsedTime().asSeconds();
            if (tempoQuePassou >= 1.0f) {
                direcaoAleatoria = rand() % 9;
                relogio.restart();
            }
        }

        void Inimigo::colidir(Entidade* entidade2, sf::Vector2f ds)
        {
            switch(entidade2->getId()) {
                case(ID::jogador):
                {       
                    Personagem* pPersonagem = static_cast<Personagem*>(entidade2);             
                    atacar();
                    if (estaAtacando) {
                        
                        pPersonagem->tomarDano(dano);

                        estaAtacando = false;
                    }

                    //colisaoPersonagem(pPersonagem, ds);
                }
                break;
                case(ID::plataforma):
                {
                    
                }
                break;
                default:
                {
                    
                }
                break;
            }
        }
    }
}