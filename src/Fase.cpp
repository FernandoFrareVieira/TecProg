#include "Fases/Fase.hpp"

namespace Fases
{
    Fase::Fase():
        listaObstaculos(),
        listaInimigos(),
        listaJogadores(),
        corpo(),
        pGC()
    {
        pGC.setObstaculos(&listaObstaculos);
        pGC.setInimigos(&listaInimigos);
        pGC.setJogadores(&listaJogadores);
    }

    Fase::~Fase()
    {
        
    }

    void Fase::criarObstaculos(Entidades::Entidade* obstaculo)
    {
        if(obstaculo) {
            listaObstaculos.adicionarEntidade(obstaculo);
        }
    }

    void Fase::criarInimigos(Entidades::Entidade* inimigo)
    {
        if(inimigo) {
            listaInimigos.adicionarEntidade(inimigo);
        }
    }

    void Fase::criarJogador(Entidades::Entidade* jogador)
    {
        if(jogador) {
            listaJogadores.adicionarEntidade(jogador);
        }
    }
}