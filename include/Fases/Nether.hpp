#pragma once
#include "Fase.hpp"
#include "Entidades/Personagens/Jogador.hpp"
#include "Entidades/Obstaculos/Plataforma.hpp"
#include "Entidades/Obstaculos/Espinho.hpp"
#include <list>

namespace Fases {
    class Nether: public Fase {
    private:
        //Maximo de instancias
        const int maxArqueiros;
        const int maxSamurais;
        const int maxEspinhos;

        //Vetores posições disponiveis instancias aleatorias
        std::vector<sf::Vector2f> posicoesArqueiros;
        std::vector<sf::Vector2f> posicoesSamurais;
        std::list<sf::Vector2f> posicoesEspinhos;

        sf::Texture background;

    public:
        Nether(int id, bool dois_jogadores);
        ~Nether();
        void criarEntidade (sf::Vector2f posicao, sf::Vector2f tamanho, int tipo);
        void desenhar();
    };
}