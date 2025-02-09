#pragma once

namespace Gerenciadores {
    class GerenciadorEstados;
}

namespace Estados {
    enum ID_Estado {
        empty = -1,
        menu_principal = 0,
        pantanal = 1,
        menu_pause = 2,
        nether = 3,
        game_over = 4,
        leaderboard = 5,
        menu_fases = 6,
    };
    class Estado {
    protected:
        Gerenciadores::GerenciadorEstados* pEG;
        int id;
        ID_Estado idEstado;
    public:
        Estado(int id = -1);
        virtual ~Estado();
        void setGerenciador(Gerenciadores::GerenciadorEstados* GE) {pEG = GE;}
        virtual void executar() = 0;
        int getID();
        void setID_Estado(ID_Estado ID) {idEstado = ID;}
        const ID_Estado getID_Estado() const {return idEstado;}

    };
}