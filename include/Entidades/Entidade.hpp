#pragma once

#include "Ente.hpp"
 
namespace Entidades
{
    enum ID
    {
        vazio = 0,
        jogador, 
        arqueiro,
        esqueleto,
        samurai,
        gosma,
        espinho,
        plataforma,
        projetil,
        fogo,
    };

    class Entidade : public Ente
    {
        protected:
            ID id;
            sf::RectangleShape corpo;

            sf::Vector2f posicao; 
            sf::Vector2f tamanho;
            sf::Vector2f velocidade;
            sf::Texture* textura;

            bool vivo;

            //Atributo gravidade
            bool podePular;
            float gravidade; 
            float forcaEmpuxo;

        public: 
            Entidade(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel = sf::Vector2f(0.0f, 0.0f), ID identificador = vazio);
            virtual ~Entidade();

            virtual void executar() = 0;
            virtual void desenhar() = 0;
            sf::RectangleShape* getCorpo();
            ID getId();

            void setPosicao(sf::Vector2f pos);
            sf::Vector2f getPosicao();

            void setTamanho(sf::Vector2f tam);
            sf::Vector2f getTamanho();
            
            void setVelocidade(sf::Vector2f vel);
            sf::Vector2f getVelocidade();

            void setTextura(std::string caminhoTextura);

            virtual void colidir(Entidade* entidade2, sf::Vector2f ds) = 0;

            bool getVivo();

            void atualizarPosicao();
            void setPodePular(bool pPular); 
     };  
}