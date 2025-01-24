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
            virtual void notificar(sf::Keyboard::Key tecla) = 0;
            void mudarAtivar();
            bool getAtivar() const;
    };  
}