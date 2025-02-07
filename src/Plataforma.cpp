#include "Entidades/Obstaculos/Plataforma.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel):
        Obstaculo(pos, tam, vel, ID::plataforma)
        {
            vivo = true;   
            //corpo.setFillColor(sf::Color::White);
            //corpo.setSize(sf::Vector2f(LARGURA, ALTURA/7.5f));
        }

        Plataforma::~Plataforma(){}

        void Plataforma::executar()
        {
            atualizarPosicao();
            desenhar();
        }

        void Plataforma::desenhar()
        {
            pGG->desenhar(corpo);
        }

        void Plataforma::obstacular(Personagens::Jogador* jogador)
        {
            //Quando tiver colisão
        }

        void Plataforma::colidir(Entidade* entidade2, sf::Vector2f ds)
        {
            switch(entidade2->getId())
            {
                case(ID::jogador):
                {
                    colisaoObstaculo(entidade2, ds);
                }break;
                case(ID::esquleto):
                {
                    colisaoObstaculo(entidade2, ds);
                }break;
                case(ID::arqueiro):
                {
                    colisaoObstaculo(entidade2, ds);
                }break;
            }   
        }
    }
}