#pragma once

#include <iostream>

#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "SFML/Graphics.hpp"

namespace Animacoes
{
    enum ID_animacao
    {   
        andando = 0,
        correndo = 1,
        atacando = 2,
    };

    class Animacao
    {
        private:
            class FrameAtual
            {
                private:
                    int quantidadeImagens;
                    int imagemAtual;
                    sf::IntRect tamanhoImagem;
                    sf::Texture* textura;
                    float tempoTotal;
                    static float tempoDeTroca;
                public:
                    FrameAtual(const char* caminho, int quantImagens):
                        quantidadeImagens(quantImagens),
                        imagemAtual(0),
                        textura(pGG->carregarTextura(caminho)),
                        tempoTotal(0.0f)
                    {
                        if(textura == nullptr) {
                            std::cout << "Erro ao carregar textura" << std::endl;
                            exit(1);
                        }
                        tamanhoImagem.width = textura->getSize().x / float(quantidadeImagens);
                        tamanhoImagem.height = textura->getSize().y;
                    }
                    ~FrameAtual() {}

                    void atualizar(float variacaoTempo, bool paraEsquerda) 
                    {
                        tempoTotal += variacaoTempo;
                        if(tempoTotal >= tempoDeTroca) {
                            tempoTotal -= tempoDeTroca;
                            imagemAtual = imagemAtual + 1;

                            if(imagemAtual >= quantidadeImagens) {
                                imagemAtual = 0;
                            }
                        }

                        if(paraEsquerda) {
                            tamanhoImagem.left = (imagemAtual + 1) * abs(tamanhoImagem.width);
                            tamanhoImagem.width = -abs(tamanhoImagem.width);
                        }else {
                            tamanhoImagem.left = imagemAtual * tamanhoImagem.width;
                            tamanhoImagem.width = abs(tamanhoImagem.width);
                        }
                    }

                    void reiniciar() 
                    {
                        imagemAtual = 0;
                        tempoTotal = 0;
                    }

                    sf::IntRect getTamanho()
                    {
                        return tamanhoImagem;
                    }

                    sf::Texture* getTextura()
                    {
                        return textura;
                    }

            };

        private:
            sf::RectangleShape* corpo;
            std::map<ID_animacao, FrameAtual*> animacaoMap;
            ID_animacao ID_atual;

            static Gerenciadores::GerenciadorGrafico* pGG;

        public:
            Animacao(sf::RectangleShape* pCorpo);
            ~Animacao();
            void adicionarAnimacao(ID_animacao id, const char* caminho, int quantImagens);
            void atualizar(ID_animacao id, bool estaParaEsquerda, sf::Vector2f posicao, float variacaoTempo);
            void renderizar();
    };
}