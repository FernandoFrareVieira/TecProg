#pragma once

#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Gerenciadores/GerenciadorEventos.hpp"
#include "Gerenciadores/GerenciadorColisoes.hpp"
#include "Gerenciadores/GerenciadorEstados.hpp"
#include "Fases/Fase1.hpp"

class Jogo
{
    private:
        Gerenciadores::GerenciadorGrafico* pGG;
        Gerenciadores::GerenciadorEventos* pGE;
        Gerenciadores::GerenciadorEstados* GE;
        //Gerenciadores::GerenciadorColisoes pGC;

        Fases::Fase1* fase1;
    public:
        Jogo();
        ~Jogo();
        void executar();
};