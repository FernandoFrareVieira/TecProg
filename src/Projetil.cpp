#include "Entidades/Projetil.hpp"

namespace Entidades
{
    Projetil::Projetil(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, bool pDireita):
        Entidade(pos, tam, vel, ID::projetil),
        paraDireita(pDireita)
    {
        vivo = true;
        tempoDeVida = 2.0f;
        dano = 10;

        if(!paraDireita) {
            textura = pGG->carregarTextura("assets/flecha/flecha.png");
            corpo.setTexture(textura);
            corpo.setTextureRect(sf::IntRect(0, 20, 48, 10));
       }else {
            textura = pGG->carregarTextura("assets/flecha/flechaEsquerda.png");
            corpo.setTexture(textura);
            corpo.setTextureRect(sf::IntRect(0, 20, 48, 10));
        }
    }

    Projetil::~Projetil()
    {
        if(textura) {
            delete textura;
            textura = nullptr;
        }
    }

    void Projetil::executar()
    {
        float tempoQuePassou = relogio.getElapsedTime().asSeconds();

        if(tempoQuePassou >= 2.0f) {
            dano = 0;
            vivo = false;
            relogio.restart();
        }

        if(vivo) {
            atualizarPosicao();
            desenhar();
            mover();
        }
    }

    void Projetil::desenhar()
    {
        if(vivo) {
            pGG->desenhar(corpo);
        }
    }

    void Projetil::mover()
    {
        if(paraDireita) {
            corpo.move(velocidade.x, 0.0f);
        }else {
            corpo.move(-velocidade.x, 0.0f);
        }
    }

    void Projetil::colidir(Entidades::Entidade* entidade2, sf::Vector2f ds)
    {
        if(entidade2->getId() == ID::jogador) {
            Personagens::Personagem* pPersonagem = static_cast<Personagens::Personagem*>(entidade2);  
            pPersonagem->tomarDano(dano);

            vivo = false;
            dano = 0;
        }
    }
}