#pragma once

#include "Entidades/Entidade.hpp"

namespace Entidades
{
    namespace Personagens 
    {
        class Jogador;

        class Personagem : public Entidade
        {
            protected:

                //Atributos vida
                bool vivo;
                int pontosDeVida;

                //Atributos ataque
                bool estaAtacando;
                bool podeAtacar;
                float tempoAtacarNovamente;
                float tempoDesdeUltimoAtaque;
                int dano;

                //Atributo movimentação
                float aceleracaoHorizontal;
                float desaceleracaoHorizontal;
                float velocidadeMaximaHorizontal;

                //Atributo gravidade
                bool podePular;
                float gravidade; 
                float velocidadePulo;

            public:
                Personagem(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, ID identificador = vazio);
                ~Personagem();
                virtual void executar() = 0;
                virtual void desenhar() = 0;
                virtual void mover() = 0;
                
                //Métodos colisão
                virtual void colidir(Entidade* entidade2, sf::Vector2f ds) = 0;
                void colisaoPersonagem(Personagem* pPersonagem, sf::Vector2f ds);

                //Métodos combates
                void tomarDano(int dano);
                void atacar();
                void iniciarAtaque();
                void atualizarAtaque();

                //Métodos gravidade
                void atualizarPosicao();
                void pular();
                void setPodePular(bool pPular); 
                bool getVivo();

                int getPontosDeVida();

                virtual void adicionarAnimacoes() = 0;
        };
    }
}