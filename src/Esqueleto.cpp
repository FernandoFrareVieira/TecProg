#include "Entidades/Personagens/Esqueleto.hpp"

namespace Entidades
{
    namespace Personagens
    {
        Esqueleto::Esqueleto(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, Jogador* jogador):
            Inimigo(pos, tam, vel, jogador, ID::esqueleto),
            animacao(&corpo, 0.1f)
        {
            vivo = true;
            pontosDeVida = 40;
            dano = 10;

            tempoAtacarNovamente = 1.5f;

            tempoAnimacaoAtaque = 0.4f;

            texturaParado = pGG->carregarTextura("assets/esqueletoGuerreiro/Idle.png");
            texturaAndando = pGG->carregarTextura("assets/esqueletoGuerreiro/Walk.png");
            texturaAtacando = pGG->carregarTextura("assets/esqueletoGuerreiro/Attack_3.png");

            corpo.setTexture(texturaParado);

            adicionarAnimacoes();
        }

        Esqueleto::~Esqueleto() {}

        void Esqueleto::executar() {
            float dt = pGG->getTempo();

            atualizarAnimacao(dt);
            atualizarAtaque();
            atualizarPosicao();
            desenhar();
            mover();            
        }

        void Esqueleto::desenhar() {
            if(vivo) {
                pGG->desenhar(corpo);
            }
         }

        void Esqueleto::atualizarAnimacao(float dt)
        {
            if(!estaAtacando) {
                if(velocidade.x == 0) {
                    if (animacao.getAnimacaoAtual() != "parado") { 
                        animacao.setTextura(texturaParado);
                        animacao.setAnimacao("parado");

                        corpo.setSize(sf::Vector2f(80.0f, 80.0f));
                    }
                }else {
                    if(animacao.getAnimacaoAtual() != "andando") {
                        animacao.setTextura(texturaAndando);
                        animacao.setAnimacao("andando");

                        corpo.setSize(sf::Vector2f(80.0f, 80.0f));
                    }
                }
            }else {
                if(animacao.getAnimacaoAtual() != "atacando" && podePular) {
                    animacao.setTextura(texturaAtacando);
                    animacao.setAnimacao("atacando");

                    corpo.setSize(sf::Vector2f(110.0f, 100.0f));
                }
            }

            animacao.atualizar(dt);
        }

        void Esqueleto::adicionarAnimacoes()
        {
            int numFramesParado = 7;
            std::vector<sf::IntRect> framesParado(numFramesParado);
            for (int i = 0; i < numFramesParado; i++)
            {
                framesParado[i] = sf::IntRect(40 + 128 * i, 65, 55, 60);
            }

            int numFramesAndando = 7;
            std::vector<sf::IntRect> framesAndando(numFramesAndando);

            for (int i = 0; i < numFramesAndando; i++) {
                framesAndando[i] = sf::IntRect(35 + 96 * i, 45, 35, 35);
            }
            
            int numFramesAtacando = 4;
            std::vector<sf::IntRect> framesAtacando(numFramesAtacando);

            for (int i = 0; i < numFramesAtacando; i++){
                framesAtacando[i] = sf::IntRect(30 + 128 * i, 45, 70, 80);
            }

            animacao.adicionarAnimacao("parado", framesParado);
            animacao.adicionarAnimacao("andando", framesAndando);
            animacao.adicionarAnimacao("atacando", framesAtacando);

            animacao.setAnimacao("parado");
        }
    }
}