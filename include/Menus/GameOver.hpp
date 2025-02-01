#include "Menus/Menu.hpp"
#include "Listas/ListaEntidades.hpp"
#include <iostream>
#include "Entidades/Personagens/Jogador.hpp"
#define MAX_JOGADORES 4

namespace Menus {
    class GameOver : public Menu {
    private:
        std::map<std::string, std::string> jogadores;
        Listas::ListaEntidades* LJ;

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
        std::map<std::string, std::string>* getLista() {return &jogadores;}
    };
}