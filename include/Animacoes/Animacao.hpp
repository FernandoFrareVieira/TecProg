#ifndef ANIMACAO_HPP
#define ANIMACAO_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include <string>

namespace Animacoes {
    class Animacao {
    private:
        struct dadosAnimacao {
            std::vector<sf::IntRect> quadros;
            int indiceMax;
        };

        sf::RectangleShape* corpo;
        sf::Texture* textura;
        std::map<std::string, dadosAnimacao> animacoes;
        std::string animacaoAtual;
        float tempoTroca;
        float tempoAtual;
        int indiceAtual;

    public:
        Animacao(sf::RectangleShape* corpo, float tempoTroca);
        ~Animacao();

        void setTextura(sf::Texture* textura);
        void adicionarAnimacao(std::string nome, std::vector<sf::IntRect> quadros);
        void setAnimacao(std::string nome);
        void atualizar(float dt);

        std::string getAnimacaoAtual();
    };
}

#endif
