
#pragma once

#include "Menus/Menu.hpp"  // Classe base
#include "Gerenciadores/GerenciadorEstados.hpp"


namespace Menus {
    class MenuPrincipal: public Menu {
    private:
        Observadores::MenuObservador* pMenuObservador;
    public:
        MenuPrincipal(int id);
        ~MenuPrincipal();
        void desenhar();   
        void executar(); 
        Observadores::MenuObservador* getObservador();
        int getIndice();
        void selecionar();
    };
}
