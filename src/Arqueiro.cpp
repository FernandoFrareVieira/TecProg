#include "Entidades/Personagens/Inimigos/Arqueiro.hpp"

namespace Entidades
{
    namespace Personagens
    {
        namespace Inimigos
        {
            Arqueiro::Arqueiro(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, Jogador* jogador):
            Inimigo(pos, tam, vel, jogador, ID::arqueiro),
            animacao(&corpo, 0.1f),
            listaProjeteis(nullptr)        
            {
                vivo = true;
                pontosDeVida = 20;
                estaAtacando = false;
                podeAtacar = true;
                tempoAtacarNovamente = 2.0f; 
                tempoDesdeUltimoAtaque = 0.0f;
                dano = 0;

                texturaParado = pGG->carregarTextura("assets/arqueiro/Idle.png");
                texturaAtacando = pGG->carregarTextura("assets/arqueiro/Shot_1.png");

                corpo.setTexture(texturaParado);

                adicionarAnimacoes();
            }

            Arqueiro::~Arqueiro() {
                
            }

            void Arqueiro::executar() {
                float dt = pGG->getTempo();

                atualizarAnimacao(dt);
                atualizarPosicao();
                atualizarLadoOlhando();

                atacarProjetil();

                desenhar();
                mover();
            }

            void Arqueiro::desenhar() {
                if(vivo) {
                    pGG->desenhar(corpo);
                }
            }

            void Arqueiro::atualizarAnimacao(float dt) {
                std::string animacaoAtual = animacao.getAnimacaoAtual();
                std::string novaAnimacao;
                sf::Texture* textura = nullptr;
                sf::Vector2f tamanhoSprite;
            
                float tempoDecorrido = relogioAnimacao.getElapsedTime().asSeconds();
            
                if (tempoDecorrido < 1.0f) {
                    if (olhandoParaDireita) {
                        novaAnimacao = "parado";
                    } else {
                        novaAnimacao = "paradoEsquerda";
                    }
                    textura = texturaParado;
                    tamanhoSprite = sf::Vector2f(80.0f, 80.0f);
                } else if (tempoDecorrido < 1.0f + 1.5f) {
                    if (olhandoParaDireita) {
                        novaAnimacao = "atacando";
                    } else {
                        novaAnimacao = "atacandoEsquerda";
                    }
                    textura = texturaAtacando;
                    tamanhoSprite = sf::Vector2f(90.0f, 80.0f);
                } else {
                    relogioAnimacao.restart();
                    return;
                }
            
                if (animacaoAtual != novaAnimacao) {
                    animacao.setAnimacao(novaAnimacao);
                    animacao.setTextura(textura);
                    corpo.setSize(tamanhoSprite);
                }
            
                animacao.atualizar(dt);
            }

            void Arqueiro::adicionarAnimacoes()
            {
                int numFramesParado = 7;
                std::vector<sf::IntRect> framesParado(numFramesParado);
                for (int i = 0; i < numFramesParado; i++)
                {
                    framesParado[i] = sf::IntRect(40 + 128 * i, 65, 45, 60);
                }

                int numFramesAtacando = 15;
                std::vector<sf::IntRect> framesAtacando(numFramesAtacando);

                for (int i = 0; i < numFramesAtacando; i++){
                    framesAtacando[i] = sf::IntRect(30 + 128 * i, 60, 60, 70);
                }

                int numFramesParadoEsquerda = 7;
                std::vector<sf::IntRect> framesParadoEsquerda(numFramesParadoEsquerda);
                for (int i = 0; i < numFramesParadoEsquerda; i++)
                {
                    framesParadoEsquerda[i] = sf::IntRect(40 + 45 + 128 * i, 65, -45, 60);
                }

                int numFramesAtacandoEsquerda = 15;
                std::vector<sf::IntRect> framesAtacandoEsquerda(numFramesAtacandoEsquerda);

                for (int i = 0; i < numFramesAtacandoEsquerda; i++){
                    framesAtacandoEsquerda[i] = sf::IntRect(30 + 60 + 128 * i, 60, -60, 70);
                }

                animacao.adicionarAnimacao("parado", framesParado);
                animacao.adicionarAnimacao("atacando", framesAtacando);

                animacao.adicionarAnimacao("paradoEsquerda", framesParadoEsquerda);
                animacao.adicionarAnimacao("atacandoEsquerda", framesAtacandoEsquerda);

                animacao.setAnimacao("paradoEsquerda");
            }

            void Arqueiro::atacarProjetil()
            {
                float tempoQuePassou = relogioAtaque.getElapsedTime().asSeconds();
            
                if(tempoQuePassou >= 2.5f) {
                    Entidades::Projetil* projetil = new Entidades::Projetil({corpo.getPosition().x - 20, corpo.getPosition().y} ,sf::Vector2f(64.0f, 10.0f), sf::Vector2f(5.0f, 5.0f), olhandoParaDireita);

                    if(listaProjeteis)
                        listaProjeteis->adicionarEntidade(static_cast<Entidades::Entidade*>(projetil));
                    else
                        delete projetil;

                    relogioAtaque.restart();
                }
            }

            void Arqueiro::setListaProjeteis(Listas::ListaEntidades* LP)
            {
                listaProjeteis = LP;
            }
        }
    }
}