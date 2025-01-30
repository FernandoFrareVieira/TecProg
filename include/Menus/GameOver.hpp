#include "Menus/Menu.hpp"
#include "Listas/ListaEntidades.hpp"
#include <iostream>

namespace Menus {
    class GameOver : public Menu {
    private:
        std::map<std::string, std::string> jogadores;
        Listas::ListaEntidades listaJogadores;

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
        std::map<std::string, std::string> getLista() {return jogadores;}
    };
}