#include "Entidades/Personagens/Jogador.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include <iostream>

namespace Entidades
{
    namespace Personagens
    {
        Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel):
            Personagem(pos, tam, vel)
        {   
            vivo = true;
            textura = pGG->carregarTextura("assets/IDLE.png"); 
            corpo.setSize(sf::Vector2f(LARGURA/30.0f,ALTURA/7.5f));
            corpo.setTextureRect(sf::IntRect(40,48,15,33));
            //corpo.setFillColor(sf::Color::White);
            corpo.setTexture(textura);
        }

        Jogador::~Jogador()
        {

        }

        void Jogador::executar()
        {

        }

        void Jogador::desenhar()
        {
            if(vivo) {
                pGG->desenhar(corpo);
            }
        }

        void Jogador::mover(sf::Keyboard::Key tecla)
        {
            if(tecla == sf::Keyboard::D) {
                sf::Vector2f pos = corpo.getPosition();
                pos.x = pos.x + velocidade.x;
                corpo.setPosition(pos);
            }else if(tecla == sf::Keyboard::A) {
                sf::Vector2f pos = corpo.getPosition();
                pos.x = pos.x - velocidade.x;
                corpo.setPosition(pos);
            }
            else if (tecla == sf::Keyboard::W) {
                sf::Vector2f pos = corpo.getPosition();
                pos.y = pos.y - velocidade.y;
                corpo.setPosition(pos);
            }
            else if (tecla == sf::Keyboard::S) {
                sf::Vector2f pos = corpo.getPosition();
                pos.y = pos.y + velocidade.y;
                corpo.setPosition(pos);
            }
        }


    }
}