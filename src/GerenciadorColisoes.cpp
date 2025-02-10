#include "Gerenciadores/GerenciadorColisoes.hpp"
#include <cmath>
#include <iostream>

namespace Gerenciadores {
    GerenciadorColisoes::GerenciadorColisoes():
        listaInimigos(nullptr),
        listaJogadores(nullptr),
        listaObstaculos(nullptr),
        listaProjeteis(nullptr)
    {
    
    }

    GerenciadorColisoes::~GerenciadorColisoes() 
    {

    }


    void GerenciadorColisoes::setObstaculos(Listas::ListaEntidades* LO)
    {
        if(LO)
            listaObstaculos = LO;
    }

    void GerenciadorColisoes::setInimigos(Listas::ListaEntidades* LI)
    {
        if(LI)
            listaInimigos = LI;
    }

    void GerenciadorColisoes::setJogadores(Listas::ListaEntidades* LJ)
    {
        if(LJ)
            listaJogadores = LJ;
    }

    void GerenciadorColisoes::setProjeteis(Listas::ListaEntidades* LP)
    {
        if(LP)
            listaProjeteis = LP;
    }

    void GerenciadorColisoes::gerenciar() {
        sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f);

        reiniciaPulo();

        //Colisão jogadores com obstaculos e inimigos
        for(int i = 0; i < listaJogadores->getTamanho(); i++) {
            Entidades::Entidade* entidade1 = listaJogadores->operator[](i);

            //Colisão jogadores com inimigos
            for(int j = 0; j < listaInimigos->getTamanho(); j++) {
                Entidades::Entidade* entidade2 = listaInimigos->operator[](j);
                ds = calculaColisao(entidade1, entidade2);

                if(ds.x > 0.0f && ds.y > 0.0f) {
                    entidade1->colidir(entidade2, ds);
                    entidade2->colidir(entidade1, ds);
                }
            }

            //Colisão jogadores com obstaculos
            for(int j = 0; j < listaObstaculos->getTamanho(); j++) {
                Entidades::Entidade* entidade2 = listaObstaculos->operator[](j);
                ds = calculaColisao(entidade1, entidade2);

                if(ds.x > 0.0f && ds.y > 0.0f) {
                    entidade1->colidir(entidade2, ds);
                    entidade2->colidir(entidade1, ds);
                }
            }

            //Colisão jogadores com projeteis
            for(int j = 0; j < listaProjeteis->getTamanho(); j++) {
                Entidades::Entidade* entidade2 = listaProjeteis->operator[](j);
                ds = calculaColisao(entidade1, entidade2);

                if(ds.x > 0.0f && ds.y > 0.0f) {
                    entidade1->colidir(entidade2, ds);
                    entidade2->colidir(entidade1, ds);
                }
            }
        }

        for(int i = 0; i < listaObstaculos->getTamanho(); i++) {
            Entidades::Entidade* entidade1 = listaObstaculos->operator[](i);

            for(int j = 0; j < listaInimigos->getTamanho(); j++) {
                Entidades::Entidade* entidade2 = listaInimigos->operator[](j);
                ds = calculaColisao(entidade1, entidade2);

                if(ds.x > 0.0f && ds.y > 0.0f) {
                    entidade1->colidir(entidade2, ds);
                    entidade2->colidir(entidade1, ds);
                }
            }

            for(int j = 0; j < listaProjeteis->getTamanho(); j++) {
                Entidades::Entidade* entidade2 = listaProjeteis->operator[](j);
                ds = calculaColisao(entidade1, entidade2);

                if(ds.x > 0.0f && ds.y > 0.0f) {
                    entidade1->colidir(entidade2, ds);
                    entidade2->colidir(entidade1, ds);
                }
            }
        }
    }
    
    sf::Vector2f GerenciadorColisoes::calculaColisao(Entidades::Entidade* entidade1, Entidades::Entidade* entidade2) {
        sf::RectangleShape* corpo1 = entidade1->getCorpo();
        sf::RectangleShape* corpo2 = entidade2->getCorpo();

        sf::Vector2f centro1 = corpo1->getPosition() + corpo1->getSize() / 2.0f;
        sf::Vector2f centro2 = corpo2->getPosition() + corpo2->getSize() / 2.0f;
        float dist_x = centro1.x - centro2.x;
        float dist_y = centro1.y - centro2.y;
        float limite_x = (corpo1->getSize().x + corpo2->getSize().x) / 2.0f;
        float limite_y = (corpo1->getSize().y + corpo2->getSize().y) / 2.0f;

        if (fabs(dist_x) < limite_x && fabs(dist_y) < limite_y) {
            float overlap_x = limite_x - fabs(dist_x);
            float overlap_y = limite_y - fabs(dist_y);

            return sf::Vector2f(overlap_x, overlap_y);
        }

        return sf::Vector2f(0.0f, 0.0f);
    }

    void GerenciadorColisoes::reiniciaPulo()
    {
        for (int i = 0; i < listaJogadores->getTamanho(); i++) {
            Entidades::Entidade* entidade = listaJogadores->operator[](i);

            Entidades::Personagens::Personagem* pPersonagem = static_cast<Entidades::Personagens::Personagem*>(entidade);
            pPersonagem->setPodePular(false); // Reseta para falso
        }

        for (int i = 0; i < listaInimigos->getTamanho(); i++) {
            Entidades::Entidade* entidade = listaInimigos->operator[](i);

            Entidades::Personagens::Personagem* pPersonagem = static_cast<Entidades::Personagens::Personagem*>(entidade);
            pPersonagem->setPodePular(false); // Reseta para falso
        }
    }
}