#include "Entidades/Obstaculos/Gosma.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Gosma::Gosma(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel):
            Obstaculo(pos, tam, vel)
        {}

        Gosma::~Gosma()
        {}

        void Gosma::executar()
        {
            desenhar();
        }

        void Gosma::desenhar()
        {
            pGG->desenhar(corpo);
        }

        void Gosma::obstacular(Personagens::Jogador* pJogador)
        {
            sf::Vector2f velocidadeNova = pJogador->getVelocidade() / 2.0f;
            pJogador->setVelocidade(velocidadeNova);
        }

        void Gosma::colidir(Entidade* entidade2, sf::Vector2f ds)
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