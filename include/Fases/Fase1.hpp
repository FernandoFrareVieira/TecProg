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
        public:
            Fase1(int id);
            ~Fase1();
            void criarEntidade (sf::Vector2f posicao, sf::Vector2f tamanho, int tipo);
            void desenhar();
    };
}