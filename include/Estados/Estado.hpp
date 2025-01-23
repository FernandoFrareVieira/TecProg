#pragma once

namespace Gerenciadores {
    class GerenciadorEstados;
}

namespace Estados {
    class Estado {
    protected:
        Gerenciadores::GerenciadorEstados* pEG;
    public:
        Estado();
        virtual ~Estado();
        void setGerenciador(Gerenciadores::GerenciadorEstados* GE) {pEG = GE;}
        virtual void executar() = 0;

    };
}