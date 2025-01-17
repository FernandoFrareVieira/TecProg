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
            static GerenciadorEventos* instancia;
            Observadores::MenuObservador* pMenu;

            GerenciadorEventos();

        public:
            static GerenciadorEventos* getInstancia();
            ~GerenciadorEventos();
            void add(Observadores::MenuObservador* pM) {pMenu = pM;}
            void executar();
    };
}