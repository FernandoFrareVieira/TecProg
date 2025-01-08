#pragma once

#include "Gerenciadores/GerenciadorEventos.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Entidades/Personagens/Jogador.hpp"

#include <SFML/Graphics.hpp>

namespace Observadores {
    class Observador {
        protected: 
            Gerenciadores::GerenciadorEventos* pGE;
            Gerenciadores::GerenciadorGrafico* pGG; 
            Entidades::Personagens::Jogador* jogador;
        public:
            Observador();
            ~Observador();
            virtual void atualizar(sf::Keyboard::Key tecla) = 0;
    };
}