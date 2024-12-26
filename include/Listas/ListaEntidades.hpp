#include "Lista.hpp"
#include "Entidades/Entidade.hpp"

#pragma once

namespace Listas
{
    class ListaEntidades
    {
        private:
            Lista<Entidades::Entidade> LE;
        public:
            ListaEntidades();
            ~ListaEntidades();

            void adicionarEntidade(Entidades::Entidade* entidade);
            void removerEntidade(Entidades::Entidade* entidade);
            void executar();
            void desenhar();
            int getTamanho();
            void limpar();
            Entidades::Entidade* operator[](int pos);
    };
}