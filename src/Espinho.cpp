#include "Entidades/Obstaculos/Espinho.hpp"
#include "iostream"

namespace Entidades
{
    namespace Obstaculos
    {
        Espinho::Espinho(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel):
            Obstaculo(pos, tam, vel, ID::espinho),
            dano(9)
        {
            nocivo = true;

            relogioDano.restart();
            setTextura("assets/espinho/espinho.png");

            corpo.setTextureRect(sf::IntRect(100, 400, 1000, 800));

            corpo.setOutlineThickness(1.0f);
            corpo.setOutlineColor(sf::Color::Red);
        }

        Espinho::~Espinho()
        {}

        void Espinho::executar()
        {
            relogioDano.getElapsedTime().asSeconds();

            desenhar();
        }

        void Espinho::desenhar()
        {
            pGG->desenhar(corpo);
        }

        void Espinho::obstacular(Personagens::Jogador* pJogador)
        {
            // Se for a primeira colisão ou já se passaram 3 segundos, aplica o dano
            if (relogioDano.getElapsedTime().asSeconds() >= 1.5f || relogioDano.getElapsedTime().asSeconds() == 0.0f && nocivo)
            {
                pJogador->tomarDano(5);
                relogioDano.restart(); // Reinicia o relógio para impedir novos danos por 3 segundos
            }

            // Impulso para afastar o jogador do espinho
            pJogador->setPodePular(true);
            pJogador->setVelocidade(sf::Vector2f(-200.0f, -470.0f));
        }

        void Espinho::colidir(Entidade* entidade2, sf::Vector2f ds)
        {
            switch(entidade2->getId()) {
                case(ID::jogador):
                {
                    Personagens::Jogador* pJogador = static_cast<Personagens::Jogador*>(entidade2);

                    // Verifica se a colisão foi mais no eixo Y e se o jogador estava caindo
                    if (ds.y < ds.x)
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