#include "Listas/ListaEntidades.hpp"

namespace Listas
{
    ListaEntidades::ListaEntidades(){}
        

    ListaEntidades::~ListaEntidades()
    {

    }

    void ListaEntidades::executar(){
        Listas::Lista<Entidades::Entidade>::Iterator<Entidades::Entidade> it = LE.getPrimeiro();
        while (it != nullptr) {
            (*it)->executar();
            it++;
        }

    }

    void ListaEntidades::desenhar(){
        Listas::Lista<Entidades::Entidade>::Iterator<Entidades::Entidade> it = LE.getPrimeiro();
        while (it != nullptr) {
            (*it)->desenhar();
        }   it++;
    }

    int ListaEntidades::getTamanho(){
        return LE.getTamanho();
    }

    void ListaEntidades::limpar() {
        LE.limpar();
    }

    void ListaEntidades::incluir(Entidades::Entidade* ent) {
        LE.incluir(ent);
    }

}