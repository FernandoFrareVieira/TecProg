#include "Entidades/Personagens/Jogador.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include <iostream>

namespace Entidades
{
    namespace Personagens
    {
        Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, int identificador):
            Personagem(pos, tam, vel, identificador)
        {   
            vivo = true;
            vida = 100;

            //corpo.setFillColor(sf::Color::Red);

            textura = pGG->carregarTextura("assets/IDLE.png"); 
            corpo.setSize(sf::Vector2f(LARGURA/30.0f,ALTURA/7.5f));
            corpo.setTextureRect(sf::IntRect(40,48,15,33));
            corpo.setFillColor(sf::Color::White);
            corpo.setTexture(textura);
        }

        Jogador::~Jogador()
        {
            
        }

        void Jogador::executar()
        {
            desenhar();
        }

        void Jogador::desenhar()
        {
            pGG->desenhar(corpo);
        }

        void Jogador::mover(sf::Keyboard::Key tecla)
        {
            if(tecla == sf::Keyboard::D) {
                corpo.move(velocidade.x, 0.0f);
            }else if(tecla == sf::Keyboard::A) {
                corpo.move(-velocidade.x, 0.0f);
            }
            else if (tecla == sf::Keyboard::W) {
                corpo.move(0.0f, -velocidade.y);
            }
            else if (tecla == sf::Keyboard::S) {
                corpo.move(0.0f, velocidade.y);
            }
        }


    }
}