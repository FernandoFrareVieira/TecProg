#include "Lista.hpp"
#include "Entidades/Entidade.hpp"

namespace Listas
{
    class ListaEntidades
    {
        private:
            Lista<Entidades::Entidade> LE;
        public:
            ListaEntidades();
            ~ListaEntidades();

            void executar();

            void desenhar();

            int getTamanho();

            void limpar();

            void incluir(Entidades::Entidade* ent);


    };
}