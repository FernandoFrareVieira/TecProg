#pragma once

#include "Personagem.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class Jogador : public Personagem
        {
            private:
                int pontos;
            public:
                Jogador();
                ~Jogador();
                void executar();
                void desenhar();
        };
    }
}