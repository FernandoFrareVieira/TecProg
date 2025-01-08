#include "Entidades/Personagens/Jogador.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include <iostream>

namespace Entidades
{
    namespace Personagens
    {
        Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel):
            Personagem(pos, tam, vel, ID::jogador),
            animacao(&corpo)
        {   
            vivo = true;
            vida = 100;

            animacao.adicionarAnimacao(Animacoes::ID_animacao::andando, "assets/jogador/andando.png", 10);

            //corpo.setFillColor(sf::Color::Red);

            //textura = pGG->carregarTextura("assets/jogador/IDLE.png"); 
            //corpo.setSize(sf::Vector2f(LARGURA/30.0f,ALTURA/7.5f));
            //corpo.setTextureRect(sf::IntRect(40,48,15,33));
            //corpo.setFillColor(sf::Color::White);
            //corpo.setTexture(textura);
        }

        Jogador::~Jogador()
        {
            
        }

        void Jogador::executar()
        {
            atualizar(pGG->getTempo());
            desenhar();
        }

        void Jogador::desenhar()
        {
            animacao.renderizar();
        }

        void Jogador::atualizar(float dt)
        {
            animacao.atualizar(Animacoes::ID_animacao::andando, false, corpo.getPosition(), dt);
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