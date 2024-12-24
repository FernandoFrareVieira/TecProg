#pragma once
#include "Entidades/Entidade.hpp"
#include "Entidades/Personagens/Personagem.hpp"

namespace Gerenciadores {
    class GerenciadorColisoes {
    private:
        Entidades::Personagens::Personagem* ent1;
        Entidades::Personagens::Personagem* ent2;
    public:
        GerenciadorColisoes();
        ~GerenciadorColisoes();
        //void colisao();
        void gerenciar(Entidades::Personagens::Personagem *ente1, Entidades::Personagens::Personagem *ente2);

               
    };
}