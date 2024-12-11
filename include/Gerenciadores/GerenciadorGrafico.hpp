#pragma once

#include <SFML/Graphics.hpp>

namespace Gerenciadores
{
    class GerenciadorGrafico
    {
        private:
            sf::RenderWindow* pJanela;
            static GerenciadorGrafico* instancia;
        
            GerenciadorGrafico();
        public:
            static GerenciadorGrafico* getInstancia();
            ~GerenciadorGrafico();
            bool janelaAberta() const;
            void mostrar();
            void limpar();
            void fechar();
            sf::RenderWindow* getJanela() const;
    };      
}