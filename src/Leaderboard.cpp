#include "Menus/Leaderboard.hpp"

namespace Menus {

    Leaderboard::Leaderboard(int id):
    Menu(3,id)  
    {
        opcoes[0]->setTexto("LEADERBOARD");
        if (!fonte.loadFromFile("assets/fontes/Ubuntu-R.ttf")) {
            std::cerr << "Erro ao carregar a fonte Ubuntu!" << std::endl;
        }
        textoLeaderboard.setFont(fonte);
        textoLeaderboard.setCharacterSize(30);
        textoLeaderboard.setFillColor(sf::Color::Black);
        opcoes[1]->setBotao(voltar);
        opcoes[1]->setTexto("Voltar");
        opcoes[1]->setPosicao(sf::Vector2f(1050,1000));

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
        std::istringstream ss(linha);  // Usando istringstream para dividir a linha
        std::string nome;
        int pontuacao;

        // Lê a string até o traço
        std::getline(ss, nome, '-');
        // Lê a pontuação após o traço
        ss >> pontuacao;

        
        rank.insert(std::make_pair(pontuacao, nome));
        if (rank.size() > 3) {
            
            rank.erase(std::prev(rank.end()));
        }  
    }

    arquivo.close();
    for (const auto& entry : rank) {
        //std::cout << entry.second << " - " << entry.first << std::endl;
    }

    }
}