#include "Entidades/Personagens/Personagem.hpp"

namespace Entidades
{
    namespace Personagens
    {
        Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, ID identificador):
            Entidade(pos, tam, vel, identificador)
        {}

        Personagem::~Personagem()
        {

        }

        void Personagem::tomarDano(int dano)
        {
            vida = vida - dano;
        }

        sf::RectangleShape Personagem::getCorpo(){
            return corpo;
        }
    }
}