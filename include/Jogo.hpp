#pragma once

#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Gerenciadores/GerenciadorEventos.hpp"
#include "Gerenciadores/GerenciadorColisoes.hpp"
#include "Fases/Fase1.hpp"

class Jogo
{
    private:
        Gerenciadores::GerenciadorGrafico* pGG;
        Gerenciadores::GerenciadorEventos* pGE;
        //Gerenciadores::GerenciadorColisoes pGC;

<<<<<<< HEAD
        Fases::Fase1 fase1;
=======
        Observadores::MenuObservador* pMenu;

        Listas::ListaEntidades listaObstaculos;
        Listas::ListaEntidades listaInimigos;
        Listas::ListaEntidades listaJogadores;
>>>>>>> 4c111b48914fc4785fc3474028ec660323a9e0ab
    public:
        Jogo();
        ~Jogo();
        void executar();
};