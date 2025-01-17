#pragma once

#include "Fase.hpp"
#include "Entidades/Personagens/Jogador.hpp"
#include "Entidades/Obstaculos/Plataforma.hpp"

namespace Fases
{
    class Fase1 : public Fase
    {
        private:
            const int maxEsqueletos;
            const int maxPlataformas;

            sf::Texture background;
            //Provisorio
            Entidades::Personagens::Jogador* jogador;
        public:
            Fase1();
            ~Fase1();
            void executar();
            void desenhar();
    };
}