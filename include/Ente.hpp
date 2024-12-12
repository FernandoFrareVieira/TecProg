#pragma once
#include "Gerenciadores/GerenciadorGrafico.hpp"

class Ente
{
    protected:
        static Gerenciadores::GerenciadorGrafico* pGG;
    public:
        Ente();
        ~Ente();
        virtual void executar() = 0;
        virtual void desenhar() = 0;
};