#include "Gerenciadores/GerenciadorEstados.hpp"
#include "Gerenciadores/GerenciadorEventos.hpp"
#include "Fases/Pantanal.hpp"
#include "Fases/Nether.hpp"
#include <stdio.h>

namespace Gerenciadores {
    GerenciadorEstados* GerenciadorEstados::instancia = nullptr;
    Estados::ID_Estado Gerenciadores::GerenciadorEstados::Estado_ID = Estados::ID_Estado::pantanal;
    GerenciadorEstados::GerenciadorEstados():
    estados(),
    estadoAtual(0),
    LJ(),
    dois_jogadores(false),
    venceu(false)
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

    void GerenciadorEstados::adicionarEstado(int id) {
        if (id == 0) {
            Menus::MenuPrincipal* MenuPrincipal = new Menus::MenuPrincipal(0);
            MenuPrincipal->setID_Estado(Estados::ID_Estado::menu_principal);
            estados.push(MenuPrincipal);
        }
        else if (id == 1) {
            Fases::Pantanal* Pantanal = new Fases::Pantanal(1,dois_jogadores);
            Pantanal->setID_Estado(Estados::ID_Estado::pantanal);
            estados.push(Pantanal);
        }
        else if (id == 2) {
            Menus::MenuPause* MenuPause = new Menus::MenuPause(2);
            MenuPause->setID_Estado(Estados::ID_Estado::menu_pause);
            estados.push(MenuPause);
        }
        else if (id == 3) {
            Fases::Nether* Nether = new Fases::Nether(3,dois_jogadores);
            Nether->setID_Estado(Estados::ID_Estado::nether);
            estados.push(Nether);
        }
        else if (id == 4) {
            pGameOver = new Menus::GameOver(4);
            pGameOver->setID_Estado(Estados::ID_Estado::game_over);
            pGameOver->setListaJogadores(LJ);
            pGameOver->setVenceu(venceu);
            estados.push(pGameOver);
        }
        else if (id == 5) {
            Menus::Leaderboard* pLeaderboard = new Menus::Leaderboard(5);
            pLeaderboard->setID_Estado(Estados::ID_Estado::leaderboard);
            estados.push(pLeaderboard);
        }
        else if (id == 6) {
            Menus::MenuFases* pMenuFases = new Menus::MenuFases(6);
            pMenuFases->setID_Estado(Estados::ID_Estado::menu_fases);
            estados.push(pMenuFases);
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

    void GerenciadorEstados::executarGameOver(sf::Event evento) {
       pGameOver->executar(evento);
        //PontuacaoJogadores = pGameOver->getLista();
    }

    int GerenciadorEstados::getTamanho(){
        return estados.size();
    }
    Estados::Estado* GerenciadorEstados::getPrimeiroEstado(){
        std::deque<Estados::Estado*> &dequeInterno = *reinterpret_cast<std::deque<Estados::Estado*>*>(&estados);
        return dequeInterno.front();
    };

    
}