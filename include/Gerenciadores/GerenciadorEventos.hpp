#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Entidades/Personagens/Jogador.hpp"
#include "Gerenciadores/GerenciadorEstados.hpp"

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
            Observadores::MenuObservador* pMenuObservador;

            Gerenciadores::GerenciadorEstados* gEstados;

            GerenciadorEventos();

        public:
            static GerenciadorEventos* getInstancia();
            ~GerenciadorEventos();
            void add(Observadores::MenuObservador* pM) {pMenuObservador = pM;}
            void executar();
    };
}