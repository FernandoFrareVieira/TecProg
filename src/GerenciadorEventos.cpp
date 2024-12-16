#include "Gerenciadores/GerenciadorEventos.hpp"

namespace Gerenciadores
{
    GerenciadorEventos* GerenciadorEventos::instancia = nullptr;

    GerenciadorEventos* GerenciadorEventos::getInstancia(Entidades::Personagens::Jogador* jogador)
    {
        if(instancia == nullptr) {
            instancia = new GerenciadorEventos(jogador);
        }
        return instancia;
    }

    GerenciadorEventos::GerenciadorEventos(Entidades::Personagens::Jogador* jogador):
        pGG(Gerenciadores::GerenciadorGrafico::getInstancia())
    {
        pJogador = jogador;
    }

    GerenciadorEventos::~GerenciadorEventos()
    {
        pJogador = nullptr; 
    }

    void GerenciadorEventos::executar()
    {
        sf::Event evento;
        while(pGG->getJanela()->pollEvent(evento)) {
            if(evento.type == sf::Event::Closed) {
                pGG->fechar();
            }else if(evento.type == sf::Event::KeyPressed) {
                pJogador->mover(evento.key.code);
            }
        }
    }
}