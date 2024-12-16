#include "Entidades/Personagens/Personagem.hpp"

namespace Entidades
{
    namespace Personagens
    {
        Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel):
            Entidade(pos, tam),
            velocidade(vel)
        {
            corpo.setPosition(posicao);
            corpo.setSize(tamanho);
        }

        Personagem::~Personagem()
        {

        }

        void Personagem::tomarDano(int dano)
        {
            vida = vida - dano;
        }
    }
}