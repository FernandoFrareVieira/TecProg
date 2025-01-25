#include "Gerenciadores/GerenciadorEstados.hpp"
#include "Gerenciadores/GerenciadorEventos.hpp"
#include <stdio.h>

namespace Gerenciadores {
    GerenciadorEstados* GerenciadorEstados::instancia = nullptr;
    
    GerenciadorEstados::GerenciadorEstados():
    estados(),
    estadoAtual(0)
    {
    }

    GerenciadorEstados::~GerenciadorEstados(){
        while (!estados.empty()) {
            delete estados.top();
            estados.top() == nullptr;
            estados.pop();
        }
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

    void GerenciadorEstados::addEstado(int id) {
        if (id == 0) {
            estados.push(new Menus::MenuPrincipal(0));
        }
        else if (id == 1) {
            estados.push(new Fases::Fase1(1));
        }
        else if (id == 2) {
            estados.push(new Menus::MenuPause(2));
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

    int GerenciadorEstados::getTamanho(){
        return estados.size();
    }

    
}