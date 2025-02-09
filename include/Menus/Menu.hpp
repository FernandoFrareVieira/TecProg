#pragma once

#include "Ente.hpp"
#include "Menus/Opcao.hpp"
#include "Estados/Estado.hpp"

namespace Observadores {
    class MenuObservador;  // Declaração antecipada
}


namespace Menus {

    class Menu: public Ente, public Estados::Estado  {
        protected:
            sf::RectangleShape corpo;
            sf::Texture textura;

            int num_opcoes;
            int indice_selecionado;

            std::vector<Opcao*> opcoes;
            sf::Color cor_normal;
            sf::Color cor_selecao;
            Observadores::MenuObservador* pMenuObservador;
        public:
            Menu(int n_opcoes, int id);
            ~Menu();
            void addOpcao(Opcao* op);
            void moverBaixo();
            void moverCima();
            virtual void desenhar();
            virtual void executar();
            int getIndice() const;
            BOTOES getBotao() const {return opcoes[indice_selecionado]->getBotao();}
    };
}   