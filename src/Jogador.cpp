#include "Entidades/Personagens/Jogador.hpp"
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
            corpo.setTexture(textura);
            corpo.setTextureRect(sf::IntRect(0, 0, 120, 120));
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
        }


    }
}