#include "Gerenciadores/GerenciadorGrafico.hpp"

#include <iostream>

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
    {
        pJanela->setFramerateLimit(60);
    }

    GerenciadorGrafico::~GerenciadorGrafico() 
    {
        pJanela = nullptr;
        delete pJanela;
    }

    sf::Texture* GerenciadorGrafico::carregarTextura(std::string caminhoTextura)
    {
        sf::Texture* textura = new sf::Texture();
        if(!textura->loadFromFile(caminhoTextura)) {
            std::cout << "Textura não carregada";
            delete textura;
            return nullptr;
        }

        return textura;
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
            pJanela->clear();
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

    void GerenciadorGrafico::desenhar(sf::RectangleShape& corpo)
    {
        pJanela->draw(corpo);
    }

}