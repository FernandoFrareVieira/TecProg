#include "Menus/Menu.hpp"

namespace Menus {
    class MenuPause : public Menu {
    public:
        MenuPause(int id);
        ~MenuPause();
        void executar();
        void desenhar();
        
    };
}