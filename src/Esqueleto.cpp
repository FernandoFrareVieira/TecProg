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

            olhandoParaDireita = false;

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
            atualizarLadoOlhando();

            desenhar();
            mover();            
        }

        void Esqueleto::desenhar() {
            if(vivo) {
                pGG->desenhar(corpo);
            }
         }

         void Esqueleto::atualizarAnimacao(float dt) {
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
                    tamanhoSprite = sf::Vector2f(80.0f, 80.0f); 
                } else {
                    if (olhandoParaDireita) {
                        novaAnimacao = "andando";
                    } else {
                        novaAnimacao = "andandoEsquerda";
                    }
                    textura = texturaAndando;
                    tamanhoSprite = sf::Vector2f(80.0f, 80.0f); 
                }
            } else {
                if (olhandoParaDireita) {
                    novaAnimacao = "atacando";
                } else {
                    novaAnimacao = "atacandoEsquerda";
                }
                textura = texturaAtacando;
                tamanhoSprite = sf::Vector2f(110.0f, 100.0f); 
            }
        
            if (animacaoAtual != novaAnimacao) {
                animacao.setAnimacao(novaAnimacao);
                animacao.setTextura(textura);
                corpo.setSize(tamanhoSprite);
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

            int numFramesParadoEsquerda = 7;
            std::vector<sf::IntRect> framesParadoEsquerda(numFramesParadoEsquerda);
            for (int i = 0; i < numFramesParadoEsquerda; i++)
            {
                framesParadoEsquerda[i] = sf::IntRect(40 + 55 + 128 * i, 65, -55, 60);
            }

            int numFramesAndandoEsquerda = 7;
            std::vector<sf::IntRect> framesAndandoEsquerda(numFramesAndandoEsquerda);

            for (int i = 0; i < numFramesAndandoEsquerda; i++) {
                framesAndandoEsquerda[i] = sf::IntRect(35 + 35 + 96 * i, 45, -35, 35);
            }
            
            int numFramesAtacandoEsquerda = 4;
            std::vector<sf::IntRect> framesAtacandoEsquerda(numFramesAtacandoEsquerda);

            for (int i = 0; i < numFramesAtacandoEsquerda; i++){
                framesAtacandoEsquerda[i] = sf::IntRect(30 + 70 + 128 * i, 45, -70, 80);
            }

            animacao.adicionarAnimacao("parado", framesParado);
            animacao.adicionarAnimacao("andando", framesAndando);
            animacao.adicionarAnimacao("atacando", framesAtacando);

            animacao.adicionarAnimacao("paradoEsquerda", framesParadoEsquerda);
            animacao.adicionarAnimacao("andandoEsquerda", framesAndandoEsquerda);
            animacao.adicionarAnimacao("atacandoEsquerda", framesAtacandoEsquerda);

            animacao.setAnimacao("paradoEsquerda");
        }
    }
}