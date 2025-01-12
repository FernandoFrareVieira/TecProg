#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "nlohmann/json.hpp"
#include <vector>
#include <fstream>
#include <string>
#include "Entidades/Entidade.hpp"
#include "Entidades/Obstaculos/Plataforma.hpp"
#include "Listas/ListaEntidades.hpp"



/*
    Classe Tilemap
    - Classe responsável por carregar o mapa do jogo
    - Cria as entidades do jogo
    - Cria o mapa do jogo

    LEIA OS COMENTARIOS DO .CPP E AJUSTE NO SEU CÓDIGO

*/

class Entidade;

class Tilemap{
    private:
        nlohmann::json mapa; // mapa.json  

    public:
        Tilemap(std::string mapJson);
        ~Tilemap();

        sf::Texture* textura_mapa;
        void carregarMapa(std::string mapJson, std::string caminhoImagem);
        Entidades::Entidade* criarEntidade (sf::Vector2f posicao, sf::Vector2f tamanho, int tipo);
        void criarMapa(Listas::ListaEntidades* LE);
};