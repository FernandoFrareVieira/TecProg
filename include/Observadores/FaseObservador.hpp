#pragma once

#include "Observador.hpp"
#include "Entidades/Personagens/Jogador.hpp"

namespace Fases {
    class Fase;
}


namespace Observadores {
    class FaseObservador: public Observador {
    private :
        Fases::Fase* fase;
        FaseObservador();
        static FaseObservador* instancia;
    public:
        ~FaseObservador();
        static FaseObservador* getInstancia();
        void notificarMudarFase();
        void notificarGameOver();
        void notificarSalvamento();
        void notificarCarregamento();
        void notificarSolta(sf::Keyboard::Key tecla); //completar
        void notificarPressionada(sf::Keyboard::Key tecla); //completar
        void setFase(Fases::Fase* pFase) {fase = pFase;}
    };
}