#include "Gerenciadores/GerenciadorEstados.hpp"
#include <stdio.h>

namespace Gerenciadores {
    GerenciadorEstados* GerenciadorEstados::instancia = nullptr;
    GerenciadorEstados::GerenciadorEstados():
    estadoAtual(0)
    {
    }

    GerenciadorEstados::~GerenciadorEstados(){
    }

    GerenciadorEstados* GerenciadorEstados::getInstancia()
    {
        if(instancia == nullptr) {
            instancia = new GerenciadorEstados();
        }
        return instancia;
    }

    void GerenciadorEstados::setEstadoAtual(int id) {
        estadoAtual = id;
    }

    Estados::Estado* GerenciadorEstados::getEstadoAtual() const {
        return estados.top();

    }

    void GerenciadorEstados::addEstado(Estados::Estado* pE) {
        if (pE) {
            printf("ADICIONADO\n");
            fflush(stdout);
            estados.push(pE);
        }
    }  

    void GerenciadorEstados::removerEstado() {
        if (!estados.empty())
            estados.pop();
    }

    void GerenciadorEstados::executar() {
        if (!estados.empty())
            estados.top()->executar();
    }

    
}