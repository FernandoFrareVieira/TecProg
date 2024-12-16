#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Entidades/Personagens/Jogador.hpp"

namespace Gerenciadores
{
    class GerenciadorEventos
    {
        private:
            GerenciadorGrafico* pGG;
            Entidades::Personagens::Jogador*  pJogador;
            static GerenciadorEventos* instancia;

            GerenciadorEventos(Entidades::Personagens::Jogador* jogador);

        public:
            static GerenciadorEventos* getInstancia(Entidades::Personagens::Jogador* jogador);
            ~GerenciadorEventos();
            void executar();
    };
}