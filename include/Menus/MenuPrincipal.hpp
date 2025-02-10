
#pragma once

#include "Menus/Menu.hpp"  // Classe base
#include "Gerenciadores/GerenciadorEstados.hpp"


namespace Menus {
    class MenuPrincipal: public Menu {
    private:
        sf::Text nomeJogo;
        sf::Font fonte;
    public:
        MenuPrincipal(int id);
        ~MenuPrincipal();
        void desenhar();
        void executar();
    };
}
