#include "Menus/Opcao.hpp"

namespace Menus {
    Opcao::Opcao():
    pGG(Gerenciadores::GerenciadorGrafico::getInstancia())
    {
        texto.setCharacterSize(30);

        corpo.setOrigin(LARGURA/2,ALTURA/2);
        texto.setOrigin(LARGURA/2.2, ALTURA/2.2);
    }

    Opcao::~Opcao() {

    }

    void Opcao::setPosicao(sf::Vector2f posicao) {
        texto.setPosition(posicao);
        corpo.setPosition(posicao);
    }

    void Opcao::setTexto(const std::string text) {
        texto.setString(text);
    }

    void Opcao::desenhar() {
        pGG->desenhar(corpo);
        pGG->desenhar(texto);
    }
}