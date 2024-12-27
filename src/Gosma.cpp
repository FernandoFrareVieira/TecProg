#include "Entidades/Obstaculos/Gosma.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Gosma::Gosma(sf::Vector2f pos, sf::Vector2f tam, int identificador):
            Obstaculo(pos, tam, identificador)
        {}

        Gosma::~Gosma()
        {}

        void Gosma::executar()
        {
            desenhar();
        }

        void Gosma::desenhar()
        {
            //pGG->desenhar(corpo);
        }

        void Gosma::obstacular(Personagens::Jogador* pJogador)
        {
            //while colisao {
                //sf::Vector2f velocidade = pJogador->getVelocidade();
                //velocidade.x = velocidade.x - 10;
                //pJogador->setVelocidade(velocidade);
            //}
        }
    }
}