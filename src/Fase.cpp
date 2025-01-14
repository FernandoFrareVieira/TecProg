#include "Fases/Fase.hpp"

namespace Fases
{
    Fase::Fase():
        listaObstaculos(),
        listaInimigos(),
        listaJogadores(),
        corpo(),
        pGC()
    {
        pGC.setObstaculos(&listaObstaculos);
        pGC.setInimigos(&listaInimigos);
        pGC.setJogadores(&listaJogadores);
    }

    Fase::~Fase()
    {
        
    }

    void Fase::adicionarObstaculos(Entidades::Entidade* obstaculo)
    {
        if(obstaculo) {
            listaObstaculos.adicionarEntidade(obstaculo);
        }
    }

    void Fase::adicionarInimigos(Entidades::Entidade* inimigo)
    {
        if(inimigo) {
            listaInimigos.adicionarEntidade(inimigo);
        }
    }

    void Fase::adicionarJogador(Entidades::Entidade* jogador)
    {
        if(jogador) {
            listaJogadores.adicionarEntidade(jogador);
        }
    }


    void Fase::carregarMapa(std::string mapJson, std::string caminhoImagem) {
    std::ifstream arquivo(mapJson);
    
    if(!arquivo.is_open()){
        std::cerr << "Erro ao abrir o mapa " << mapJson <<std::endl;
        return;
    }

    if (!tilesetTextura.loadFromFile(caminhoImagem)) {
        std::cerr <<"Erro ao abrir textura " << std::endl;
    }

    arquivo >> mapa;
    
    int sizeTiled = mapa["tilewidth"];
    int width = mapa["width"];
    int height = mapa["height"];

    int indice = 0;

    //loop de entidades com tamanho fixo (sizeTiled x sizeTiled)
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int tileId = mapa["layers"][0]["data"][indice++];
            if(tileId != 0){
                sf::Vector2f posicao(x * sizeTiled, y * sizeTiled);
                sf::Vector2f tamanho(sizeTiled, sizeTiled);
                criarEntidade(posicao,tamanho, tileId);
            }
        }
    }
    
    }

    void Fase::criarEntidade(sf::Vector2f posicao, sf::Vector2f tamanho, int tipo)
{
    
    switch (tipo){  
        case 16 : //plataforma
            adicionarObstaculos(new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0)));
    }
    /*
        case 2 : //plataforma sprite 1
            return new Plataforma(posicao, tamanho, tipo);
            break;
        case 3 : //plataforma sprite 2
            return new Plataforma(posicao, tamanho, tipo);
            break;
        ...
    }
     - ASSIM POR DIANTE PARA CADA TIPO DE ENTIDADE QUE VC NECESSITA CRIAR
    */
}
}