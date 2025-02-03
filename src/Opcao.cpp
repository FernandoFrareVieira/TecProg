#include "Menus/Opcao.hpp"
#include <iostream>

namespace Menus {
    Opcao::Opcao():
    pGG(Gerenciadores::GerenciadorGrafico::getInstancia()),
    corpo(sf::Vector2f(100,100)),
    botao(vazio)
    {
        texto.setOrigin(500, 500);
        corpo.setOrigin(500,500);

        texto.setFillColor(sf::Color::Red);

        texto.setPosition(sf::Vector2f(LARGURA/2,ALTURA/2));

        texto.setCharacterSize(50);
    }

    Opcao::~Opcao() {

    }

    void Opcao::setPosicao(sf::Vector2f posicao) {
        texto.setPosition(posicao);
    }

    void Opcao::setTexto(const std::string text) {
        if (!fonte.loadFromFile("assets/fontes/Ubuntu-R.ttf")) {
            std::cerr << "Erro ao carregar a fonte Ubuntu!" << std::endl;
        }
        texto.setFont(fonte);
        texto.setString(text);
    }

    void Opcao::desenhar() {
        pGG->desenhar(corpo);
        pGG->desenhar(texto);
    }

    void Opcao::mudarCor() {
        if (texto.getFillColor() == sf::Color::Red) {
            texto.setFillColor(sf::Color::Green);
        }
        else {
            texto.setFillColor(sf::Color::Red);
        }
    }
}