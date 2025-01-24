#pragma once
#include "Estados/Estado.hpp"
#include "Menus/MenuPrincipal.hpp"
#include "Fases/Fase1.hpp"
#include <stack>

namespace Gerenciadores {
    class GerenciadorEstados {
    protected:
        std::stack<Estados::Estado*> estados;
        int estadoAtual;
        static GerenciadorEstados* instancia;
        GerenciadorEstados(); //Singletron
    public:
        ~GerenciadorEstados();
        static GerenciadorEstados* getInstancia();
        void setEstadoAtual(int id);
        Estados::Estado* getEstadoAtual() const;
        void addEstado(int id);
        void removerEstado();   
        void executar(); 
    };
}

