#include "Entidades/Personagens/Personagem.hpp"

namespace Entidades
{
    namespace Personagens
    {
        Personagem::Personagem():
            Entidade()
        {
            corpo.setSize(sf::Vector2f(120.0f, 120.0f));
            corpo.setPosition(120.0f, 120.0f);
            corpo.setFillColor(sf::Color::Red);
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