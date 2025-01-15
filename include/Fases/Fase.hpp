#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "nlohmann/json.hpp"
#include "Ente.hpp"
#include "Listas/ListaEntidades.hpp"
#include "Entidades/Personagens/Jogador.hpp"
#include "Gerenciadores/GerenciadorColisoes.hpp"
#include "Entidades/Obstaculos/Plataforma.hpp"
#include "Entidades/Personagens/Esqueleto.hpp"

namespace Fases
{
    class Fase : public Ente
    {
        protected:
            Listas::ListaEntidades listaObstaculos;
            Listas::ListaEntidades listaInimigos;
            Listas::ListaEntidades listaJogadores;

            sf::RectangleShape corpo;

            Gerenciadores::GerenciadorColisoes pGC;

            nlohmann::json mapa;
            sf::Texture tilesetTextura;

            std::vector<sf::Vector2f> posicoes;
        public:
            Fase();
            ~Fase();
            virtual void executar() = 0;
            virtual void desenhar() = 0;
            void teste(Listas::ListaEntidades &LO) {listaObstaculos = LO;}
            void adicionarInimigos(Entidades::Entidade* inimigo);
            void adicionarObstaculos(Entidades::Entidade* obstaculo);
            void adicionarJogador(Entidades::Entidade* jogador);

            void carregarMapa(std::string mapJson, std::string caminhoImagem);
            void criarEntidade (sf::Vector2f posicao, sf::Vector2f tamanho, int tipo);

            void criarInimigos(std::string mapJson, std::vector<sf::Vector2f> posicoes_inimigos, Entidades::Personagens::Jogador* jogador);
            
    };
}