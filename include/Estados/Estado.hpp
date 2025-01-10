#pragma once

namespace Estados {
    class MaquinaEstados;

    enum estadoID {
        vazio = -1,
        menuPrincipal = 0,

    };

    class Estado {
    protected:
        MaquinaEstados* pME;
        estadoID id;
    public :
        Estado(MaquinaEstados* maquina = nullptr, Estados::estadoID id = vazio);
        virtual ~Estado();
        void setMaquinaEstados(MaquinaEstados* maquina) {pME = maquina;}
        void mudarEstado(Estados::estadoID id);
        Estados::estadoID getID() const;
        virtual void atualizar() = 0;
        virtual void desenhar() = 0;
        virtual void resetar();
    };
}