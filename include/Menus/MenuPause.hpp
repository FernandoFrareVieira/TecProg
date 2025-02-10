#include "Menus/Menu.hpp"

namespace Menus {
    class MenuPause : public Menu {
    private:
        bool entrouEmPause;
    public:
        MenuPause(int id);
        ~MenuPause();
        void executar();
        void desenhar();
        
    };
}