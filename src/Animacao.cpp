#include "Animacoes/Animacao.hpp"

namespace Animacoes
{
    float Animacao::FrameAtual::tempoDeTroca = 0.2;

    Gerenciadores::GerenciadorGrafico* Animacao::pGG = Gerenciadores::GerenciadorGrafico::getInstancia();

    Animacao::Animacao(sf::RectangleShape* pCorpo):
        corpo(pCorpo),
        animacaoMap(),
        ID_atual(ID_animacao::andando) 
    {
        //corpo->setScale(sf::Vector2f(7, 7));
    }

    Animacao::~Animacao()
    {
        std::map<ID_animacao, FrameAtual*>::iterator it;
        it = animacaoMap.begin();
        while(it != animacaoMap.end()) {
            delete (it->second);
            it++;
        }

        animacaoMap.clear();
    }

    void Animacao::adicionarAnimacao(ID_animacao id, const char* caminho, int quantImagens)
    {
        FrameAtual* aux = new FrameAtual(caminho, quantImagens);

        if(aux == nullptr) {
            std::cout << "Textura não carregada" << std::endl;
            exit(1);
        }


        animacaoMap.insert(std::pair<ID_animacao, FrameAtual*>(id, aux));

        sf::IntRect tamanhoImagem = aux->getTamanho();
        
        //Valor do sf::Vector2f só para testar para o jogador o certo é tamanhoImagem.width, tamanhoImagem.height
        corpo->setSize(sf::Vector2f(50.0f, 50.0f));
        corpo->setOrigin(sf::Vector2f(50.0f, 50.0f) / 2.0f);
    }

    void Animacao::atualizar(ID_animacao id, bool estaParaEsquerda, sf::Vector2f posicao, float variacaoTempo)
    {
        if(ID_atual != id) {
            ID_atual = id;
            animacaoMap[ID_atual]->reiniciar();
        }

        animacaoMap[ID_atual]->atualizar(variacaoTempo, estaParaEsquerda);
    
        corpo->setTextureRect(animacaoMap[ID_atual]->getTamanho());
        corpo->setTexture(animacaoMap[ID_atual]->getTextura());

        renderizar();
    }

    void Animacao::renderizar()
    {
        
        pGG->desenhar(*corpo);
    }
}