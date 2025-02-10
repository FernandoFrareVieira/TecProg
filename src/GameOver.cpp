#include "Menus/GameOver.hpp"

namespace Menus {
    std::map<std::string, std::string> Menus::GameOver::jogadores;

    GameOver::GameOver(int id):
    Menus::Menu(1,id),
    pontuacao(0),
    nomeJogador(""),
    LJ()
    {
        this->corpo.setSize(sf::Vector2f(LARGURA,ALTURA));
        corpo.setFillColor(sf::Color::White);
        if (!fonte.loadFromFile("assets/fontes/ThaleahFat.ttf")) {
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
        opcoes[0]->setTexto("MENU PRINCIPAL");
        opcoes[0]->setBotao(menu_principal);
        opcoes[0]->mudarCor();
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
        if (evento.key.code == sf::Keyboard::Enter) {
            salvar(); // Adiciona ao mapa
        }
        for (int i = 0; i < LJ->getTamanho(); i++) {
            Entidades::Entidade* entidade = LJ->operator[](i);

            Entidades::Personagens::Jogador* jogador = dynamic_cast<Entidades::Personagens::Jogador*>(entidade);
            pontuacao += jogador->getPontuacao();
        }
        textoNome.setString("Jogador: " + nomeJogador);
        textoPontuacao.setString("Pontos: " + std::to_string(pontuacao));
        nomePonto = nomeJogador + "-" + std::to_string(pontuacao);
        pontuacao = 0;
    }

    void GameOver::salvar() {
    std::ofstream arquivo(LEADERBOARD, std::ios::app);  // "app" faz com que o arquivo não seja sobrescrito
    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo para salvar! Caminho: " << LEADERBOARD << std::endl;
        perror("Erro do sistema");
        return;
    }
    else {
        std::cerr << "SALVO COM SUCESSO" << std::endl;
    }
    arquivo << nomePonto << std::endl;

    arquivo.close();
    }



}