#include "Animacoes/Animacao.hpp"

namespace Animacoes {
    Animacao::Animacao(sf::RectangleShape* corpo, float tempoTroca):
        corpo(corpo), 
        textura(nullptr), 
        tempoTroca(tempoTroca), 
        tempoAtual(0), 
        indiceAtual(0), 
        animacaoAtual("")
    {}

    Animacao::~Animacao() {}

    void Animacao::setTextura(sf::Texture* textura) {
        this->textura = textura;
        if (corpo) corpo->setTexture(textura);
    }

    void Animacao::adicionarAnimacao(std::string nome, std::vector<sf::IntRect> quadros) {
        animacoes[nome] = {quadros, static_cast<int>(quadros.size())};
        if (animacaoAtual.empty()) {
            setAnimacao(nome);
        }
    }

    void Animacao::setAnimacao(std::string nome) {
        if (animacoes.find(nome) != animacoes.end()) {
            animacaoAtual = nome;
            indiceAtual = 0;
            corpo->setTextureRect(animacoes[nome].quadros[indiceAtual]);
        }
    }

    void Animacao::atualizar(float dt) {
        if (animacaoAtual.empty() || animacoes.find(animacaoAtual) == animacoes.end()) return;

        tempoAtual += dt;
        if (tempoAtual >= tempoTroca) {
            tempoAtual = 0;
            indiceAtual = (indiceAtual + 1) % animacoes[animacaoAtual].indiceMax;
            corpo->setTextureRect(animacoes[animacaoAtual].quadros[indiceAtual]);
        }
    }

    std::string Animacao::getAnimacaoAtual()
    {
        return animacaoAtual;
    }
}
