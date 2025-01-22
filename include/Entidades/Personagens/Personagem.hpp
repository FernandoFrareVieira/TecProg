    #pragma once

#include "../Entidade.hpp"

namespace Entidades
{
    namespace Personagens 
    {
        class Personagem : public Entidade
        {
            protected:
                bool vivo;
                int pontosDeVida;
                bool estaAtacando;
                bool podeAtacar;
                float tempoAtacarNovamente;
                float tempoDesdeUltimoAtaque;
                int dano;

            public:
                Personagem(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, ID identificador = vazio);
                ~Personagem();
                virtual void executar() = 0;
                virtual void desenhar() = 0;
                
                // Método colisão
                virtual void colidir(Entidade* entidade2, sf::Vector2f ds) = 0;

                // Métodos combates
                void tomarDano(int dano);
                void atacar();
                void iniciarAtaque();
                void atualizarAtaque();
        };
    }
}