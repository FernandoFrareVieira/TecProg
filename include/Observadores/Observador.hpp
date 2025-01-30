#pragma once

#include "Gerenciadores/GerenciadorGrafico.hpp"

#include <SFML/Graphics.hpp>

namespace Gerenciadores {
    class GerenciadorEventos;
    class GerenciadorEstados;
}

namespace Observadores {
    class Observador {
        protected: 
            static Gerenciadores::GerenciadorEventos* pGEventos;
            Gerenciadores::GerenciadorGrafico* pGG;
            static Gerenciadores::GerenciadorEstados* pGEstados; 
        private:
            bool ativo;
        public:
            Observador();
            virtual ~Observador();
            void removerObservador();
            virtual void notificarSolta(sf::Keyboard::Key tecla) {}
            virtual void notificarPressionada(sf::Keyboard::Key tecla) {}
            void mudarAtivar();
            bool getAtivar() const;
    };  
}