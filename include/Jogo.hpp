#pragma once

#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Gerenciadores/GerenciadorEventos.hpp"
#include "Gerenciadores/GerenciadorColisoes.hpp"
#include "Gerenciadores/GerenciadorEstados.hpp"
#include "Menus/MenuPrincipal.hpp"
#include "Fases/Pantano.hpp"
#include "Fases/Nether.hpp"

class Jogo
{
    private:
        Gerenciadores::GerenciadorGrafico* pGG;
        Gerenciadores::GerenciadorEventos* pGE;
        Gerenciadores::GerenciadorEstados* GE;
        //Gerenciadores::GerenciadorColisoes pGC;
        Menus::MenuPrincipal* pMP;

        Fases::Pantano* pantano;
        Fases::Nether* nether;
    public:
        Jogo();
        ~Jogo();
        void executar();
};