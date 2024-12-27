#pragma once

#include "Ente.hpp"
 
namespace Entidades
{
    class Entidade : public Ente
    {
        protected:
            static int contador;
            sf::RectangleShape corpo;

            //Identificador baseado em número, por enquanto: Jogador: 0, Inimigo: 1, Obstaculo: 2
            const int id;
        public:
            Entidade(sf::Vector2f pos, sf::Vector2f tam, int identificador);
            ~Entidade();

            virtual void executar() = 0;
            virtual void desenhar() = 0;
            sf::RectangleShape* getCorpo();
            int getId();
    };  
}