#pragma once

#include "Ente.hpp"
 
namespace Entidades
{
    enum ID
    {
        vazio = 0,
        jogador, 
        inimigo,
        obstaculo
    };

    class Entidade : public Ente
    {
        protected:
            ID id;
            static int contador;
            sf::RectangleShape corpo;
            sf::Vector2f velocidade;
            
        public:
            Entidade(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, ID identificador = vazio);
            virtual ~Entidade();

            virtual void executar() = 0;
            virtual void desenhar() = 0;
            sf::RectangleShape* getCorpo();
            ID getId();
            sf::Vector2f getVelocidade();
     };  
}