#include "Gerenciadores/GerenciadorColisoes.hpp"
#include <cmath>
#include <iostream>

namespace Gerenciadores {
    GerenciadorColisoes::GerenciadorColisoes()
    {

    }

    GerenciadorColisoes::~GerenciadorColisoes() 
    {

    }


<<<<<<< HEAD
    void GerenciadorColisoes::setObstaculos(Listas::ListaEntidades* LO)
    {
        if(LO)
            listaObstaculos = LO;
    }

    void GerenciadorColisoes::setInimigos(Listas::ListaEntidades* LI)
    {
        if(LI)
            listaInimigos = LI;
    }

    void GerenciadorColisoes::setJogadores(Listas::ListaEntidades* LJ)
    {
        if(LJ)
            listaJogadores = LJ;
    }

    void GerenciadorColisoes::colisaoPersonagens(Entidades::Entidade* ente1, Entidades::Entidade* ente2, float overlap_x, float overlap_y, float dist_x, float dist_y) {
        //Problema nesse algoritmo, o corpo que se move depende da ordem dos parametros
        //TODO - Criar método virtual puro colidir na classe Entidade para tratar a colisão para cada Entidade em especifico, deve arrumar o problema
=======
    void GerenciadorColisoes::colisaoPersonagens(Entidades::Entidade* ente1, Entidades::Entidade* ente2, float overlap_x, float overlap_y, float dist_x, float dist_y) {
>>>>>>> 66663f3c035762bd59289e872a2b37287de82623
        sf::RectangleShape* corpo1 = ente1->getCorpo();
        sf::RectangleShape* corpo2 = ente2->getCorpo();
        if (overlap_x < overlap_y) {
            if (dist_x > 0.0f) {
                corpo2->move(-overlap_x, 0); // Move para a esquerda
            } 
            else {
                corpo2->move(overlap_x, 0); // Move para a direita
            }
        }
        else {
            if (dist_y > 0.0f) {
                corpo2->move(0, -overlap_y); // Move para cima
            } 
            else {
                corpo2->move(0, overlap_y); // Move para baixo
            }
        }
        
    }
    void GerenciadorColisoes::colisao(Entidades::Entidade* ente1, Entidades::Entidade* ente2) 
    {
        // Verifica se os ponteiros são válidos
        if (!ente1 || !ente2) return;

        // Obtém as referências ao corpo de cada entidade
        sf::RectangleShape* corpo1 = ente1->getCorpo();
        sf::RectangleShape* corpo2 = ente2->getCorpo();

        // Calcula os centros das entidades
        sf::Vector2f centro1 = corpo1->getPosition() + corpo1->getSize() / 2.0f;
        sf::Vector2f centro2 = corpo2->getPosition() + corpo2->getSize() / 2.0f;

        // Calcula as distâncias entre os centros
        float dist_x = centro1.x - centro2.x;
        float dist_y = centro1.y - centro2.y;

        // Calcula os limites para colisão (metades das larguras e alturas somadas)
        float limite_x = (corpo1->getSize().x + corpo2->getSize().x) / 2.0f;
        float limite_y = (corpo1->getSize().y + corpo2->getSize().y) / 2.0f;

        // Verifica se há colisão
        if (fabs(dist_x) < limite_x && fabs(dist_y) < limite_y) {
            // Calcula a sobreposição (overlap) em cada eixo
            float overlap_x = limite_x - fabs(dist_x);
            float overlap_y = limite_y - fabs(dist_y);

            // Verifica a combinação de IDs
            Entidades::ID id1 = ente1->getId();
            Entidades::ID id2 = ente2->getId();

            // Ajusta as posições para evitar sobreposição

<<<<<<< HEAD
            if (id1 == Entidades::ID::inimigo && id2 == Entidades::ID::jogador) // Jogador e inimigo
                colisaoPersonagens(ente1, ente2, overlap_x, overlap_y, dist_x, dist_y);
            else if (id1 == Entidades::ID::obstaculo && id2 == Entidades::ID::inimigo) //Obstaculo e inimigo
                colisaoPersonagens(ente1, ente2, overlap_x, overlap_y, dist_x, dist_y);
            else // Jogador e Obstaculo 
                colisaoPersonagens(ente1, ente2, overlap_x, overlap_y, dist_x, dist_y);
=======
            if (id1 == Entidades::ID::inimigo && id2 == Entidades::ID::jogador) { // Jogador ou inimigo
                colisaoPersonagens(ente1, ente2, overlap_x,overlap_y,dist_x,dist_y);
            }
            else if (id1 == Entidades::ID::obstaculo && id2 == Entidades::ID::inimigo)
                colisaoPersonagens(ente1, ente2, overlap_x,overlap_y,dist_x,dist_y);
>>>>>>> 66663f3c035762bd59289e872a2b37287de82623
        }
    }
    
    void GerenciadorColisoes::gerenciar() {
        //Colisão jogadores com obstaculos e inimigos
        for(int i = 0; i < listaJogadores->getTamanho(); i++) {
            Entidades::Entidade* entidade1 = listaJogadores->operator[](i);
            for(int j = 0; j < listaInimigos->getTamanho(); j++) {
                Entidades::Entidade* entidade2 = listaInimigos->operator[](j);
                colisao(entidade1, entidade2);
            }
            for(int j = 0; j < listaObstaculos->getTamanho(); j++) {
                Entidades::Entidade* entidade2 = listaObstaculos->operator[](j);
                colisao(entidade2, entidade1);
            }
        }

        //Colisão Inimigos e obstaculos
        for(int i = 0; i < listaInimigos->getTamanho(); i++) {
            Entidades::Entidade* entidade1 = listaInimigos->operator[](i);
            for(int j = 0; j < listaObstaculos->getTamanho(); j++) {
                Entidades::Entidade* entidade2 = listaObstaculos->operator[](j);
                colisao(entidade2, entidade1);
            }
        }

        //TODO - Colisão inimigo com inimigo ?
    }
}