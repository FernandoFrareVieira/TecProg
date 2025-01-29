#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

namespace Animacoes
{
    class Animacao {
    public:
        Animacao(sf::RectangleShape& body, float switchTime);
        ~Animacao();

        void adicionarFrame(const sf::IntRect& frame);
        void atualizarAnimacao(float dt);

    private:
        sf::RectangleShape& body;
        std::vector<sf::IntRect> frames;
        float switchTime;
        float totalTime;
        size_t currentFrame;
    };
}