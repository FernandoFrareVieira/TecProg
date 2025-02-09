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
            void adicionarObservador();
            void removerObservador();
            void mudarAtivar();
            bool getAtivar() const;
            virtual void notificarSolta(sf::Keyboard::Key tecla) = 0;
            virtual void notificarPressionada(sf::Keyboard::Key tecla) = 0;
    };  
}