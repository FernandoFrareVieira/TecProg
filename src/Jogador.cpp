#include "Entidades/Personagens/Jogador.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Entidades/Personagens/Inimigo.hpp"
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
            pontosDeVida = 100;
            estaAtacando = false;
            podeAtacar = true;
            tempoAtacarNovamente = 1.0f; 
            tempoDesdeUltimoAtaque = 0.0f;
            dano = 10;
        
            corpo.setFillColor(sf::Color::Red);

            //textura = pGG->carregarTextura("assets/IDLE.png"); 
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
            atualizarPosicao();
            atualizarAtaque();
            
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

        void Jogador::mover()
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                corpo.move(velocidade.x, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                corpo.move(-velocidade.x, 0);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                pular();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                atacar();
            }
        }

        void Jogador::colidir(Entidade *entidade2, sf::Vector2f ds)
        {
            switch (entidade2->getId())
            {
            case (ID::inimigo):
            {
               if (estaAtacando) {
                    Inimigo* pInimigo = static_cast<Inimigo*>(entidade2);
                    pInimigo->tomarDano(dano);
                    estaAtacando = false;
                }
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
    }
}
