#include "Entidades/Personagens/Jogador.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Entidades/Personagens/Inimigo.hpp"
#include <iostream>

namespace Entidades
{
    namespace Personagens
    {
        int Entidades::Personagens::Jogador::pontos = 0;

        Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, int idJogador, sf::Vector2f vel): 
            Personagem(pos, tam, vel, ID::jogador), 
            animacao(corpo, 0.2f)
        {
            id = idJogador;

            vivo = true;
            estaAtacando = false;
            podeAtacar = true;

            tempoDesdeUltimoAtaque = 0.0f;
        
            if(id == 1) {
                pontosDeVida = 100;

                tempoAtacarNovamente = 2.0f; 
                dano = 10;

                aceleracaoHorizontal = 400.0f;
                desaceleracaoHorizontal = 300.0f;
                velocidadeMaximaHorizontal= 300.0f;

                corpo.setFillColor(sf::Color::Red);
            }else {
                pontosDeVida = 70;

                tempoAtacarNovamente = 1.0f; 
                dano = 20;

                aceleracaoHorizontal = 450.0f;
                desaceleracaoHorizontal = 350.0f;
                velocidadeMaximaHorizontal= 400.0f;

                corpo.setFillColor(sf::Color::Black);
            }

            //textura = pGG->carregarTextura("assets/jogador/andando.png"); 
            //corpo.setSize(sf::Vector2f(LARGURA/30.0f,ALTURA/7.5f));
            //corpo.setTextureRect(sf::IntRect(40,48,15,33));
            //corpo.setTexture(textura);
        }

        Jogador::~Jogador()
        {
        }

        void Jogador::executar()
        {
            atualizarPosicao();
            atualizarAtaque();
            
            desenhar();
            mover();
            if (this->getPosicao().y > 1090)
                vivo = false;
        }

        void Jogador::desenhar()
        {
            if (vivo)
                pGG->desenhar(corpo);
        }

        void Jogador::atualizarAnimacao(float dt)
        {
            
        }

        void Jogador::mover()
        {
            float dt = pGG->getTempo(); // Tempo entre frames

            if(id == 1) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
                    velocidade.x += aceleracaoHorizontal * dt;
                    if (velocidade.x > velocidadeMaximaHorizontal)
                        velocidade.x = velocidadeMaximaHorizontal;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    velocidade.x -= aceleracaoHorizontal * dt;
                    if (velocidade.x < -velocidadeMaximaHorizontal)
                        velocidade.x = -velocidadeMaximaHorizontal;
                } else {
                    if (velocidade.x > 0.0f) {
                        velocidade.x -= desaceleracaoHorizontal * dt;
                        if (velocidade.x < 0.0f)
                            velocidade.x = 0.0f;
                    } else if (velocidade.x < 0.0f) {
                        velocidade.x += desaceleracaoHorizontal * dt;
                        if (velocidade.x > 0.0f)
                            velocidade.x = 0.0f;
                    }
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    pular();
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    atacar();
                }
            }else {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    velocidade.x += aceleracaoHorizontal * dt;
                    if (velocidade.x > velocidadeMaximaHorizontal)
                        velocidade.x = velocidadeMaximaHorizontal;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                        velocidade.x -= aceleracaoHorizontal * dt;
                        if (velocidade.x < -velocidadeMaximaHorizontal)
                            velocidade.x = -velocidadeMaximaHorizontal;
                } else {
                    if (velocidade.x > 0.0f) {
                        velocidade.x -= desaceleracaoHorizontal * dt;
                        if (velocidade.x < 0.0f)
                            velocidade.x = 0.0f;
                    } else if (velocidade.x < 0.0f) {
                        velocidade.x += desaceleracaoHorizontal * dt;
                        if (velocidade.x > 0.0f)
                            velocidade.x = 0.0f;
                    }
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    pular();
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  {
                    atacar();
                }
            }
        }

        void Jogador::colidir(Entidade *entidade2, sf::Vector2f ds)
        {
            switch (entidade2->getId())
            {
            case (ID::inimigo):
            {
                Personagem* pPersonagem = static_cast<Personagem*>(entidade2);
                if (estaAtacando) {
                    pPersonagem->tomarDano(dano);

                    this->ganharPontos(10);
                    estaAtacando = false;
                }

                //colisaoPersonagem(pPersonagem, ds);
            }
            break;

            case (ID::obstaculo):
            {
               
            }
            break;

            default:
            {
            }
            break;
            }
        }

        void Jogador::ganharPontos(int pts)
        {
            pontos = pontos + pts;
            
            std::cout << pontos << std::endl;
        }

        void Jogador::perderPontos(int pts)
        {
            pontos = pontos - pts;
            if(pontos < 0) {
                pontos = 0;
            }

            std::cout << pontos << std::endl;
        }

        int Jogador::getPontuacao()
        {
            return pontos;
        }
    }
}
