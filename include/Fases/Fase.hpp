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
#include "Entidades/Personagens/Inimigos/Esqueleto.hpp"
#include "Entidades/Personagens/Inimigos/Arqueiro.hpp"
#include "Entidades/Personagens/Inimigos/Samurai.hpp"
#include "Entidades/Obstaculos/Gosma.hpp"
#include "Entidades/Obstaculos/Espinho.hpp"
#include "Entidades/Obstaculos/Fogo.hpp"
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

            std::vector<sf::Vector2f> posicoesFogos;
            Observadores::FaseObservador* pObservadorFase;
            bool multiplayer;

            sf::Texture imagemDeFundo;
        public:
            Fase(int id, bool dois_jogadores);
            ~Fase();

            void adicionarInimigo(Entidades::Entidade* inimigo);
            void adicionarObstaculo(Entidades::Entidade* obstaculo);
            void adicionarJogador(Entidades::Entidade* jogador);
            void adicionarProjetil(Entidades::Entidade* projetil);

            void carregarMapa(std::string mapJson, std::string caminhoImagem);
            virtual void criarObstaculo(sf::Vector2f posicao, sf::Vector2f tamanho, int tipo) = 0;

            virtual void desenhar() = 0;
            void executar();

            void mudarFase();

            virtual void setPosicoesAleatorias() = 0;
            void instanciaAleatorias(std::vector<sf::Vector2f> posicoes, Entidades::ID id);

            //Salvamento e Carregamento
            void salvar(const std::string& caminhoArquivo);
            void carregar(const std::string& caminhoArquivo);
    };
}