#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Listas/ListaObservadores.hpp"

namespace Gerenciadores
{
    class GerenciadorEstados;
    class GerenciadorEventos
    {
        private:
            GerenciadorGrafico* pGG;
            Gerenciadores::GerenciadorEstados* pGE;
            static Listas::ListaObservadores* LO;

            static GerenciadorEventos* instancia;
            GerenciadorEventos();

        public:
            static GerenciadorEventos* getInstancia();
            ~GerenciadorEventos();
            void adicionarObservador(Observadores::Observador* observador);
            void removerObservador(Observadores::Observador* observador);
            void executar();
    };
}