#include "Entidades/Obstaculos/Fogo.hpp"
#include "iostream"

namespace Entidades
{
    namespace Obstaculos
    {
        Fogo::Fogo(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel):
            Obstaculo(pos, tam, vel, ID::fogo),
            dano(3)
        {
            relogioDano.restart();
            setTextura("assets/Fogo/Attack.png");

            corpo.setTextureRect(sf::IntRect(2, 10, 40, 52));
            //corpo.setOutlineThickness(1.0f);
            //corpo.setOutlineColor(sf::Color::Red);
        }

        Fogo::~Fogo()
        {}

        void Fogo::executar()
        {
            relogioDano.getElapsedTime().asSeconds();

            desenhar();
        }

        void Fogo::desenhar()
        {
            pGG->desenhar(corpo);
        }

        void Fogo::obstacular(Personagens::Jogador* pJogador)
        {
            // Se for a primeira colisão ou já se passaram 3 segundos, aplica o dano
            if (relogioDano.getElapsedTime().asSeconds() >= 3.0f || relogioDano.getElapsedTime().asSeconds() == 0.0f)
            {
                pJogador->tomarDano(20);
                relogioDano.restart(); // Reinicia o relógio para impedir novos danos por 3 segundos
            }

            // Impulso para afastar o jogador do Fogo
            printf("Tomou dano");
            fflush(stdout);
            pJogador->setPodePular(true);
            pJogador->setVelocidade(sf::Vector2f(-100.0f, -500.0f));
        }

        void Fogo::colidir(Entidade* entidade2, sf::Vector2f ds)
        {
            switch(entidade2->getId()) {
                case(ID::jogador):
                {
                    Personagens::Jogador* pJogador = static_cast<Personagens::Jogador*>(entidade2);

                    // Verifica se a colisão foi mais no eixo Y e se o jogador estava caindo
                    obstacular(pJogador);
        
                    colisaoObstaculo(entidade2, ds);
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