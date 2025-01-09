#include "Observadores/Observador.hpp"

namespace Observadores {
    Observador::Observador() {
        this->pGG = Gerenciadores::GerenciadorGrafico::getInstancia();
        //this->pGE = Gerenciadores::GerenciadorEventos::getInstancia(jogador);
    }

    Observador::~Observador() {
        
    }
}   