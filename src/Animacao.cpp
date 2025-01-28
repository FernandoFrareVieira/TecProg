#include "Animacoes/Animacao.hpp"

namespace Animacoes
{
    Animacao::Animacao(sf::RectangleShape& body, float switchTime): 
        body(body), 
        switchTime(switchTime), 
        totalTime(0.f), 
        currentFrame(0) 
    {}

    Animacao::~Animacao()
    {}

    void Animacao::adicionarFrame(const sf::IntRect& frame) {
        frames.push_back(frame);
    }

    void Animacao::atualizarAnimacao(float deltaTime) {
        if (frames.empty()) return;

        totalTime += deltaTime;

        if (totalTime >= switchTime) {
            totalTime -= switchTime;
            currentFrame = (currentFrame + 1) % frames.size();
            body.setTextureRect(frames[currentFrame]);
        }
    }
}