#pragma once

#include "Ente.hpp"
 
namespace Entidades
{
    class Entidade : public Ente
    {
        protected:
            const int id;
            static int contador;
            sf::RectangleShape corpo;

        public:
            Entidade(sf::Vector2f pos, sf::Vector2f tam);
            ~Entidade();

            virtual void executar() = 0;
            virtual void desenhar() = 0;
            const sf::RectangleShape getCorpo() const;
    };  
}