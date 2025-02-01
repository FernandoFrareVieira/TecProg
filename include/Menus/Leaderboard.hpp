#pragma once

#include <iostream>
#include <fstream>
#include "Menus/Menu.hpp"

namespace Menus {
    class Leaderboard : public Menu {
    private:
        sf::Font fonte;
        sf::Text textoLeaderboard;
         std::map<std::string, std::string> jogadores;
    public: 
        Leaderboard(int id);
        ~Leaderboard();
        void desenhar();
        void executar();
    };
}