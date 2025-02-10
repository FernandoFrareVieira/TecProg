#include "Entidades/Obstaculos/Gosma.hpp"
#include "iostream"

namespace Entidades
{
    namespace Obstaculos
    {
        Gosma::Gosma(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel):
            Obstaculo(pos, tam, vel, ID::gosma),
            viscosidade(0.1f)
        {
            nocivo = false;

            setTextura("assets/plataformas/gosma.png");
        }

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
            if(!nocivo) {
                sf::Vector2f velocidadeAtual = pJogador->getVelocidade();
                pJogador->setVelocidade(sf::Vector2f(velocidadeAtual.x * (1.0f - viscosidade), velocidadeAtual.y));
            }
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
                default:
                {

                }
                break;
            }
        }
    }
}