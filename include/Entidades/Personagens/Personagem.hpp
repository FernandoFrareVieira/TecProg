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
                float velocidadePulo;

                //Atributos texturas
                sf::Texture* texturaParado;
                sf::Texture* texturaAndando;
                sf::Texture* texturaAtacando;


                //Animacao ataque
                float tempoAnimacaoAtaque;
            public:
                Personagem(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, ID identificador = vazio);
                ~Personagem();
                virtual void executar() = 0;
                virtual void desenhar() = 0;
                virtual void mover() = 0;
                
                //Métodos colisão
                virtual void colidir(Entidade* entidade2, sf::Vector2f ds) = 0;
                void colisaoPersonagem(Personagem* pPersonagem, sf::Vector2f ds);

                //Métodos ataque
                void tomarDano(int dano);
                void atacar();
                void iniciarAtaque();
                void atualizarAtaque();

                //Métodos gravidade
                void pular();

                //Métodos pontos d evida
                int getPontosDeVida();
                void setPontosDeVida(int vida);

                //Método animacao
                virtual void adicionarAnimacoes() = 0;
        };
    }
}