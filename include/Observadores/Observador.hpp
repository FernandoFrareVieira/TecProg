#pragma once

#include "Gerenciadores/GerenciadorEventos.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"

#include <SFML/Graphics.hpp>

namespace Observadores {
    class Observador {
        protected: 
            //Gerenciadores::GerenciadorEventos* pGE;
            Gerenciadores::GerenciadorGrafico* pGG; 
        public:
            Observador();
            virtual ~Observador();
            virtual void atualizar(sf::Keyboard::Key tecla) = 0;
    };
}