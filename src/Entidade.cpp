#include "Entidades/Entidade.hpp"

namespace Entidades
{
    int Entidade::contador = 0;

    Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, ID identificador):
        Ente(),
        id(identificador),
        tamanho(tam),
        posicao(pos),
        velocidade(vel)
    {
        corpo.setPosition(pos);
        corpo.setSize(tam);
 
        contador++;
    }

    Entidade::~Entidade()
    {}

    sf::RectangleShape* Entidade::getCorpo()
    {
        return &corpo;
    }

    ID Entidade::getId()
    {
        return id;
    }

    void Entidade::setPosicao(sf::Vector2f pos)
    {
        posicao = pos;
    }

    sf::Vector2f Entidade::getPosicao()
    {
        return corpo.getPosition();
    }

    void Entidade::setTamanho(sf::Vector2f tam)
    {
        tamanho = tam;
    }

    sf::Vector2f Entidade::getTamanho()
    {
        return tamanho;
    }

    sf::Vector2f Entidade::getVelocidade()
    {
        return velocidade;
    }

    void Entidade::setVelocidade(sf::Vector2f vel)
    {
        velocidade = vel;
    }

    void Entidade::setTextura(std::string caminhoTextura) {
        textura = pGG->carregarTextura(caminhoTextura);
        corpo.setTexture(textura);
    }

    bool Entidade::getVivo()
    {
        return vivo;
    }
}