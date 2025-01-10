#pragma once
#include "Estado.hpp"
#include <map>

namespace Estados {
    class MaquinaEstados {
    protected:
        Estados::estadoID estadoAtual;
        std::map<estadoID, Estados::Estado*> mapEstado;
    public:
        MaquinaEstados();
        ~MaquinaEstados();
        void mudarEstadoAtual(Estados::estadoID id);
        void addEstado(Estados::Estado* pEstado);
        estadoID getEstadoAtual() const;
        void executar();
    };
}