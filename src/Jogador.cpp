#include "Entidades/Personagens/Jogador.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include <iostream>

namespace Entidades
{
    namespace Personagens
    {
        Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel)
            : Personagem(pos, tam, vel, ID::jogador), animacao(&corpo)
        {
            vivo = true;
            vida = 100;
            podePular = false;

            gravidade = 500.0f;        
            velocidadePulo = -300.0f;  

            corpo.setFillColor(sf::Color::Red);
        }

        Jogador::~Jogador()
        {
        }

        void Jogador::executar()
        {
            atualizarPosicao();
            desenhar();
            mover();
        }

        void Jogador::desenhar()
        {
            pGG->desenhar(corpo);
        }

        void Jogador::atualizarAnimacao(float dt)
        {
            animacao.atualizar(Animacoes::ID_animacao::andando, false, corpo.getPosition(), dt);
        }

        void Jogador::atualizarPosicao()
        {
            float dt = pGG->getTempo(); 

       
            if (!podePular)
            {
                velocidade.y += gravidade * dt;
            }

            corpo.move(0, velocidade.y * dt);
        }

        void Jogador::mover()
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                corpo.move(velocidade.x, 0);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                corpo.move(-velocidade.x, 0);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                pular();
            }
        }

        void Jogador::pular()
        {
            if (podePular)
            {
                velocidade.y = velocidadePulo; 
                podePular = false;    
            }
        }

        void Jogador::colidir(Entidade *entidade2, sf::Vector2f ds)
        {
            switch (entidade2->getId())
            {
            case (ID::inimigo):
            {
                tomarDano(10);
            }
            break;

            case (ID::obstaculo):
            {
               
            }
            break;

            default:
            {
            }
            break;
            }
        }

        void Jogador::setPodePular(bool pPular)
        {
            podePular = pPular;
        }
    }
}
