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
        janela(new sf::RenderWindow(sf::VideoMode(LARGURA, ALTURA), "Teste"))
    {
        janela->setFramerateLimit(60);
    }

    GerenciadorGrafico::~GerenciadorGrafico() 
    {
        if(janela) {
            janela = nullptr;
            delete janela;
        }
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
        return janela->isOpen();
    }

    void GerenciadorGrafico::mostrar() 
    {
        if(janelaAberta()) {
            janela->display();
        }
    }

    void GerenciadorGrafico::limpar() 
    {
        if(janelaAberta()) {
            janela->clear();
        }
    }

    void GerenciadorGrafico::fechar()
    {
        if(janelaAberta()) {
            janela->close();
        }
    }

    sf::RenderWindow* GerenciadorGrafico::getJanela() const
    {
        return janela;
    }

    void GerenciadorGrafico::desenhar(sf::RectangleShape& corpo)
    {
        janela->draw(corpo);
    }

}