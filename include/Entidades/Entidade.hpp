#pragma once

#include "Ente.hpp"
 
namespace Entidades
{
    class Entidade : public Ente
    {
        protected:
            const int id;
            static int contador;
        public:
            Entidade();
            ~Entidade();
            virtual void executar() = 0;
            virtual void desenhar() = 0;
    };  
}