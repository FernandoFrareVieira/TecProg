#pragma once
#define LARGURA 1600
#define ALTURA 900

#include <SFML/Graphics.hpp>
#include <iostream>

namespace Gerenciadores
{
    class GerenciadorGrafico
    {
        private:
            sf::RenderWindow* janela;
            static GerenciadorGrafico* instancia;

            sf::View camera;
            sf::Clock relogio;
            float tempo;

            sf::Font fonte;

        private:
            GerenciadorGrafico();

        public:
            static GerenciadorGrafico* getInstancia();
            ~GerenciadorGrafico();
            sf::Texture* carregarTextura(std::string caminhoTextura);
            const bool getJanelaAberta() const;
            void mostrar();
            void limpar();
            void fechar();
            sf::RenderWindow* getJanela() const;
            void centralizarCamera(sf::Vector2f pos);
            void desenhar(sf::RectangleShape& corpo);
            void desenhar(sf::Text& texto);
            void desenharOutros(sf::Drawable& objeto);
            void atualizarTempo();
            float getTempo();
            sf::View getCamera();
            void desenharHUD(const std::string& textoStr, sf::Vector2f offset);
    };      
}