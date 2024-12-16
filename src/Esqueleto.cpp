#include "Entidades/Personagens/Esqueleto.hpp"

namespace Entidades
{
    namespace Personagens
    {
        Esqueleto::Esqueleto(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel):
            Inimigo(pos, tam, vel)
        {
            textura = pGG->carregarTextura("assets/esqueleto.png");
            corpo.setTexture(textura);
            corpo.setTextureRect(sf::IntRect(0, 0, 60, 60));
        }
         Esqueleto::~Esqueleto() {}

        void Esqueleto::executar() {}

        void Esqueleto::desenhar() {
            pGG->desenhar(corpo);
         }

        void Esqueleto::mover() {}
    }
}
