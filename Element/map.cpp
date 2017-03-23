#include "map.hpp"

// A faire, appliquer les textures correctement
// Verification


/*** Methode Map ***/

Map::Map(int sizeX, int sizeY){
    this->_sizeX = sizeX;
    this->_sizeY = sizeY;
    _world1 = new Unit* [_sizeX];
    _world2 = new Scenery* [_sizeX];
    _mapTile = new Button [_sizeX];
    for(int i =0; i <_sizeX;++i){
        _world1[i]= new Unit[_sizeY];
        _world2[i]= new Scenery[_sizeY];
    }
    _tileClicked = -1;
    setMapClickable();
}

Map::~Map(){
     delete[] _world1;
     delete[] _world2;
}

Unit Map::getElementW1(Position pos)const{
  return(this->_world1[pos.getX()][pos.getY()]);
}

void Map::setElementW1(Position pos,Unit &u){
  this->_world1[pos.getX()][pos.getY()]=u;
}

void Map::setElementW2(Position pos,Scenery &u){
    this->_world2[pos.getX()][pos.getY()]=u;
  }

Scenery Map::getElementW2(Position pos)const{
    return(this->_world2[pos.getX()][pos.getY()]);
}

std::string Map::getNameOfElement(Position pos)const{
     if (this->getElementW1(pos).getName() == "") {
          return(this->getElementW2(pos).getName());
     }else
          return (this->getElementW1(pos).getName());
}


void Map::setElement(Position pos,Element* elt){

}


//  Idée: On a une matrice world2 qui contient tout les éléments de la map
//  Même chose pour world1.
//  Lorsqu'on affiche la map, si world1[x,y] = "vide", alors on affiche world2, sinon on affiche world1.
void Map::createTile(int x, int y, sf::RenderWindow &window,sf::Texture &t){
     sf::RectangleShape rectangle(sf::Vector2f(32, 32));
     Position P;
     P.setX(x);
     P.setY(y);
     std::cout << "Siam\' qui per creare un pezzo di mappa" << '\n';
     if (this->getNameOfElement(P) == "zedd") {

     }
     if (this->getNameOfElement(P) == "putties") {

     }
     if (this->getNameOfElement(P) == "red") {

     }
     if (this->getNameOfElement(P) == "blue") {

     }
     if (this->getNameOfElement(P) == "green") {

     }
     if (this->getNameOfElement(P) == "yellow") {

     }
     if(this->getNameOfElement(P) == "Tree"){
          sf::Sprite s;
          s.setTexture(t);
          s.setTextureRect(sf::IntRect(207, 282, 32, 32));
          // rectangle.setFillColor(sf::Color::Green);
          s.setPosition(x*32,y*32);
          window.draw(s);
     }else if(this->getNameOfElement(P) == "Water"){
          std::cout << "Questo è dell'acqua" << '\n';
          sf::Sprite s;
          s.setTexture(t);
          s.setTextureRect(sf::IntRect(886, 91, 32, 32));
          // rectangle.setFillColor(sf::Color::Blue);
          s.setPosition(x*32,y*32);
          window.draw(s);

     }else if(this->getNameOfElement(P) == "Hill"){
          sf::Sprite s;
          s.setTexture(t);
          s.setTextureRect(sf::IntRect(772, 625, 32, 32));
          // rectangle.setFillColor(sf::Color::Red);
          s.setPosition(x*32,y*32);
          window.draw(s);
     }

}

void Map::drawWorld(sf::RenderWindow &window){
     std::cout << "Iniziamo a creare la mappa" << '\n';
     sf::Texture texture;
     texture.loadFromFile("./Textures/LPC_Terrain/terrain.png");
     for(int i = 0; i< this->_sizeX/32; i++){
          for(int j = 0; j< this->_sizeY/32; j++){

               // rectangle.setFillColor(sf::Color::Yellow);
               std::cout << "i: " << i << "| j :" << j << '\n';
               if(j < 5){
                    Scenery *t = new Tree;
                    _world2[i][j] = *t;
               }
               if(j>= 5){
                    Scenery *w = new Water;
                    _world2[i][j] = *w;
               }
               if(i>= (_sizeX/32)-3){
                    Scenery *h = new Hill;
                    _world2[i][j] = *h;
               }
               createTile(i,j, window,texture);
          }
     }
}

/****************************************/

bool Map::isOnMap(Position pos){
     if(((pos.getX()<0)||(pos.getX()>_sizeX))&&((pos.getY()<0)||(pos.getY()>_sizeY))) {
          std::cerr << "You cannot access this position !" << '\n';
          return false;
     }else
          return true;
}

int Map::getSizeY(){return this->_sizeY;}
int Map::getSizeX(){return this->_sizeX;}
void Map::setSizeY(int y){this->_sizeY = y;}
void Map::setSizeX(int x){this->_sizeX = x;}

void Map::setMapClickable() {
     // _mapTile[0].rect.top = 0;
     // _mapTile[0].rect.left = 0;
     // _mapTile[0].rect.height = 32;
     // _mapTile[0].rect.width = 32;
     // _mapTile[0].action = 0;
     for (int i = 0; i < _sizeX/32; i++) {
          _mapTile[i].rect.top = i*32;
          for (int j = 0; j < _sizeY/32; j++) {
               _mapTile[i].rect.left = j*32;
               _mapTile[i].rect.height = 32;
               _mapTile[i].rect.width = 32;
               _mapTile[i].action = i;
          }
          // std::cout << "i: " << i <<"_mapTile.rect.top: "<< _mapTile[i].rect.top << '\n';
          // std::cout << "i: " << i <<"_mapTile.rect.left: "<< _mapTile[i].rect.left << '\n';
          // std::cout << "i: " << i <<"_mapTile.rect.height: "<< _mapTile[i].rect.height << '\n';
          // std::cout << "i: " << i <<"_mapTile.rect.width: "<< _mapTile[i].rect.width << '\n';
     }

     std::cout << "map is now clickable !" << '\n';
}

void Map::handleClick(sf::RenderWindow &window){
     sf::Event mapEvent;
     bool test = true;
     int i = 0;
     _tileClicked = -1;
     // std::cout << "_tileClicked" <<_tileClicked<< '\n';
     // while(test){
          while (window.pollEvent(mapEvent)) {
               if (mapEvent.type == sf::Event::MouseButtonPressed) {
                    while ((i < _sizeX/32) && (_tileClicked == -1)) {
                         Menu m;
                         std::cout << "i: " << i<< '\n';
                         // std::cout << "actions: "<< _mapTile[i].action << '\n';
                         _tileClicked = m.checkZone(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, _mapTile[i]);
                         test = false;
                         i++;
                         // std::cout << "_tileClicked: " << _tileClicked << '\n';
                    }
                    std::cout << "You clicked on the "<< _tileClicked << "th tile"<< '\n';
                    std::cout << "x: " << sf::Mouse::getPosition(window).x<< " y: " << sf::Mouse::getPosition(window).y << '\n';
               }
          }
     // }
}
