#include "Entidades/Obstaculos/Plataforma.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, int tipoPlataforma):
        Obstaculo(pos, tam, vel, ID::plataforma)
        {
            vivo = true;   
            atrito = 0.0f;

            nocivo = false;
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
            sf::Vector2f velocidadeJogador = jogador->getVelocidade();

            jogador->setVelocidade(sf::Vector2f(velocidadeJogador.x*(1.0f - atrito), velocidadeJogador.y));
        }

        void Plataforma::colidir(Entidade* entidade2, sf::Vector2f ds)
        {
            switch(entidade2->getId())
            {
                case(ID::jogador):
                {
                    if(!nocivo)
                        colisaoObstaculo(entidade2, ds);
                        
                        Entidades::Personagens::Jogador* pJogador = static_cast<Entidades::Personagens::Jogador*>(entidade2);
                        obstacular(pJogador);
                }break;
                case(ID::esqueleto):
                {
                    colisaoObstaculo(entidade2, ds);
                }break;
                case(ID::arqueiro):
                {
                    colisaoObstaculo(entidade2, ds);
                }break;
                case(ID::samurai):
                {
                    colisaoObstaculo(entidade2, ds);
                }
                break;
                case(ID::projetil):
                {
                    colisaoObstaculo(entidade2, ds);

                    Entidades::Projetil* pProjetil = static_cast<Entidades::Projetil*>(entidade2);
                    pProjetil->setVelocidade(sf::Vector2f(0.0f, 0.0f));
                }
            }   
        }
    }

    
}