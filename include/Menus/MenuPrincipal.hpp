
#pragma once

#include "Menus/Menu.hpp"  // Classe base
#include "Observadores/MenuObservador.hpp"

namespace Menus {
    class MenuPrincipal: public Menu {
    private:
        Observadores::MenuObservador* pMenuObservador;
    public:
        MenuPrincipal();
        ~MenuPrincipal();
        void desenhar();   
        void executar(); 
        Observadores::MenuObservador* getObservador();
        int getIndice();
        void selecionar();
    };
}
