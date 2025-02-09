#pragma once
#include "Estados/Estado.hpp"
#include "Menus/MenuPrincipal.hpp"
#include "Menus/MenuPause.hpp"
#include "Menus/GameOver.hpp"
#include "Listas/ListaEntidades.hpp"
#include "Menus/Leaderboard.hpp"
#include "Menus/MenuFases.hpp"
#include <stack>

namespace Fases {
    class Fase;
    class Pantano;
    class Nether;
}

namespace Gerenciadores {
    class GerenciadorEstados {
        protected:
            std::stack<Estados::Estado*> estados;
            int estadoAtual;
            static GerenciadorEstados* instancia;
            Menus::GameOver* pGameOver;
            Listas::ListaEntidades* LJ;
            bool dois_jogadores;

        protected:
            GerenciadorEstados(); //Singleton
            
        public:
            ~GerenciadorEstados();
            static GerenciadorEstados* getInstancia();
            void setEstadoAtual(int id);
            Estados::Estado* getEstadoAtual() const;
            void adicionarEstado(int id);
            void removerEstado();   
            void executar(); 
            void executarGameOver(sf::Event evento);
            int getTamanho();
            void setListaJogadores(Listas::ListaEntidades* listaJogadores) {LJ = listaJogadores;}
            void setMultiplayer(bool doisJ) {dois_jogadores = doisJ;}
            const bool getMultiplayer() const {return dois_jogadores;}
    };
}

