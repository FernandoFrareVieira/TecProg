#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciadores/GerenciadorGrafico.hpp"

namespace Gerenciadores
{
    class GerenciadorEventos
    {
        private:
            GerenciadorGrafico* pGG;
            static GerenciadorEventos* instancia;

            GerenciadorEventos();

        public:
            static GerenciadorEventos* getInstancia();
            ~GerenciadorEventos();
            void executar();
    };
}