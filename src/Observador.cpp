#include "Observadores/Observador.hpp"

#include "Gerenciadores/GerenciadorEstados.hpp"
#include "Gerenciadores/GerenciadorEventos.hpp"


namespace Observadores {
    Gerenciadores::GerenciadorEstados* Observador::pGEstados = Gerenciadores::GerenciadorEstados::getInstancia();
    Gerenciadores::GerenciadorEventos* Observador::pGEventos = Gerenciadores::GerenciadorEventos::getInstancia();
    Observador::Observador():
    ativo(true)
    {
        this->pGG = Gerenciadores::GerenciadorGrafico::getInstancia();
        pGEventos->adicionarObservador(this);
        //this->pGE = Gerenciadores::GerenciadorEventos::getInstancia(jogador);
    }

    Observador::~Observador() {
        removerObservador();
    }

    void Observador::mudarAtivar() {
        ativo != ativo;
    }

    bool Observador::getAtivar() const {
        return ativo;
    }

    void Observador::removerObservador() {
        pGEventos->removerObservador(this);
    }
    
    void Observador::adicionarObservador() {
        pGEventos->adicionarObservador(this);
    }
}   