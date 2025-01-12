#include "Tilemap/Tilemap.hpp"

//#include "caminho/até/entidade.hpp"
//#include "classe/diversa/que/vc quer construir.hpp



Tilemap::Tilemap(std::string mapJson)
{   
    carregarMapa(mapJson, "");    
    textura_mapa = new sf::Texture();
}

Tilemap::~Tilemap()
{
    delete textura_mapa;

}

Entidades::Entidade* Tilemap::criarEntidade(sf::Vector2f posicao, sf::Vector2f tamanho, int tipo)
{
    
    switch (tipo){  
        case 1 : //jogador
            return new Entidades::Obstaculos::Plataforma(posicao, tamanho, sf::Vector2f(0,0));
        default:
            return nullptr;
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

void Tilemap::carregarMapa(std::string mapJson, std::string caminhoImagem="") {
    std::ifstream arquivo(mapJson);
    
    if(!arquivo.is_open()){
        std::cerr << "Erro ao abrir o mapa " << mapJson <<std::endl;
        return;
    }

    arquivo >> mapa;
    arquivo.close();

       //se o caminho da imagem não for passado, ele pega o caminho do json e troca a extensão para .png
    if (caminhoImagem == "")
        caminhoImagem = mapJson.substr(0, mapJson.find_last_of(".")) + ".png";

    /*if(!textura_mapa->loadFromFile("include/Tilemap/Assets.png")){ //Está dando seg fault"
        std::cerr << "Erro ao carregar a textura do mapa" << std::endl;
        return;
    }*/
    


}

void Tilemap::criarMapa(Listas::ListaEntidades* LE)
{
    // Pega as informações do mapa
    int sizeTiled = mapa["tilewidth"]; //tamanho do tile
    int width = mapa["width"];
    int height = mapa["height"]; // altura do mapa

    int indice = 0;

    //loop de entidades com tamanho fixo (sizeTiled x sizeTiled)
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int tileId = mapa["layers"][0]["data"][indice++];
            if(tileId != 0){
                sf::Vector2f posicao(x * sizeTiled, y * sizeTiled);
                sf::Vector2f tamanho(sizeTiled, sizeTiled);
                Entidades::Entidade* ent = static_cast<Entidades::Entidade*>(criarEntidade(posicao, tamanho, tileId));
                LE->adicionarEntidade(ent);
            }
        }
    }

    //loop de entidades com tamanho variável em X
    /*for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            long int tileId = mapa["layers"][0]["data"][indice];
            if(tileId != 0){
                int mult = 1;
                while(tileId == mapa["layers"][0]["data"][++indice]){
                    mult++;
                }
                sf::Vector2f posicao(x*sizeTiled, y*sizeTiled);
                x += mult - 1;

                sf::Vector2f tamanho(sizeTiled*mult, sizeTiled);
                Entidade* ent = criarEntidade(posicao, tamanho, tileId); //cria a entidade
                entidades->push_back(ent);  //adiciona a entidade no vetor de entidades
               
            }
            else{
                indice++;
            }
        }
    }*/

}