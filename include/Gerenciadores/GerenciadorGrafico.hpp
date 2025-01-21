#pragma once
#define LARGURA 1600
#define ALTURA 900

#include <SFML/Graphics.hpp>
namespace Entidades {
    namespace Personagens {
        class Jogador;
    }
}

namespace Gerenciadores
{
    class GerenciadorGrafico
    {
        private:
            sf::RenderWindow* janela;
            sf::View camera;
            sf::Clock relogio;
            float tempo;
            Entidades::Personagens::Jogador* pJogador;

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
            void centralizarCamera(sf::Vector2f pos);
            void desenhar(sf::RectangleShape& corpo);
            void desenhar(sf::Text& texto);
            void desenharOutros(sf::Drawable& objeto);
            void atualizarTempo();
            float getTempo();
            void setJogador(Entidades::Personagens::Jogador* jogador) {pJogador = jogador;}
    };      
}