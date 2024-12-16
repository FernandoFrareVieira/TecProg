#pragma once

#include "Ente.hpp"
 
namespace Entidades
{
    class Entidade : public Ente
    {
        protected:
            const int id;
            static int contador;

            sf::Vector2f posicao;
            sf::Vector2f tamanho;

        public:
            Entidade(sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f), sf::Vector2f tam = sf::Vector2f(0.0f, 0.0f));
            ~Entidade();

            virtual void executar() = 0;
            virtual void desenhar() = 0;
    };  
}