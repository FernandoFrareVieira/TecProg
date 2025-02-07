#include "Entidades/Projetil.hpp"

namespace Entidades
{
    Projetil::Projetil(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel):
        Entidade(pos, tam, vel, ID::projetil)
    {
        vivo = true;
        tempoDeVida = 2.0f;
        dano = 10;

        textura = pGG->carregarTextura("assets/arqueiro/Flecha.png");
        corpo.setTexture(textura);
        corpo.setTextureRect(sf::IntRect(0, 0, 48, 48));
    }

    Projetil::~Projetil()
    {

    }

    void Projetil::executar()
    {
        float tempoQuePassou = relogio.getElapsedTime().asSeconds();

        if(tempoQuePassou >= 4.0f) {
            vivo = false;
            relogio.restart();
        }

        if(vivo) {
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
        corpo.move(-velocidade.x, 0.0f);
    }

    void Projetil::colidir(Entidades::Entidade* entidade2, sf::Vector2f ds)
    {
        if(entidade2->getId() == ID::jogador) {
            Personagens::Personagem* pPersonagem = static_cast<Personagens::Personagem*>(entidade2);  
            pPersonagem->tomarDano(dano);

            vivo = false;
        }
    }
}