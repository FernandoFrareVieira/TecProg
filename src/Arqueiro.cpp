#include "Entidades/Personagens/Arqueiro.hpp"

namespace Entidades
{
    namespace Personagens
    {
        Arqueiro::Arqueiro(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, Jogador* jogador):
            Inimigo(pos, tam, vel, jogador, ID::arqueiro),
            animacao(&corpo, 0.1f),
            listaProjeteis(nullptr)        
        {
            vivo = true;
            pontosDeVida = 40;
            estaAtacando = false;
            podeAtacar = true;
            tempoAtacarNovamente = 2.0f; 
            tempoDesdeUltimoAtaque = 0.0f;
            dano = 10;

            texturaParado = pGG->carregarTextura("assets/arqueiro/Idle.png");

            corpo.setTexture(texturaParado);

            adicionarAnimacoes();
        }

        Arqueiro::~Arqueiro() {
            
        }

        void Arqueiro::executar() {
            float dt = pGG->getTempo();

            atualizarAnimacao(dt);
            atualizarPosicao();
            atacarProjetil();
            desenhar();
            mover();
        }

        void Arqueiro::desenhar() {
            if(vivo) {
                pGG->desenhar(corpo);
            }
         }

        void Arqueiro::atualizarAnimacao(float dt)
        {
            animacao.atualizar(dt);
        }

        void Arqueiro::adicionarAnimacoes()
        {
            int numFramesParado = 7;
            std::vector<sf::IntRect> framesParado(numFramesParado);
            for (int i = 0; i < numFramesParado; i++)
            {
                framesParado[i] = sf::IntRect(40 + 128 * i, 65, 45, 60);
            }

            animacao.adicionarAnimacao("parado", framesParado);

            animacao.setAnimacao("parado");
        }

        void Arqueiro::atacarProjetil()
        {
            float tempoQuePassou = relogio.getElapsedTime().asSeconds();
          
            if(tempoQuePassou >= 2.5f) {
                Entidades::Projetil* projetil = new Entidades::Projetil({corpo.getPosition().x - 20, corpo.getPosition().y} ,sf::Vector2f(64.0f, 64.0f), sf::Vector2f(5.0f, 5.0f));

                if(listaProjeteis)
                    listaProjeteis->adicionarEntidade(static_cast<Entidades::Entidade*>(projetil));
                else
                    delete projetil;

                relogio.restart();
            }
        }

        void Arqueiro::setListaProjeteis(Listas::ListaEntidades* LP)
        {
            listaProjeteis = LP;
        }
    }
}