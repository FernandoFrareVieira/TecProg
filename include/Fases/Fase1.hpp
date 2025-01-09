#pragma once

#include "Fase.hpp"
#include "Entidades/Personagens/Jogador.hpp"
#include "Entidades/Personagens/Esqueleto.hpp"
#include "Entidades/Obstaculos/Plataforma.hpp"

namespace Fases
{
    class Fase1 : public Fase
    {
        private:
            const int maxEsqueletos;
            const int maxPlataformas;

            //Provisorio
            Entidades::Personagens::Jogador* jogador;
        public:
            Fase1();
            ~Fase1();
            void executar();
            void desenhar();

            //Provisorio
            Entidades::Personagens::Jogador* getJogador();
    };
}