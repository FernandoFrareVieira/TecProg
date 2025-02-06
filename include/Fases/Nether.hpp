#pragma once
#include "Fase.hpp"
#include "Entidades/Personagens/Jogador.hpp"
#include "Entidades/Obstaculos/Plataforma.hpp"
#include "Entidades/Obstaculos/Espinho.hpp"

namespace Fases {
    class Nether: public Fase {
    private:
        const int maxEsqueletos;
        const int maxPlataformas;

        sf::Texture background;
        //Provisorio
        //Entidades::Personagens::Jogador* jogador;
    public:
        Nether(int id);
        ~Nether();
        void criarEntidade (sf::Vector2f posicao, sf::Vector2f tamanho, int tipo);
        void desenhar();
    };
}