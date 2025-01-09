#pragma once

#include "Ente.hpp"
#include "Menus/Opcao.hpp"

namespace Observadores {
    class MenuObservador;  // Declaração antecipada
}


namespace Menus {
    class Menu: public Ente  {
        protected:
            Gerenciadores::GerenciadorGrafico* pGG;
            sf::RectangleShape corpo;

            int num_opcoes;
            int indice_selecionado;

            std::vector<Opcao*> opcoes;
            sf::Color cor_normal;
            sf::Color cor_selecao;
        public:
            Menu(int n_opcoes);
            ~Menu();
            virtual void desenhar();
            void addOpcao(Opcao* op);
            void moverBaixo();
            void moverCima();
            void executar();
            int getIndice() const;
    };
}   