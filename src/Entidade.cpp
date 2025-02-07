#include "Entidades/Entidade.hpp"
#include <iostream>

namespace Entidades
{
    int Entidade::contador = 0;

    Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, ID identificador) : 
        Ente(),
        id(identificador),
        tamanho(tam),
        posicao(pos),
        velocidade(vel),
        vivo(true),
        podePular(false),
        gravidade(600.0f),
        forçaEmpuxo(0.0f)
    {
        corpo.setPosition(pos);
        corpo.setSize(tam);

        contador++;
    }

    Entidade::~Entidade()
    {
    }

    sf::RectangleShape *Entidade::getCorpo()
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

    void Entidade::setTextura(std::string caminhoTextura)
    {
        textura = pGG->carregarTextura(caminhoTextura);
        corpo.setTexture(textura);
    }

    bool Entidade::getVivo()
    {
        return vivo;
    }

    void Entidade::atualizarPosicao()
    {
        float dt = pGG->getTempo();

        if(getId() == ID::jogador) {
            //std::cout << podePular << std::endl;
        }

        if (!podePular)
        {
            velocidade.y += (gravidade - forçaEmpuxo) * dt;
        }

        corpo.move(velocidade.x * dt, velocidade.y * dt);
    }

    void Entidade::setPodePular(bool pPular)
    {
        podePular = pPular;

        if(podePular) {
            velocidade.y = 0.0f;
        }
    }
}