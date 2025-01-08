#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Entidades/Personagens/Jogador.hpp"

namespace Observadores {
    class MenuObservador;
}

namespace Gerenciadores
{
    class GerenciadorEventos
    {
        private:
            GerenciadorGrafico* pGG;
            Entidades::Personagens::Jogador*  pJogador;
            static GerenciadorEventos* instancia;
            Observadores::MenuObservador* pMenu;

            GerenciadorEventos(Entidades::Personagens::Jogador* jogador);

        public:
            static GerenciadorEventos* getInstancia(Entidades::Personagens::Jogador* jogador);
            ~GerenciadorEventos();
            void add(Observadores::MenuObservador* pM) {pMenu = pM;}
            void executar();
    };
}