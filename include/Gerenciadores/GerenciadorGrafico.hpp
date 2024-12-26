#pragma once
#define LARGURA 1600
#define ALTURA 900

#include <SFML/Graphics.hpp>

namespace Gerenciadores
{
    class GerenciadorGrafico
    {
        private:
            sf::RenderWindow* janela;
            static GerenciadorGrafico* instancia;
        
            GerenciadorGrafico();
        public:
            static GerenciadorGrafico* getInstancia();
            ~GerenciadorGrafico();
            sf::Texture* carregarTextura(std::string caminhoTextura);
            bool janelaAberta() const;
            void mostrar();
            void limpar();
            void fechar();
            sf::RenderWindow* getJanela() const;
            void desenhar(sf::RectangleShape& corpo);
    };      
}