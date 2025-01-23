#pragma once

namespace Gerenciadores {
    class GerenciadorEstados;
}

namespace Estados {
    class Estado {
    protected:
        Gerenciadores::GerenciadorEstados* pEG;
        int id;
    public:
        Estado(int id = -1);
        virtual ~Estado();
        void setGerenciador(Gerenciadores::GerenciadorEstados* GE) {pEG = GE;}
        virtual void executar() = 0;

    };
}