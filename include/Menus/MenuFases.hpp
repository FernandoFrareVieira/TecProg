#include "Menus/Menu.hpp"

namespace Menus {
    class MenuFases : public Menu {
    private:
        bool EntrouEmFases;
    public:
        MenuFases(int id);
        ~MenuFases();
        void desenhar();
        void executar(); 
    };
}