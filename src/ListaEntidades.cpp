#include "Listas/ListaEntidades.hpp"
#include <iostream>

namespace Listas
{
    ListaEntidades::ListaEntidades(){}
        

    ListaEntidades::~ListaEntidades()
    {

    }

    void ListaEntidades::adicionarEntidade(Entidades::Entidade* entidade)
    {
        LE.incluir(entidade);
    }

    void ListaEntidades::removerEntidade(Entidades::Entidade* entidade)
    {
        LE.remover(entidade);
    }

    void ListaEntidades::executar(){
        Listas::Lista<Entidades::Entidade>::Iterator<Entidades::Entidade> it = LE.getPrimeiro();

        while (it != nullptr) {
            if(!((*it)->getVivo())) {
                //LE.remover(*it);
            }else {
                (*it)->executar();
            }
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
    
    Listas::Lista<Entidades::Entidade>::Iterator<Entidades::Entidade> ListaEntidades::getPrimeiro()
    {
        return LE.getPrimeiro();
    }

    void ListaEntidades::limpar() {
        LE.limpar();
    }

    Entidades::Entidade* ListaEntidades::operator[](int pos)
    {
        return LE.operator[](pos);
    }
}