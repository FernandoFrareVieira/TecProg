#pragma once
#include "Estados/Estado.hpp"
#include "Menus/MenuPrincipal.hpp"
#include "Menus/MenuPause.hpp"
#include "Menus/GameOver.hpp"
#include "Listas/ListaEntidades.hpp"
#include <stack>

namespace Fases {
    class Fase;
    class Fase1;
    class Nether;
}

namespace Gerenciadores {
    class GerenciadorEstados {
    protected:
        std::stack<Estados::Estado*> estados;
        int estadoAtual;
        static GerenciadorEstados* instancia;
        GerenciadorEstados(); //Singletron
        Menus::GameOver* pGameOver;
        Listas::ListaEntidades* LJ;
    public:
        ~GerenciadorEstados();
        static GerenciadorEstados* getInstancia();
        void setEstadoAtual(int id);
        Estados::Estado* getEstadoAtual() const;
        void addEstado(int id);
        void removerEstado();   
        void executar(); 
        void executarGameOver(sf::Event evento);
        int getTamanho();
        void setListaJogadores(Listas::ListaEntidades* lista) {LJ = lista;}
    };
}

