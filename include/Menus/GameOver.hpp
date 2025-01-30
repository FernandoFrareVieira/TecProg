#include "Menus/Menu.hpp"
#include "Listas/ListaEntidades.hpp"
#include <iostream>

namespace Menus {
    class GameOver : public Menu {
    private:
        std::map<std::string, std::string> jogadores;
        Listas::ListaEntidades listaJogadores;
    public:
        GameOver(int id);
        ~GameOver();
        void desenhar();
        void executar();
        void addPontuacao();
        std::map<std::string, std::string> getLista() {return jogadores;}
    };
}