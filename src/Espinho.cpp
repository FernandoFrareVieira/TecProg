#include "Entidades/Obstaculos/Espinho.hpp"
#include "iostream"

namespace Entidades
{
    namespace Obstaculos
    {
        Espinho::Espinho(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel):
            Obstaculo(pos, tam, vel),
            dano(5)
        {
            setTextura("assets/espinho/espinho.png");

            corpo.setTextureRect(sf::IntRect(0, 0, 1184, 1184));
        }

        Espinho::~Espinho()
        {}

        void Espinho::executar()
        {
            desenhar();
        }

        void Espinho::desenhar()
        {
            pGG->desenhar(corpo);
        }

        void Espinho::obstacular(Personagens::Jogador* pJogador)
        {
            pJogador->tomarDano(5);
        }

        void Espinho::colidir(Entidade* entidade2, sf::Vector2f ds)
        {
            switch(entidade2->getId()) {
                case(ID::jogador):
                {
                    Personagens::Jogador* pJogador = static_cast<Personagens::Jogador*>(entidade2);
                    obstacular(pJogador);
                }
                break;

                case(ID::inimigo):
                {

                }

                break;

                default:
                {

                }
                break;
            }
        }
    }
}