#include "Estados/MaquinaEstados.hpp"

namespace Estados {
    MaquinaEstados::MaquinaEstados():
    estadoAtual(vazio)
    {

    }

    MaquinaEstados::~MaquinaEstados() {
        
    }

    void MaquinaEstados::mudarEstadoAtual(Estados::estadoID id) {
        estadoAtual = id;
    }

    estadoID MaquinaEstados::getEstadoAtual() const {
        return estadoAtual;
    }

    void MaquinaEstados::addEstado(Estados::Estado* pEstado) {
        mapEstado[pEstado->getID()] = pEstado;
    }

    void MaquinaEstados::executar() {
        mapEstado[estadoAtual]->atualizar();
        mapEstado[estadoAtual]->desenhar();
    }
}