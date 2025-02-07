#include "Entidades/Obstaculos/Obstaculo.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Obstaculo::Obstaculo(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, ID identificador):
            Entidade(pos, tam, vel, identificador)
        {
            forçaEmpuxo =  600.0f;
        }

        Obstaculo::~Obstaculo()
        {}

        void Obstaculo::colisaoObstaculo(Entidade* entidade2, sf::Vector2f ds) {
            sf::Vector2f posicao = corpo.getPosition();
            sf::Vector2f tamanho = corpo.getSize();

            sf::Vector2f posicaoEntidade = entidade2->getCorpo()->getPosition();
            sf::Vector2f tamanhoEntidade = entidade2->getCorpo()->getSize();
            sf::Vector2f velocidadeEntidade = entidade2->getVelocidade();

            sf::Vector2f novaVelocidadeEntidade = velocidadeEntidade;

            if (ds.x < ds.y) {
                if (posicaoEntidade.x < posicao.x) {
                    // Entidade está na esquerda do obstáculo
                    entidade2->getCorpo()->setPosition(
                        posicao.x - tamanhoEntidade.x,
                        posicaoEntidade.y
                    );

                    novaVelocidadeEntidade.x = 0.0f;
                
                    
                } else {
                    // Entidade está na direita do obstáculo
                    entidade2->getCorpo()->setPosition(
                        posicao.x + tamanho.x,
                        posicaoEntidade.y
                    );

                    novaVelocidadeEntidade.x = 0.0f;   
                }
            } else {
                if (posicaoEntidade.y < posicao.y) {
                    // Entidade está acima do obstáculo
                    entidade2->getCorpo()->setPosition(
                        posicaoEntidade.x,
                        posicao.y - tamanhoEntidade.y
                    );

                    if (entidade2->getId() == ID::jogador || entidade2->getId() == ID::esquleto || entidade2->getId() == ID::arqueiro) {
                        Personagens::Personagem* pPersonagem = static_cast<Personagens::Personagem*>(entidade2);
                        pPersonagem->setPodePular(true);
                    }
                } else {
                    // Entidade está abaixo do obstáculo
                    entidade2->getCorpo()->setPosition(
                        posicaoEntidade.x,
                        posicao.y + tamanho.y
                    );
                }
            }
        }
    }
}