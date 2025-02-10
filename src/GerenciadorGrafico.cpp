#include "Gerenciadores/GerenciadorGrafico.hpp"
#include <stdexcept>

namespace Gerenciadores
{
    GerenciadorGrafico* GerenciadorGrafico::instancia = nullptr;

    GerenciadorGrafico* GerenciadorGrafico::getInstancia()
    {
        if(instancia == nullptr) {
            instancia = new GerenciadorGrafico();
        }
        return instancia;
    }

    GerenciadorGrafico::GerenciadorGrafico():
        janela(new sf::RenderWindow(sf::VideoMode(LARGURA, ALTURA), "ShadowBlade")),
        camera(sf::Vector2f(LARGURA / 2, ALTURA / 2), sf::Vector2f(LARGURA, ALTURA)),
        tempo(0.0f)
    {
        janela->setFramerateLimit(60);

        sf::Font fonte;
        if (!fonte.loadFromFile("assets/fontes/DungeonFont.ttf")) {
            std::cerr << "Erro ao carregar a fonte DungeonFont!" << std::endl;
        }
    }

    GerenciadorGrafico::~GerenciadorGrafico() 
    {
        if(janela) {
            janela = nullptr;
            delete janela;
        }
    }

    sf::Texture* GerenciadorGrafico::carregarTextura(std::string caminhoTextura)
    {
        sf::Texture* textura = new sf::Texture();
        try {
            textura->loadFromFile(caminhoTextura);
        }
        catch(const std::invalid_argument& caminhoTextura) {
            std::cout <<"ARGUMENTO INVÁLIDO"<<std::endl;
        }
        return textura;
    }

    const bool GerenciadorGrafico::getJanelaAberta() const 
    {
        return janela->isOpen();
    }

    void GerenciadorGrafico::mostrar() 
    {
        if(getJanelaAberta()) {
            janela->display();
        }
    }

    void GerenciadorGrafico::limpar() 
    {
        if(getJanelaAberta()) {
            janela->clear();
        }
    }

    void GerenciadorGrafico::fechar()
    {
        if(getJanelaAberta()) {
            janela->close();
        }
    }

    sf::RenderWindow* GerenciadorGrafico::getJanela() const
    {
        return janela;
    }

    void GerenciadorGrafico::centralizarCamera(sf::Vector2f pos)
    {
        camera.setSize(1200,1000);
        sf::FloatRect limiteMundo(-90,100,3180,1000);

        float suavidade = 0.05;
        sf::Vector2f centroAtual = camera.getCenter();
        sf::Vector2f novoCentro = centroAtual +suavidade*(pos - centroAtual);
        novoCentro.x = std::clamp(novoCentro.x, limiteMundo.left + camera.getSize().x / 2, limiteMundo.left + limiteMundo.width - camera.getSize().x / 2);
        novoCentro.y = std::clamp(novoCentro.y, limiteMundo.top + camera.getSize().y / 2, limiteMundo.top + limiteMundo.height - camera.getSize().y / 2);
        camera.setCenter(novoCentro);
        janela->setView(camera);
    }

    void GerenciadorGrafico::desenhar(sf::RectangleShape& corpo)
    {
        janela->draw(corpo);
    }

    void GerenciadorGrafico::desenhar(sf::Text& texto){
        janela->draw(texto);

    }

    void GerenciadorGrafico::atualizarTempo()
    {
        tempo = relogio.getElapsedTime().asSeconds();
        relogio.restart();
    }

    void GerenciadorGrafico::desenharOutros(sf::Drawable &objeto) {
        janela->draw(objeto);
    }

    float GerenciadorGrafico::getTempo()
    {
        return tempo;
    }

    sf::View GerenciadorGrafico::getCamera() {
        return camera;
    }

    void GerenciadorGrafico::desenharHUD(const std::string& textoStr, sf::Vector2f offset)
    {
        sf::Text texto;

        texto.setFont(fonte);
        texto.setCharacterSize(24);
        texto.setFillColor(sf::Color::White);
        texto.setString("diowamdwiamdwiam");

        sf::Vector2f cameraCentro = camera.getCenter();
        sf::Vector2f cameraTamanho = camera.getSize();

        // Calcula a posição relativa ao canto superior esquerdo da tela
        sf::Vector2f posicaoTexto(cameraCentro.x - cameraTamanho.x / 2 + offset.x, 
                                cameraCentro.y - cameraTamanho.y / 2 + offset.y);

        texto.setPosition(posicaoTexto);
        janela->draw(texto);
    }
}