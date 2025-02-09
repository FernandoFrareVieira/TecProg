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
        animacao(&corpo, 0.1f),
        olhandoParaDireita(true)
        {
            id = idJogador;

            podePular = false;

            vivo = true;
            estaAtacando = false;
            podeAtacar = true;

            tempoDesdeUltimoAtaque = 0.0f;
            olhandoParaDireita = true;

            if (id == 1)
            {
                pontosDeVida = 50;

                tempoAtacarNovamente = 1.5f;
                dano = 20;

                aceleracaoHorizontal = 400.0f;
                desaceleracaoHorizontal = 300.0f;
                velocidadeMaximaHorizontal = 300.0f;

                texturaParado = pGG->carregarTextura("assets/jogador1/andando.png");
                texturaAndando = pGG->carregarTextura("assets/jogador1/correndo.png");
                texturaAtacando = pGG->carregarTextura("assets/jogador1/atacando.png");

                corpo.setTexture(texturaParado);

                tempoAnimacaoAtaque = 0.5f;

                adicionarAnimacoes();
            }
            else
            {
                pontosDeVida = 30;

                tempoAtacarNovamente = 1.5f;
                dano = 20;

                aceleracaoHorizontal = 450.0f;
                desaceleracaoHorizontal = 350.0f;
                velocidadeMaximaHorizontal = 400.0f;

                texturaParado = pGG->carregarTextura("assets/jogador2/Idle.png");
                texturaAndando = pGG->carregarTextura("assets/jogador2/Run.png");
                texturaAtacando = pGG->carregarTextura("assets/jogador2/Attack_1.png");

                tempoAnimacaoAtaque = 0.4f;

                corpo.setTexture(texturaParado);

                adicionarAnimacoes();
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
            std::string animacaoAtual = animacao.getAnimacaoAtual();
            std::string novaAnimacao;
            sf::Texture* textura = nullptr;
            sf::Vector2f tamanhoSprite;
        
            // Configurações específicas para cada jogador com base no id
            if (id == 1) {
                if (estaAtacando) {
                    if (olhandoParaDireita) {
                        novaAnimacao = "atacando";
                    } else {
                        novaAnimacao = "atacandoEsquerda";
                    }
                    textura = texturaAtacando;
                    tamanhoSprite = sf::Vector2f(120.0f, 110.0f); // Tamanho do sprite atacando (Jogador 1)
                } else if (velocidade.x == 0) {
                    if (olhandoParaDireita) {
                        novaAnimacao = "parado";
                    } else {
                        novaAnimacao = "paradoEsquerda";
                    }
                    textura = texturaParado;
                    tamanhoSprite = sf::Vector2f(60.0f, 110.0f); // Tamanho do sprite parado (Jogador 1)
                } else {
                    if (olhandoParaDireita) {
                        novaAnimacao = "andando";
                    } else {
                        novaAnimacao = "andandoEsquerda";
                    }
                    textura = texturaAndando;
                    tamanhoSprite = sf::Vector2f(70.0f, 110.0f); // Tamanho do sprite andando (Jogador 1)
                }
            } else if (id == 2) {
                if (estaAtacando) {
                    if (olhandoParaDireita) {
                        novaAnimacao = "atacando";
                    } else {
                        novaAnimacao = "atacandoEsquerda";
                    }
                    textura = texturaAtacando;
                    tamanhoSprite = sf::Vector2f(100.0f, 100.0f); // Tamanho do sprite atacando (Jogador 2)
                } else if (velocidade.x == 0) {
                    if (olhandoParaDireita) {
                        novaAnimacao = "parado";
                    } else {
                        novaAnimacao = "paradoEsquerda";
                    }
                    textura = texturaParado;
                    tamanhoSprite = sf::Vector2f(40.0f, 100.0f); // Tamanho do sprite parado (Jogador 2)
                } else {
                    if (olhandoParaDireita) {
                        novaAnimacao = "andando";
                    } else {
                        novaAnimacao = "andandoEsquerda";
                    }
                    textura = texturaAndando;
                    tamanhoSprite = sf::Vector2f(70.0f, 100.0f); // Tamanho do sprite andando (Jogador 2)
                }
            }
        
            // Aplica a nova animação, textura e tamanho do sprite, se necessário
            if (animacaoAtual != novaAnimacao) {
                animacao.setAnimacao(novaAnimacao);
                animacao.setTextura(textura);
                corpo.setSize(tamanhoSprite);
            }
        
            // Atualiza a animação
            animacao.atualizar(dt);
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

                //Animacoes olhando para a esquerda

                int numFramesParadoEsquerda = 10;
                std::vector<sf::IntRect> framesParadoEsquerda(numFramesParadoEsquerda);
                for (int i = 0; i < numFramesParadoEsquerda; i++)
                {
                    framesParadoEsquerda[i] = sf::IntRect(35 + 25 + 96 * i, 45, -25, 35);
                }

                int numFramesAndandoEsquerda = 16;
                std::vector<sf::IntRect> framesAndandoEsquerda(numFramesAndandoEsquerda);
                for (int i = 0; i < numFramesAndandoEsquerda; i++)
                {
                    framesAndandoEsquerda[i] = sf::IntRect(35 + 35 + 96 * i, 45, -35, 35);
                }

                //Pula os dois primeiros frames
                int numFramesAtacandoEsquerda = 4;
                std::vector<sf::IntRect> framesAtacandoEsquerda(numFramesAtacandoEsquerda);
                for (int i = 0; i < numFramesAtacandoEsquerda; i++)
                {
                    framesAtacandoEsquerda[i] = sf::IntRect(224 + 55 + 96 * i, 45, -55, 35);
                }

                animacao.adicionarAnimacao("parado", framesParado);
                animacao.adicionarAnimacao("andando", framesAndando);
                animacao.adicionarAnimacao("atacando", framesAtacando);

                animacao.adicionarAnimacao("paradoEsquerda", framesParadoEsquerda);
                animacao.adicionarAnimacao("andandoEsquerda", framesAndandoEsquerda);
                animacao.adicionarAnimacao("atacandoEsquerda", framesAtacandoEsquerda);

                animacao.setAnimacao("parado");
            }else {
                int numFramesParado = 9;
                std::vector<sf::IntRect> framesParado(numFramesParado);
                for (int i = 0; i < numFramesParado; i++)
                {
                    framesParado[i] = sf::IntRect(45 + 128 * i, 58, 30, 70);
                }

                int numFramesAndando = 8;
                std::vector<sf::IntRect> framesAndando(numFramesAndando);
                for (int i = 0; i < numFramesAndando; i++)
                {
                    framesAndando[i] = sf::IntRect(sf::IntRect(40 + 128 * i, 58, 55, 70));
                }

                //Corta os dois ultimos frames
                int numFramesAtacando = 4;
                std::vector<sf::IntRect> framesAtacando(numFramesAtacando);
                for (int i = 0; i < numFramesAtacando; i++)
                {
                    framesAtacando[i] = sf::IntRect(30 + 128 * i, 58, 100, 70);
                }

                int numFramesParadoEsquerda = 9;
                std::vector<sf::IntRect> framesParadoEsquerda(numFramesParadoEsquerda);
                for (int i = 0; i < numFramesParadoEsquerda; i++)
                {
                    framesParadoEsquerda[i] = sf::IntRect(45 + 30 + 128 * i, 58, -30, 70);
                }

                int numFramesAndandoEsquerda = 8;
                std::vector<sf::IntRect> framesAndandoEsquerda(numFramesAndandoEsquerda);
                for (int i = 0; i < numFramesAndandoEsquerda; i++)
                {
                    framesAndandoEsquerda[i] = sf::IntRect(sf::IntRect(40 + 55 + 128 * i, 58, -55, 70));
                }

                //Corta os dois ultimos frames
                int numFramesAtacandoEsquerda = 4;
                std::vector<sf::IntRect> framesAtacandoEsquerda(numFramesAtacandoEsquerda);
                for (int i = 0; i < numFramesAtacandoEsquerda; i++)
                {
                    framesAtacandoEsquerda[i] = sf::IntRect(30 + 55 + 128 * i, 58, -100, 70);
                }
        
                animacao.adicionarAnimacao("parado", framesParado);
                animacao.adicionarAnimacao("andando", framesAndando);
                animacao.adicionarAnimacao("atacando", framesAtacando);

                animacao.adicionarAnimacao("paradoEsquerda", framesParadoEsquerda);
                animacao.adicionarAnimacao("andandoEsquerda", framesAndandoEsquerda);
                animacao.adicionarAnimacao("atacandoEsquerda", framesAtacandoEsquerda);


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

                    if(!olhandoParaDireita)
                        olhandoParaDireita = true;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    velocidade.x -= aceleracaoHorizontal * dt;
                    if (velocidade.x < -velocidadeMaximaHorizontal)
                        velocidade.x = -velocidadeMaximaHorizontal;

                    if(olhandoParaDireita)
                        olhandoParaDireita = false;
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
                    if(!olhandoParaDireita)
                        olhandoParaDireita = true;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    velocidade.x -= aceleracaoHorizontal * dt;
                    if (velocidade.x < -velocidadeMaximaHorizontal)
                        velocidade.x = -velocidadeMaximaHorizontal;

                    if(olhandoParaDireita)
                        olhandoParaDireita = false;
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
            case (ID::esqueleto):
            {
                Personagem *pPersonagem = static_cast<Personagem *>(entidade2);
                if (estaAtacando)
                {
                    pPersonagem->tomarDano(dano);
                    dano = 0;
                }else {
                    dano = 20;
                }

                //colisaoPersonagem(pPersonagem, ds);
            }
            break;

            case (ID::arqueiro):
            {
                Personagem *pPersonagem = static_cast<Personagem *>(entidade2);
                if (estaAtacando)
                {
                    pPersonagem->tomarDano(dano);

                    this->ganharPontos(10);
                    dano = 0;
                }else {
                    dano = 20;
                }

                // colisaoPersonagem(pPersonagem, ds);
            }
            break;

            case(ID::samurai):
            {
                Personagem *pPersonagem = static_cast<Personagem *>(entidade2);
                if (estaAtacando)
                {
                    pPersonagem->tomarDano(dano);

                    this->ganharPontos(10);

                    dano = 0;
                }else {
                    dano = 20;
                }

                //colisaoPersonagem(pPersonagem, ds);
            }
            break;

            case (ID::plataforma):
            {
            }
            break;

            case(ID::projetil):
            {
                sf::Vector2f velocidade = this->getVelocidade();
                if(velocidade.x > 0.0f) {
                    this->setVelocidade(sf::Vector2f(-(velocidade.x - 100.0f), velocidade.y));
                }else {
                    this->setVelocidade(sf::Vector2f(-(velocidade.x + 100.0f), velocidade.y));
                }
            }break;

            default:
            {
            }
            break;
            }
        }

        void Jogador::ganharPontos(int pts)
        {
            pontos = pontos + pts;
        }
        
        int Jogador::getPontuacao()
        {
            return pontos;
        }
    }
}