#include "Menus/Menu.hpp"
#include "Observadores/MenuObservador.hpp"

namespace Menus {
    Menu::Menu(int n_opcoes, int id):
    Ente(),
    Estado(id),
    opcoes(),
    pMenuObservador(nullptr),
    indice_selecionado(0),
    num_opcoes(n_opcoes)
    {
        pGG = Gerenciadores::GerenciadorGrafico::getInstancia();
        corpo.setPosition(sf::Vector2f(1200,300));
        for (int i = 0; i < num_opcoes; i++) {
            Opcao* op = new Opcao();
            op->setPosicao(sf::Vector2f(1050,700 + 100*i));
            addOpcao(op);

        }
        corpo.setSize(sf::Vector2f(LARGURA,ALTURA));
        if (!textura.loadFromFile("assets/cenarios/cenarioMenu.png")){
            printf("ERROU\n");
            fflush(stdout);
        }
        corpo.setTexture(&textura);
        corpo.setPosition(sf::Vector2f(0,0));
        pGG->getJanela()->setView(pGG->getJanela()->getDefaultView());
        pMenuObservador = new Observadores::MenuObservador();
        if (pMenuObservador != nullptr) {
            pMenuObservador->setMenu(this);     
        }
    }

    Menu::~Menu() {
        for (int i = 0; i < num_opcoes; i++) {
            delete opcoes[i];
        }
        if (pMenuObservador)
            delete pMenuObservador;
        pMenuObservador = nullptr;
    }

    void Menu::desenhar() {
        if (num_opcoes > 0) {
            for (int i = 0; i < num_opcoes; i++) {
            opcoes[i]->desenhar();
            }
        }
    }

    void Menu::addOpcao(Opcao* op) {
        if (op)
            opcoes.push_back(op);
    }

    int Menu::getIndice() const {
        return indice_selecionado;
    }

    void Menu::moverBaixo() {
        if (indice_selecionado > 0) {
            opcoes[indice_selecionado]->mudarCor();
            indice_selecionado--;
            opcoes[indice_selecionado]->mudarCor();
        }
    }

    void Menu::moverCima() {
        if (indice_selecionado < num_opcoes - 1) {
            opcoes[indice_selecionado]->mudarCor();
            indice_selecionado++;
            opcoes[indice_selecionado]->mudarCor();
        }
    }

    void Menu::executar() {
        desenhar();
    }
}