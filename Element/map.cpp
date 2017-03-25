#include "map.hpp"

// A faire, appliquer les textures correctement
// Verification


/*** Methode Map ***/

Map::Map(int sizeX, int sizeY){
    this->_sizeX = sizeX;
    this->_sizeY = sizeY;
    this->_compttab = 0;
    _tab = new Unit[6];
    _world1 = new Unit* [_sizeX];
    _world2 = new Scenery* [_sizeX];
    _mapTile = new sf::Sprite* [(_sizeX/32)];
    for(int i =0; i <_sizeX;++i){
        _world1[i]= new Unit[_sizeY];
        _world2[i]= new Scenery[_sizeY];
    }
    for (int i = 0; i < _sizeX/32; i++) {
         _mapTile[i] = new sf::Sprite[_sizeY/32];
    }
    _tileClicked = 0;
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

int Map::getCompt()const{
  return(this->_compttab);
}

void Map::setCompt(int c){
  this->_compttab = c;
}
/*
void Map::setInTab(Unit& u){
  this->_tab[getCompt()] = u;
  setCompt((this->getCompt())+1);
}
*/
Unit Map::getTab(int pos)const{
  return(this->_tab[pos]);
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
          _mapTile[x][y] = s;
     }else if(this->getNameOfElement(P) == "Water"){
          sf::Sprite s;
          s.setTexture(t);
          s.setTextureRect(sf::IntRect(886, 91, 32, 32));
          // rectangle.setFillColor(sf::Color::Blue);
          s.setPosition(x*32,y*32);
          window.draw(s);
          _mapTile[x][y] = s;

     }else if(this->getNameOfElement(P) == "Hill"){
          sf::Sprite s;
          s.setTexture(t);
          s.setTextureRect(sf::IntRect(772, 625, 32, 32));
          // rectangle.setFillColor(sf::Color::Red);
          s.setPosition(x*32,y*32);
          window.draw(s);
          _mapTile[x][y] = s;
     }

}

void Map::drawWorld(sf::RenderWindow &window){
     std::cout << "Loading map..." << '\n';
     sf::Texture texture;
     texture.loadFromFile("./Textures/LPC_Terrain/terrain.png");
     for(int i = 0; i< this->_sizeX/32; i++){
          for(int j = 0; j< this->_sizeY/32; j++){
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

void Map::handleClick(sf::RenderWindow &window,sf::Event &e){
     sf::Event mapEvent =e;
     int i = 0;
     int j =0;
     _tileClicked = 0;
     // std::cout << "_tileClicked" <<_tileClicked<< '\n';
     // while (window.pollEvent(mapEvent)) {
          if (mapEvent.type == sf::Event::MouseButtonPressed) {
               Menu m;
               while ((i < (_sizeX/32)) && (_tileClicked == 0)) {
                    while ((j < (_sizeY/32)) &&(_tileClicked ==0)) {
                         // sf::Sprite s;

                         if (_mapTile[i][j].getGlobalBounds().contains(sf::Mouse::getPosition(window).x/32,sf::Mouse::getPosition(window).y/32)) {
                              Position pos(sf::Mouse::getPosition(window).x/32,sf::Mouse::getPosition(window).y/32);
                              std::cout << "x: " << sf::Mouse::getPosition(window).x<< " y: " << sf::Mouse::getPosition(window).y << '\n';
                              std::cout << "Name: " << getNameOfElement(pos) <<'\n';
                         }
                         // _tileClicked = m.checkZone(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, _mapTile[i][j]);
                         j++;
                    }
                    i++;
               }
          }
     // }
}

/* ====================  Game UI   ========================== */
Ui::Ui(){

}

Ui::~Ui(){

}

void Ui::drawUi(sf::RenderWindow &window){
     std::cout << "Loading Ui..." << '\n';
     sf::Texture texture;
     texture.loadFromFile("./Textures/LPC_Terrain/terrain.png");
     sf::Sprite alpha,separationBar;

     alpha.setTexture(texture);
     alpha.setTextureRect(sf::IntRect(768, 926, 250, 100));
     alpha.setPosition(800-250,600-100);

     separationBar.setTexture(texture);
     separationBar.setTextureRect(sf::IntRect(355,476,45,20));
     for (double i = 0; i < window.getSize().x/45+1; i++) {
          separationBar.setPosition(i*45,600-120);
          window.draw(separationBar);
     }
     window.draw(alpha);
     // _mapTile[x][y] = s;

}

void Ui::handleClick(sf::RenderWindow &window, sf::Event &event){

}
