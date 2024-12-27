#include "Gerenciadores/GerenciadorColisoes.hpp"
#include <cmath>
#include <iostream>

namespace Gerenciadores {
    GerenciadorColisoes::GerenciadorColisoes(Listas::ListaEntidades* LE):
    listaEntidades(LE)
    {

    }

    GerenciadorColisoes::~GerenciadorColisoes() 
    {

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
            int id1 = ente1->getId();
            int id2 = ente2->getId();

            // Ajusta as posições para evitar sobreposição
            if (id1 == 0 || id1 == 1) { // Jogador ou inimigo
                if (overlap_x < overlap_y) {
                    if (dist_x > 0.0f) {
                        corpo1->move(overlap_x, 0); // Move para a direita
                    } else {
                        corpo1->move(-overlap_x, 0); // Move para a esquerda
                    }
                } else {
                    if (dist_y > 0.0f) {
                        corpo1->move(0, overlap_y); // Move para baixo
                    } else {
                        corpo1->move(0, -overlap_y); // Move para cima
                    }
                }
            }

            if (id2 == 0 || id2 == 1) { // Jogador ou inimigo
                if (overlap_x < overlap_y) {
                    if (dist_x > 0.0f) {
                        corpo2->move(-overlap_x, 0); // Move para a esquerda
                    } else {
                        corpo2->move(overlap_x, 0); // Move para a direita
                    }
                } else {
                    if (dist_y > 0.0f) {
                        corpo2->move(0, -overlap_y); // Move para cima
                    } else {
                        corpo2->move(0, overlap_y); // Move para baixo
                    }
                }
            }
        }
    }
    
    void GerenciadorColisoes::gerenciar() {
        //TODO - Implementar o loop com a classe Iterador
        for(int i = 0; i < listaEntidades->getTamanho() - 1; i++) {
            Entidades::Entidade* entidade1 = listaEntidades->operator[](i);
            for(int j = 0; j < listaEntidades->getTamanho(); j++) {
                Entidades::Entidade* entidade2 = listaEntidades->operator[](j);
                if(entidade1->getId() != entidade2->getId()) {
                    colisao(entidade1, entidade2);
                }
            }
        }
    }
}