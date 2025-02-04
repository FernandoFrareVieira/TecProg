#include "Entidades/Personagens/Jogador.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Entidades/Personagens/Inimigo.hpp"
#include <iostream>

namespace Entidades
{
    namespace Personagens
    {
        int Entidades::Personagens::Jogador::pontos = 0;

        Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, int idJogador, sf::Vector2f vel) : 
        Personagem(pos, tam, vel, ID::jogador),
        animacao(&corpo, 0.1f)
        {
            id = idJogador;

            vivo = true;
            estaAtacando = false;
            podeAtacar = true;

            tempoDesdeUltimoAtaque = 0.0f;

            if (id == 1)
            {
                pontosDeVida = 50;

                tempoAtacarNovamente = 2.0f;
                dano = 10;

                aceleracaoHorizontal = 400.0f;
                desaceleracaoHorizontal = 300.0f;
                velocidadeMaximaHorizontal = 300.0f;

                texturaParado = pGG->carregarTextura("assets/jogador1/andando.png");
                texturaAndando = pGG->carregarTextura("assets/jogador1/correndo.png");
                texturaAtacando = pGG->carregarTextura("assets/jogador1/atacando.png");

                corpo.setTexture(texturaParado);

                adicionarAnimacoes();
            }
            else
            {
                pontosDeVida = 30;

                tempoAtacarNovamente = 1.0f;
                dano = 20;

                aceleracaoHorizontal = 450.0f;
                desaceleracaoHorizontal = 350.0f;
                velocidadeMaximaHorizontal = 400.0f;

                texturaParado = pGG->carregarTextura("assets/jogador2/Idle.png");
                corpo.setSize(sf::Vector2f(128.0f, 128.0f));
                corpo.setTextureRect(sf::IntRect(0, 0, 128, 128));
                corpo.setTexture(texturaParado);
            }
        }

        Jogador::~Jogador()
        {
        }

        void Jogador::executar()
        {
            float dt = pGG->getTempo();

            atualizarPosicao();
            atualizarAtaque();
            atualizarAnimacao(dt);

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

        void Jogador::atualizarAnimacao(float dt) {
        if (id == 1) {
            if(!estaAtacando) {
                if (velocidade.x == 0) {
                    if (animacao.getAnimacaoAtual() != "parado") { 
                        animacao.setTextura(texturaParado);
                        animacao.setAnimacao("parado");
                        corpo.setSize(sf::Vector2f(40.0f, 80.0f));
                    }
                } else{
                    if (animacao.getAnimacaoAtual() != "andando") { 
                        animacao.setTextura(texturaAndando);
                        animacao.setAnimacao("andando");
                        corpo.setSize(sf::Vector2f(50.0f, 80.0f));
                    }
                }
            }else {
                if(animacao.getAnimacaoAtual() != "atacando" && podePular) {
                    animacao.setTextura(texturaAtacando);
                    animacao.setAnimacao("atacando");
                    corpo.setSize(sf::Vector2f(80.0f, 80.0f));
                }
            }

            animacao.atualizar(dt);
        }
    }

        void Jogador::adicionarAnimacoes()
        {
            if (id == 1)
            {
                int numFramesParado = 10;
                std::vector<sf::IntRect> framesParado(numFramesParado);
                for (int i = 0; i < numFramesParado; i++)
                {
                    framesParado[i] = sf::IntRect(35 + 96 * i, 45, 25, 35);
                }

                int numFramesAndando = 16;
                std::vector<sf::IntRect> framesAndando(numFramesAndando);
                for (int i = 0; i < numFramesAndando; i++)
                {
                    framesAndando[i] = sf::IntRect(35 + 96 * i, 45, 35, 35);
                }

                //Pula os dois primeiros frames
                int numFramesAtacando = 4;
                std::vector<sf::IntRect> framesAtacando(numFramesAtacando);
                for (int i = 0; i < numFramesAtacando; i++)
                {
                    framesAtacando[i] = sf::IntRect(224 + 96 * i, 45, 55, 35);
                }

                animacao.adicionarAnimacao("parado", framesParado);
                animacao.adicionarAnimacao("andando", framesAndando);
                animacao.adicionarAnimacao("atacando", framesAtacando);

                animacao.setAnimacao("parado");
            }
        }

        void Jogador::mover()
        {
            float dt = pGG->getTempo();

            if (id == 1)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    velocidade.x += aceleracaoHorizontal * dt;
                    if (velocidade.x > velocidadeMaximaHorizontal)
                        velocidade.x = velocidadeMaximaHorizontal;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    velocidade.x -= aceleracaoHorizontal * dt;
                    if (velocidade.x < -velocidadeMaximaHorizontal)
                        velocidade.x = -velocidadeMaximaHorizontal;
                }
                else
                {
                    if (velocidade.x > 0.0f)
                    {
                        velocidade.x -= desaceleracaoHorizontal * dt;
                        if (velocidade.x < 0.0f)
                            velocidade.x = 0.0f;
                    }
                    else if (velocidade.x < 0.0f)
                    {
                        velocidade.x += desaceleracaoHorizontal * dt;
                        if (velocidade.x > 0.0f)
                            velocidade.x = 0.0f;
                    }
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    pular();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    atacar();
                }
            }
            else
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    velocidade.x += aceleracaoHorizontal * dt;
                    if (velocidade.x > velocidadeMaximaHorizontal)
                        velocidade.x = velocidadeMaximaHorizontal;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    velocidade.x -= aceleracaoHorizontal * dt;
                    if (velocidade.x < -velocidadeMaximaHorizontal)
                        velocidade.x = -velocidadeMaximaHorizontal;
                }
                else
                {
                    if (velocidade.x > 0.0f)
                    {
                        velocidade.x -= desaceleracaoHorizontal * dt;
                        if (velocidade.x < 0.0f)
                            velocidade.x = 0.0f;
                    }
                    else if (velocidade.x < 0.0f)
                    {
                        velocidade.x += desaceleracaoHorizontal * dt;
                        if (velocidade.x > 0.0f)
                            velocidade.x = 0.0f;
                    }
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    pular();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
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
                Personagem *pPersonagem = static_cast<Personagem *>(entidade2);
                if (estaAtacando)
                {
                    pPersonagem->tomarDano(dano);

                    this->ganharPontos(10);
                }

                // colisaoPersonagem(pPersonagem, ds);
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
            if (pontos < 0)
            {
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