#include "Gerenciadores/GerenciadorEventos.hpp"
#include "Observadores/MenuObservador.hpp"

namespace Gerenciadores
{
    GerenciadorEventos* GerenciadorEventos::instancia = nullptr;

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

    }

    GerenciadorEventos::~GerenciadorEventos()
    {
    }

    void GerenciadorEventos::executar()
    {
        sf::Event evento;
        while(pGG->getJanela()->pollEvent(evento)) {
            if(evento.type == sf::Event::Closed) {
                pGG->fechar();
            }else if(evento.type == sf::Event::KeyPressed) {
                //pJogador->mover(evento.key.code);
                //pMenu->atualizar(evento.key.code);
            }
        }
    }
}