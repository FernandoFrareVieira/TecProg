#pragma once

#include "Observadores/Observador.hpp"
#include "Menus/Opcao.hpp"


namespace Menus {
    class Menu: public Ente  {
        protected:
            Gerenciadores::GerenciadorGrafico* pGG;
            sf::RectangleShape corpo;

            const int num_opcoes;
            int indice_selecionado;

            std::vector<Opcao*> opcoes;
            sf::Color cor_normal;
            sf::Color cor_selecao;
        public:
            Menu(int n_opcoes);
            ~Menu();
            virtual void desenhar();
            void addOpcao(Opcao* op);
            int getIndice() const;
    };
}   