#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "nlohmann/json.hpp"
#include "Ente.hpp"
#include "Estados/Estado.hpp"
#include "Listas/ListaEntidades.hpp"
#include "Entidades/Personagens/Jogador.hpp"
#include "Gerenciadores/GerenciadorColisoes.hpp"
#include "Entidades/Obstaculos/Plataforma.hpp"
#include "Entidades/Personagens/Esqueleto.hpp"
#include "Entidades/Personagens/Arqueiro.hpp"
#include "Entidades/Obstaculos/Gosma.hpp"
#include "Entidades/Obstaculos/Espinho.hpp"
#include "Entidades/Projetil.hpp"
#include "Observadores/FaseObservador.hpp"
#include "Gerenciadores/GerenciadorEstados.hpp"

namespace Fases
{

    class Fase : public Ente, public Estados::Estado
    {
        protected:
            Listas::ListaEntidades listaObstaculos;
            Listas::ListaEntidades listaInimigos;
            Listas::ListaEntidades listaJogadores;
            Listas::ListaEntidades listaProjeteis;

            Entidades::Personagens::Jogador* pJogador1;
            Entidades::Personagens::Jogador* pJogador2;

            sf::RectangleShape corpo;

            Gerenciadores::GerenciadorColisoes pGC;
            Gerenciadores::GerenciadorEstados* pGEstados;

            nlohmann::json mapa;
            sf::Texture tilesetTextura;

            std::vector<sf::Vector2f> posicoes;
            Observadores::FaseObservador* pObservadorFase;
            bool multiplayer;
        public:
            Fase(int id, bool dois_jogadores);
            ~Fase();
            void teste(Listas::ListaEntidades &LO) {listaObstaculos = LO;}
            void adicionarInimigos(Entidades::Entidade* inimigo);
            void adicionarObstaculos(Entidades::Entidade* obstaculo);
            void adicionarJogador(Entidades::Entidade* jogador);
            void adicionarProjetil(Entidades::Entidade* projetil);

            void carregarMapa(std::string mapJson, std::string caminhoImagem);
            virtual void criarEntidade (sf::Vector2f posicao, sf::Vector2f tamanho, int tipo) = 0;

            void criarInimigos(std::string mapJson, std::vector<sf::Vector2f> posicoes_inimigos, Entidades::Personagens::Jogador* jogador);
            void executar();
            void mudarFase();

            virtual void setPosicoes() = 0;
            //Salvamento e Carregamento
            void salvar(const std::string& caminhoArquivo);
            void carregar(const std::string& caminhoArquivo);
    };
}