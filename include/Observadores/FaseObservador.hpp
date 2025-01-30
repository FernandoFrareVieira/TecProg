#pragma once

#include "Observador.hpp"
#include "Entidades/Personagens/Jogador.hpp"

namespace Observadores {
    class FaseObservador: public Observador {
    private :
        Entidades::Personagens::Jogador* pJogador1;
    public:
        FaseObservador();
        ~FaseObservador();
        void notificarMudarFase();
        void notificarGameOver();
        void notificarPressionada(sf::Keyboard::Key tecla); //completar
        void notificarSolta(sf::Keyboard::Key tecla); //completar
    };
}