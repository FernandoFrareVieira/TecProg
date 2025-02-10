#include "Entidades/Personagens/Inimigos/Samurai.hpp"

namespace Entidades
{
    namespace Personagens
    {
        namespace Inimigos
        {
            Samurai::Samurai(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, Jogador* jogador):
            Inimigo(pos, tam, vel, jogador, ID::samurai),
            animacao(&corpo, 0.1f),
            listaProjeteis(nullptr)        
            {
                vivo = true;

                pontosDeVida = 40;
                dano = 20;
                
                estaAtacando = false;
                podeAtacar = true;
                tempoAtacarNovamente = 2.0f; 
                tempoDesdeUltimoAtaque = 0.0f;

                tempoAnimacaoAtaque = 0.6f;

                olhandoParaDireita = false;

                texturaParado = pGG->carregarTextura("assets/samurai/Idle.png");
                texturaAtacando = pGG->carregarTextura("assets/samurai/Attack_1.png");

                corpo.setTexture(texturaParado);

                adicionarAnimacoes();
            }

            Samurai::~Samurai() {
                
            }

            void Samurai::executar() {
                float dt = pGG->getTempo();

                atualizarAnimacao(dt);
                atualizarPosicao();
                atualizarAtaque();
                atualizarLadoOlhando();

                desenhar();
                mover();
            }

            void Samurai::desenhar() {
                if(vivo) {
                    pGG->desenhar(corpo);
                }
            }

            void Samurai::atualizarAnimacao(float dt)
            {
                std::string animacaoAtual = animacao.getAnimacaoAtual();
                std::string novaAnimacao;
                sf::Texture* textura = nullptr;
                sf::Vector2f tamanhoSprite;
            
                if (!estaAtacando) {
                    if (velocidade.x == 0) {
                        if (olhandoParaDireita) {
                            novaAnimacao = "parado";
                        } else {
                            novaAnimacao = "paradoEsquerda";
                        }
                        textura = texturaParado;
                        tamanhoSprite = sf::Vector2f(50.0f, 100.0f); 
                    }
                } else {
                    if (olhandoParaDireita) {
                        novaAnimacao = "atacando";
                    } else {
                        novaAnimacao = "atacandoEsquerda";
                    }
                    textura = texturaAtacando;
                    tamanhoSprite = sf::Vector2f(100.0f, 100.0f); 
                }
            
                if (animacaoAtual != novaAnimacao) {
                    animacao.setAnimacao(novaAnimacao);
                    animacao.setTextura(textura);
                    corpo.setSize(tamanhoSprite);
                }
            
                animacao.atualizar(dt);
            }

            void Samurai::adicionarAnimacoes()
            {
                int numFramesParado = 9;
                std::vector<sf::IntRect> framesParado(numFramesParado);
                for (int i = 0; i < numFramesParado; i++) {
                    framesParado[i] = sf::IntRect(40 + 128 * i, 20, 40, 108);

                }

                int numFramesAtacando = 5;
                std::vector<sf::IntRect> framesAtacando(numFramesAtacando);

                for (int i = 0; i < numFramesAtacando; i++){
                    framesAtacando[i] = sf::IntRect(35 + 128 * i, 20, 90, 108);
                }

                int numFramesParadoEsquerda = 9;
                std::vector<sf::IntRect> framesParadoEsquerda(numFramesParadoEsquerda);
                for (int i = 0; i < numFramesParadoEsquerda; i++) {
                    framesParadoEsquerda[i] = sf::IntRect(40 + 40 + 128 * i, 20, -40, 108);

                }

                int numFramesAtacandoEsquerda = 5;
                std::vector<sf::IntRect> framesAtacandoEsquerda(numFramesAtacandoEsquerda);

                for (int i = 0; i < numFramesAtacandoEsquerda; i++){
                    framesAtacandoEsquerda[i] = sf::IntRect(35 + 90 + 128 * i, 20, -90, 108);
                }

                animacao.adicionarAnimacao("parado", framesParado);
                animacao.adicionarAnimacao("atacando", framesAtacando);

                animacao.adicionarAnimacao("paradoEsquerda", framesParadoEsquerda);
                animacao.adicionarAnimacao("atacandoEsquerda", framesAtacandoEsquerda);

                animacao.setAnimacao("paradoEsquerda");
            }

            void Samurai::setListaProjeteis(Listas::ListaEntidades* LP)
            {
                listaProjeteis = LP;
            }
        }
    }
}