#include "Menus/GameOver.hpp"

namespace Menus {
    GameOver::GameOver(int id):
    Menus::Menu(0,id),
    pontuacao(0),
    nomeJogador("teste")
    {
        this->corpo.setSize(sf::Vector2f(LARGURA,ALTURA));
        corpo.setFillColor(sf::Color::White);
        if (!fonte.loadFromFile("assets/fontes/Ubuntu-R.ttf")) {
            std::cerr << "Erro ao carregar a fonte Ubuntu!" << std::endl;
        }
        textoNome.setFont(fonte);
        textoNome.setCharacterSize(30);
        textoNome.setFillColor(sf::Color::Black);
        textoNome.setPosition(550, 400);

        textoPontuacao.setFont(fonte);
        textoPontuacao.setCharacterSize(30);
        textoPontuacao.setFillColor(sf::Color::Black);
        textoPontuacao.setPosition(550, 450);
        
    }

    GameOver::~GameOver() {

    }

    void GameOver::desenhar() {
        pGG->desenhar((corpo));
        if (num_opcoes > 0) {
            for (int i = 0; i < num_opcoes; i++) {
            opcoes[i]->desenhar();
            }
        }
        pGG->desenharOutros(textoNome);
        pGG->desenharOutros(textoPontuacao);
    }

    void GameOver::addPontuacao() {
    if (!nomeJogador.empty()) {
        jogadores[nomeJogador] = std::to_string(pontuacao);
        std::cout << "Nome salvo: " << nomeJogador << " - Pontuação: " << pontuacao << std::endl;
        }   
    }

    void GameOver::executar(sf::Event evento){
        if (evento.type == sf::Event::TextEntered) {
            if (evento.text.unicode < 128) {
                char typedChar = static_cast<char>(evento.text.unicode);

                // Se pressionar Backspace, remove um caractere
                if (typedChar == '\b' && !nomeJogador.empty()) {
                    nomeJogador.pop_back();
                }
                // Se for um caractere válido e não for Enter
                else if (typedChar != '\b' && typedChar != '\r' && nomeJogador.size() < 10) {
                    nomeJogador += typedChar;
                }
            }
        }
        if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Enter) {
            addPontuacao(); // Adiciona ao mapa
            printf("ADICIONOU PONTUAÇÃO\n");
            fflush(stdout);
        }
        textoNome.setString("Nome: " + nomeJogador);
        textoPontuacao.setString("Pontuacao: " + std::to_string(pontuacao));
    }
}