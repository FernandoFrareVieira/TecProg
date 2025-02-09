    #include "Observadores/FaseObservador.hpp"
#include "Gerenciadores/GerenciadorEstados.hpp"
#include "Fases/Fase.hpp"

namespace Observadores {
    FaseObservador* FaseObservador::instancia = nullptr;
    FaseObservador* FaseObservador::getInstancia() {
        if (instancia == nullptr) {
            instancia = new FaseObservador();
        }
        return instancia;
    }
    FaseObservador::FaseObservador():
    Observador(), fase(nullptr)
    {
        
    }

    FaseObservador::~FaseObservador() {
        if (fase) {
            //fase = nullptr;
        }
    }

    void FaseObservador::notificarMudarFase() {
        if (pGEstados->getEstadoAtual()->getID_Estado() == Estados::ID_Estado::pantanal) {
            pGEstados->removerEstado();
            pGEstados->adicionarEstado(3);
        }
    }

    void FaseObservador::notificarGameOver() {
        pGEstados->removerEstado();
        pGEstados->adicionarEstado(4);
    }

    void FaseObservador::notificarPressionada(sf::Keyboard::Key tecla){
    }

    void FaseObservador::notificarSolta(sf::Keyboard::Key tecla) {
    }

    void FaseObservador::notificarSalvamento() {
        if (fase) {
            fase->salvar("saves/save.dat");
        }
    }

    void FaseObservador::notificarCarregamento() {
        if (fase) {
            fase->carregar("saves/save.dat");
        }
    }
 }