#pragma once

#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Gerenciadores/GerenciadorEventos.hpp"
#include "Entidades/Personagens/Jogador.hpp"
#include "Entidades/Personagens/Esqueleto.hpp"

class Jogo
{
    private:
        Gerenciadores::GerenciadorGrafico* pGG;
        Gerenciadores::GerenciadorEventos* pGE;
        Entidades::Personagens::Jogador* jogador;
        Entidades::Personagens::Esqueleto* esqueleto;
    public:
        Jogo();
        ~Jogo();
        void executar();
};