#pragma once

#include "Inimigo.hpp"
#include "Animacoes/Animacao.hpp"
#include <iostream>

namespace Entidades
{
    namespace Personagens
    {
        namespace Inimigos
        {
            class Esqueleto : public Inimigo
            {
                private:                    
                    Animacoes::Animacao animacao;                
                public:
                    Esqueleto(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, Jogador* jogador);
                    ~Esqueleto();
                    void executar();
                    void desenhar();

                    //Métodos animações
                    void atualizarAnimacao(float dt);
                    void adicionarAnimacoes();
            };
        }
    }
}