#include "Estados/Estado.hpp"
#include "Estados/MaquinaEstados.hpp"

namespace Estados {
    Estado::Estado(MaquinaEstados* maquina, Estados::estadoID id) :
    pME(maquina),
    id(id) {}
    
    Estado::~Estado() {
        pME = nullptr;
    }

    Estados::estadoID Estado::getID() const {
        return id;
    }

    void Estado::resetar() {}

}