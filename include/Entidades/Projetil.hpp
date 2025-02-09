#pragma once

#include "Entidades/Entidade.hpp"
#include "Entidades/Personagens/Personagem.hpp"
#include "Listas/ListaEntidades.hpp"

namespace Entidades
{
    class Projetil : public Entidade
    {
        private:
            int tempoDeVida;
            int dano;

            sf::Texture* textura;

            sf::Clock relogio;

            bool paraDireita;
        public:
            Projetil(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel,  bool pDireita = false);
            ~Projetil();

            void executar();
            void desenhar();
            void mover();

            void colidir(Entidades::Entidade* entidade2, sf::Vector2f ds);
    };
}