#include "Entidades/Personagens/Esqueleto.hpp"

namespace Entidades
{
    namespace Personagens
    {
        Esqueleto::Esqueleto(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, Jogador* jogador):
            Inimigo(pos, tam, vel, jogador)
        {
            //corpo.setFillColor(sf::Color::White);
            vivo = true;
            vida = 50;

            textura = pGG->carregarTextura("assets/esqueleto.png");
            corpo.setTextureRect(sf::IntRect(10,15,32,30));
            corpo.setSize(sf::Vector2f(LARGURA/17.0f,ALTURA/7.50f));
            corpo.setTexture(textura);
            corpo.setFillColor(sf::Color::White);
        }
         Esqueleto::~Esqueleto() {}

        void Esqueleto::executar() {
            desenhar();
            mover();
        }

        void Esqueleto::desenhar() {
            pGG->desenhar(corpo);
         }
    }
}
