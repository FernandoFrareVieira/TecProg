#include "Menus/Menu.hpp"
#include "Listas/ListaEntidades.hpp"
#include "Entidades/Personagens/Jogador.hpp"
#include "Menus/Leaderboard.hpp"
#include <fstream>
#include <iostream>

#define LEADERBOARD "../TecProg/include/Menus/leaderboard.txt"
#define MAX_JOGADORES 4

namespace Menus {
    class GameOver : public Menu {
    private:
        static std::map<std::string, std::string> jogadores;
        Listas::ListaEntidades* LJ;
        std::string nomePonto;
        sf::Font fonte;
        std::string nomeJogador;
        int pontuacao;

        sf::Text  textoNome;
        sf::Text textoPontuacao;

    public:
        GameOver(int id);
        ~GameOver();
        void desenhar();
        void executar(sf::Event evento);
        void addPontuacao();
        void setListaJogadores(Listas::ListaEntidades* Lista) {LJ = Lista;}
        void salvar();
    };
}