#include "Entidades/Personagens/Samurai.hpp"

namespace Entidades
{
    namespace Personagens
    {
        Samurai::Samurai(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, Jogador* jogador):
            Inimigo(pos, tam, vel, jogador, ID::samurai),
            animacao(&corpo, 0.1f),
            listaProjeteis(nullptr)        
        {
            vivo = true;
            pontosDeVida = 100;
            estaAtacando = false;
            podeAtacar = true;
            tempoAtacarNovamente = 2.0f; 
            tempoDesdeUltimoAtaque = 0.0f;
            dano = 20;

            texturaParado = pGG->carregarTextura("assets/samurai/Idle.png");

            corpo.setTexture(texturaParado);

            adicionarAnimacoes();
        }

        Samurai::~Samurai() {
            
        }

        void Samurai::executar() {
            float dt = pGG->getTempo();

            atualizarAnimacao(dt);
            atualizarPosicao();
            atualizarAtaque();
            atacarProjetil();
            desenhar();
            mover();
        }

        void Samurai::desenhar() {
            if(vivo) {
                pGG->desenhar(corpo);
            }
         }

        void Samurai::atualizarAnimacao(float dt)
        {
            animacao.atualizar(dt);
        }

        void Samurai::adicionarAnimacoes()
        {
            int numFramesParado = 9;
            std::vector<sf::IntRect> framesParado(numFramesParado);
            for (int i = 0; i < numFramesParado; i++)
            {
                framesParado[i] = sf::IntRect(40 + 128 * i, 20, 40, 108);
            }

            animacao.adicionarAnimacao("parado", framesParado);

            animacao.setAnimacao("parado");
        }

        void Samurai::atacarProjetil()
        {
            float tempoQuePassou = relogio.getElapsedTime().asSeconds();
          
            if(tempoQuePassou >= 3.5f) {
                Entidades::Projetil* projetil = new Entidades::Projetil({corpo.getPosition().x - 20, corpo.getPosition().y} ,sf::Vector2f(64.0f, 64.0f), sf::Vector2f(5.0f, 5.0f));

                if(listaProjeteis)
                    listaProjeteis->adicionarEntidade(static_cast<Entidades::Entidade*>(projetil));
                else
                    delete projetil;

                relogio.restart();
            }
        }

        void Samurai::setListaProjeteis(Listas::ListaEntidades* LP)
        {
            listaProjeteis = LP;
        }
    }
}