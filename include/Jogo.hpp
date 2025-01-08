#pragma once

#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Gerenciadores/GerenciadorEventos.hpp"
#include "Gerenciadores/GerenciadorColisoes.hpp"
#include "Entidades/Personagens/Jogador.hpp"
#include "Entidades/Personagens/Esqueleto.hpp"
#include "Entidades/Obstaculos/Plataforma.hpp"
#include "Listas/ListaEntidades.hpp"
#include "Menus/MenuPrincipal.hpp"

class Jogo
{
    private:
        Gerenciadores::GerenciadorGrafico* pGG;
        Gerenciadores::GerenciadorEventos* pGE;
        Gerenciadores::GerenciadorColisoes pGC;
        Entidades::Personagens::Jogador* jogador;

        Listas::ListaEntidades listaEntidades;
    public:
        Jogo();
        ~Jogo();
        void executar();
};