#include "Entidades/Personagens/Jogador.hpp"
#include <iostream>

namespace Entidades
{
    namespace Personagens
    {
        Jogador::Jogador():
            Personagem()
        {   
            
        }

        Jogador::~Jogador()
        {

        }

        void Jogador::executar()
        {

        }

        void Jogador::desenhar()
        {
            pGG->desenhar(corpo);
        }

    }
}