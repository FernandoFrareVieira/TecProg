#include "Gerenciadores/GerenciadorGrafico.hpp"

namespace Gerenciadores
{
    GerenciadorGrafico* GerenciadorGrafico::instancia = nullptr;

    GerenciadorGrafico* GerenciadorGrafico::getInstancia()
    {
        if(instancia == nullptr) {
            instancia = new GerenciadorGrafico();
        }
        return instancia;
    }

    GerenciadorGrafico::GerenciadorGrafico():
        pJanela(new sf::RenderWindow(sf::VideoMode(800, 600), "Teste"))
    {}

    GerenciadorGrafico::~GerenciadorGrafico() 
    {
        pJanela = nullptr;
        delete pJanela;
    }

    bool GerenciadorGrafico::janelaAberta() const 
    {
        return pJanela->isOpen();
    }

    void GerenciadorGrafico::mostrar() 
    {
        if(janelaAberta()) {
            pJanela->display();
        }
    }

    void GerenciadorGrafico::limpar() 
    {
        if(janelaAberta()) {
            pJanela->clear(sf::Color::Black);
        }
    }

    void GerenciadorGrafico::fechar()
    {
        if(janelaAberta()) {
            pJanela->close();
        }
    }

    sf::RenderWindow* GerenciadorGrafico::getJanela() const
    {
        return pJanela;
    }
}