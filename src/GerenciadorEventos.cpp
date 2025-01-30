#include "Gerenciadores/GerenciadorEventos.hpp"
#include "Gerenciadores/GerenciadorEstados.hpp"

namespace Gerenciadores
{
    GerenciadorEventos* GerenciadorEventos::instancia = nullptr;
    Listas::ListaObservadores* GerenciadorEventos::LO = nullptr;

    GerenciadorEventos* GerenciadorEventos::getInstancia()
    {
        if(instancia == nullptr) {
            instancia = new GerenciadorEventos();
        }
        return instancia;
    }

    GerenciadorEventos::GerenciadorEventos():
    pGG(Gerenciadores::GerenciadorGrafico::getInstancia())
    {
        LO = new Listas::ListaObservadores();
    }

    GerenciadorEventos::~GerenciadorEventos()
    {
        if(LO) {
            delete(LO);
            LO = nullptr;
        }
    }

    void GerenciadorEventos::addObservador(Observadores::Observador* observador) {
        LO->add(observador);
    }

    void GerenciadorEventos::removerObservador(Observadores::Observador* observador) {
        LO->removerObservador(observador);
    }

    void GerenciadorEventos::executar()
    {
        gEstados = Gerenciadores::GerenciadorEstados::getInstancia();
        sf::Event evento;
        while(pGG->getJanela()->pollEvent(evento)) {
            if(evento.type == sf::Event::Closed) {
                pGG->fechar();
            }else if(evento.type == sf::Event::KeyPressed) {
                //pJogador->mover(evento.key.code);
                /////
                if (gEstados->getEstadoAtual()->getID() == 1 || gEstados->getEstadoAtual()->getID() == 3) { //Fazer Observador fase
                    if (evento.key.code == sf::Keyboard::Key::Escape) {
                        gEstados->addEstado(2);

                    }
                }
                if (gEstados->getEstadoAtual()->getID() == 0 || gEstados->getEstadoAtual()->getID() == 2) {
                    LO->notificarTeclaPressionada(evento.key.code);
                }
            }
            else if(evento.type == sf::Event::KeyReleased) {
                if (gEstados->getEstadoAtual()->getID() == 0 || gEstados->getEstadoAtual()->getID() == 2) {
                    LO->notificarTeclaSolta(evento.key.code);
                }
            }
        }
    }
}