#include "Entidades/Obstaculos/Obstaculo.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Obstaculo::Obstaculo(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel):
            Entidade(pos, tam, vel, ID::obstaculo)
        {}

        Obstaculo::~Obstaculo()
        {}

        void Obstaculo::colisaoObstaculo(Entidade* entidade2, sf::Vector2f ds) {
            sf::Vector2f posicao = corpo.getPosition();
            sf::Vector2f tamanho = corpo.getSize();

            sf::Vector2f posicaoEntidade = entidade2->getCorpo()->getPosition();
            sf::Vector2f tamanhoEntidade = entidade2->getCorpo()->getSize();

            if (ds.x < ds.y) {
                if (posicaoEntidade.x < posicao.x) {
                    // Entidade está na esquerda do obstaculo
                    entidade2->getCorpo()->move(-ds.x, 0.0f);
                } else {
                    // Entidade está na direita do obstaculo
                    entidade2->getCorpo()->move(ds.x, 0.0f);
                }
            } else {
                if (posicaoEntidade.y < posicao.y) {
                    // Entidade está acima do obstaculo 
                    entidade2->getCorpo()->move(0.0f, -ds.y);

                    if(entidade2->getId() == ID::jogador || entidade2->getId() == ID::inimigo) {
                        Personagens::Personagem* pPersonagem = static_cast<Personagens::Personagem*>(entidade2);
                        pPersonagem->setPodePular(true);
                    }

                } else {
                    // Entidade está abaixo do obstaculo
                    entidade2->getCorpo()->move(0.0f, ds.y);
                }
            }
        }

    }
}