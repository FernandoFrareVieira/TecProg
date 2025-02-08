#pragma once

#include "Fase.hpp"
#include "Entidades/Personagens/Jogador.hpp"
#include "Entidades/Obstaculos/Plataforma.hpp"
#include "vector"
#include "list"

namespace Fases
{
    class Fase1 : public Fase
    {
        private:
            //Maximo de instancias
            const int maxEsqueletos;
            const int maxArqueiros;
            const int maxGosmas;

            //Vetores posições disponiveis instancias aleatorias
            std::vector<sf::Vector2f> posicoesEsqueleto;
            std::vector<sf::Vector2f> posicoesArqueiros;
            std::vector<sf::Vector2f> posicoesGosmas;

            sf::Texture background;
        public:
            Fase1(int id, bool dois_jogadores);
            ~Fase1();
            void criarEntidade (sf::Vector2f posicao, sf::Vector2f tamanho, int tipo);
            void desenhar();
            void setPosicoes();
    };
}