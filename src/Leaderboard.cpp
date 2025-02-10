#include "Menus/Leaderboard.hpp"

namespace Menus {

    Leaderboard::Leaderboard(int id):
    Menu(1,id)  
    {
<<<<<<< HEAD
        if (!fonte.loadFromFile("assets/fontes/ThaleahFat.ttf")) {
            std::cerr << "Erro ao carregar a fonte Ubuntu!" << std::endl;
=======
        if (!fonte.loadFromFile("assets/fontes/DungeonFont.ttf")) {
            std::cerr << "Erro ao carregar a fonte DungeonFont!" << std::endl;
>>>>>>> 1b9222d136fd38220475b7520100bcb5fb81e54c
        }
        textoLeaderboard.setFont(fonte);
        textoLeaderboard.setCharacterSize(30);
        textoLeaderboard.setFillColor(sf::Color::Black);
        opcoes[0]->setBotao(voltar);
        opcoes[0]->setTexto("Voltar");
        opcoes[0]->setPosicao(sf::Vector2f(1050,1000));
        opcoes[0]->mudarCor();

    }

    Leaderboard::~Leaderboard() {

    }

    void Leaderboard::desenhar() {
        corpo.setFillColor(sf::Color::White);
        pGG->desenhar((corpo));
        if (num_opcoes > 0) {
            for (int i = 0; i < num_opcoes; i++) {
            opcoes[i]->desenhar();
            }
        }
        int contador = 0;
        std::string texto;
        for (const auto& pair : rank) {
            if (contador >= 3) break;  // Limita a 3 melhores pontuações
            texto += pair.second + " - " + std::to_string(pair.first) + "\n";
            textoLeaderboard.setString(texto);
            textoLeaderboard.setPosition(550,120 + 80*contador);
            contador++;
        }
        pGG->desenharOutros(textoLeaderboard);
    }

    void Leaderboard::executar() {
        carregar(); 
        desenhar();
    }

    void Leaderboard::carregar() {
    std::ifstream arquivo(LEADERBOARD);
    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        exit(1);
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::istringstream ss(linha);
        std::string nome;
        int pontuacao;

        std::getline(ss, nome, '-');
        ss >> pontuacao;

        // Verifica se o nome já existe no ranking
        bool nomeExiste = false;
        for (const auto& par : rank) {
            if (par.second == nome) {
                nomeExiste = true;
                break;
            }
        }

        // Se o nome não existe, adiciona ao ranking
        if (!nomeExiste) {
            rank.insert(std::make_pair(pontuacao, nome));

            // Mantém apenas os 3 melhores
            if (rank.size() > 3) {
                rank.erase(std::prev(rank.end()));
            }
        }
    }
    arquivo.close();
    for (const auto& entry : rank) {
        //std::cout << entry.second << " - " << entry.first << std::endl;
    }

    }
}