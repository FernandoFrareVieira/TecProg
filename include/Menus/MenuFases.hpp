#include "Menus/Menu.hpp"

namespace Menus {
    class MenuFases : public Menu {
    private:
    
    public:
        MenuFases(int id);
        ~MenuFases();
        void desenhar();
        void executar(); 
    };
}