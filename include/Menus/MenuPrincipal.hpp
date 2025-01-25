
#pragma once

#include "Menus/Menu.hpp"  // Classe base
#include "Gerenciadores/GerenciadorEstados.hpp"


namespace Menus {
    class MenuPrincipal: public Menu {
    public:
        MenuPrincipal(int id);
        ~MenuPrincipal();
        void desenhar();   
        void executar(); 
        Observadores::MenuObservador* getObservador();
    };
}
