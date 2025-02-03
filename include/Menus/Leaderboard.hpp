#pragma once

#include <iostream>
#include <fstream>
#include "Menus/Menu.hpp"
#define LEADERBOARD "../TecProg/include/Menus/leaderboard.txt"
#include <string>
#include <sstream>

namespace Menus {
    class Leaderboard : public Menu {
    private:
        sf::Font fonte;
        sf::Text textoLeaderboard;
        std::multimap<int, std::string, std::greater<int>> rank;
    public: 
        Leaderboard(int id);
        ~Leaderboard();
        void desenhar();
        void executar();
        void carregar();
    };
}