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
            pontosDeVida = 20;
            estaAtacando = false;
            podeAtacar = true;
            tempoAtacarNovamente = 2.0f; 
            tempoDesdeUltimoAtaque = 0.0f;
            dano = 0;

            texturaParado = pGG->carregarTextura("assets/arqueiro/Idle.png");
            texturaAtacando = pGG->carregarTextura("assets/arqueiro/Shot_1.png");

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

         void Arqueiro::atualizarAnimacao(float dt) {
            // Obtém o tempo decorrido desde que o relógio foi iniciado ou reiniciado
            float tempoDecorrido = relogioAnimacao.getElapsedTime().asSeconds();
        
            if (tempoDecorrido < 1.0f) {
                // Animação "parado"
                if (animacao.getAnimacaoAtual() != "parado") {
                    animacao.setTextura(texturaParado);
                    animacao.setAnimacao("parado");
                    corpo.setSize(sf::Vector2f(80.0f, 80.0f));
                }
            } else if (tempoDecorrido < 1.0f + 1.5f) {
                // Animação "atacando"
                if (animacao.getAnimacaoAtual() != "atacando") {
                    animacao.setTextura(texturaAtacando);
                    animacao.setAnimacao("atacando");
                    corpo.setSize(sf::Vector2f(90.0f, 80.0f));
                }
            } else {
                // Reinicia o relógio para começar um novo ciclo
                relogioAnimacao.restart();
            }
        
            // Atualiza a animação (se necessário, passe um delta time aqui)
            animacao.atualizar(dt); // Ou use um delta time, se a animação precisar
        }

        void Arqueiro::adicionarAnimacoes()
        {
            int numFramesParado = 7;
            std::vector<sf::IntRect> framesParado(numFramesParado);
            for (int i = 0; i < numFramesParado; i++)
            {
                framesParado[i] = sf::IntRect(40 + 128 * i, 65, 45, 60);
            }

            int numFramesAtacando = 15;
            std::vector<sf::IntRect> framesAtacando(numFramesAtacando);

            for (int i = 0; i < numFramesAtacando; i++){
                framesAtacando[i] = sf::IntRect(30 + 128 * i, 60, 60, 70);
            }

            animacao.adicionarAnimacao("parado", framesParado);
            animacao.adicionarAnimacao("atacando", framesAtacando);

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