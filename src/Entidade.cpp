#include "Entidades/Entidade.hpp"

namespace Entidades
{
    int Entidade::contador = 0;

    Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam):
        Ente(),
        id(contador++),
        posicao(pos),
        tamanho(tam)
    {}

    Entidade::~Entidade()
    {}

    sf::Vector2f Entidade::getPosicao() {
        return posicao;
    }
    
    sf::Vector2f Entidade::getTamanho() {
        return tamanho;
    }

    void Entidade::setPosicao(float posX, float posY) {
        posicao.x = posX;
        posicao.y = posY;
        printf("%f %f",posicao.x, posicao.y);

    }
}