#include "Gerenciadores/GerenciadorColisoes.hpp"
#include <cmath>

namespace Gerenciadores {
    GerenciadorColisoes::GerenciadorColisoes(){

    }

    GerenciadorColisoes::~GerenciadorColisoes() {

    }

    void GerenciadorColisoes::colisao(Entidades::Personagens::Personagem* ente1, Entidades::Personagens::Personagem* ente2) {
    // Verifica se os ponteiros são válidos
    if (!ente1 || !ente2) return;

    // Obtém as referências ao corpo de cada entidade
    const sf::RectangleShape& corpo1 = ente1->getCorpo();
    const sf::RectangleShape& corpo2 = ente2->getCorpo();

    // Calcula os centros das entidades
    sf::Vector2f centro1 = corpo1.getPosition() + corpo1.getSize() / 2.0f;
    sf::Vector2f centro2 = corpo2.getPosition() + corpo2.getSize() / 2.0f;

    // Calcula as distâncias entre os centros
    float dist_x = centro1.x - centro2.x;
    float dist_y = centro1.y - centro2.y;

    // Calcula os limites para colisão (metades das larguras e alturas somadas)
    float limite_x = (corpo1.getSize().x + corpo2.getSize().x) / 2.0f;
    float limite_y = (corpo1.getSize().y + corpo2.getSize().y) / 2.0f;

    // Verifica se há colisão
    if (fabs(dist_x) < limite_x && fabs(dist_y) < limite_y) {

        // Calcula a sobreposição (overlap) em cada eixo
        float overlap_x = limite_x - fabs(dist_x);
        float overlap_y = limite_y - fabs(dist_y);

        // Corrige a posição com base no menor overlap
        sf::Vector2f novaPosicao = corpo1.getPosition(); // Começa com a posição original

        if (overlap_x < overlap_y) {
            // Corrige no eixo X
            if (dist_x > 0.0f) {
                novaPosicao.x += overlap_x; // Move para a direita
            } else {
                novaPosicao.x -= overlap_x; // Move para a esquerda
            }
        } else {
            // Corrige no eixo Y
            if (dist_y > 0.0f) {
                novaPosicao.y += overlap_y; // Move para baixo
            } else {
                novaPosicao.y -= overlap_y; // Move para cima
            }
        }

        // Atualiza a posição do corpo da entidade 1
        ente1->getCorpo().setPosition(novaPosicao);
    }

    }
    void GerenciadorColisoes::gerenciar() {
        
    }
}
