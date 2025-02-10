#pragma once

#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Gerenciadores/GerenciadorEventos.hpp"
#include "Gerenciadores/GerenciadorColisoes.hpp"
#include "Gerenciadores/GerenciadorEstados.hpp"
#include "Menus/MenuPrincipal.hpp"
#include "Fases/Pantanal.hpp"
#include "Fases/Nether.hpp"

class Jogo
{
    private:
        Gerenciadores::GerenciadorGrafico* pGG;
        Gerenciadores::GerenciadorEventos* pGE;
        Gerenciadores::GerenciadorEstados* pGEstados;
        
        Menus::MenuPrincipal* pMP;

    public:
        Jogo();
        ~Jogo();
        void executar();
};