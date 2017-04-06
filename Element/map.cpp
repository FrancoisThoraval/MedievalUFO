#include "map.hpp"

// A faire, appliquer les textures correctement
// Verification


/*** Methode Map ***/

Map::Map(int sizeX, int sizeY){
    this->_sizeX = sizeX;
    this->_sizeY = sizeY;
    this->_compttab = 0;
    _tabUnit = new Unit[6];
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
    _unitSelected.setX(-1);
    _unitSelected.setY(-1);
}

Map::~Map(){
     std::cerr << "deleting w1" << '\n';
     delete[] _world1;
     std::cerr << "deleting w2" << '\n';
     delete[] _world2;
     std::cerr << "deleting mapTile" << '\n';
     delete[] _mapTile;
     std::cerr << "deleting tabUnit" << '\n';
     delete[] _tabUnit;
}

Unit& Map::getElementW1(Position pos)const{
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

void Map::setInTab(Unit& u){
  this->_tabUnit[getCompt()] = u;
  setCompt((this->getCompt())+1);
}

Unit Map::getTab(int pos)const{
  return(this->_tabUnit[pos]);
}

void Map::setElement(Position pos,Element* elt){

}

void Map::createTile(int x, int y, sf::RenderWindow &window,sf::Texture &t){
     // sf::RectangleShape rectangle(sf::Vector2f(32, 32));
     Position P;
     P.setX(x);
     P.setY(y);
     if (this->getNameOfElement(P) == "zedd") {
          sf::Sprite s;
          s.setTexture(t);
          s.setTextureRect(sf::IntRect(409, 844, 32, 32));
          s.setPosition(x*32,y*32);
          window.draw(s);
          _mapTile[x][y] = s;
     }
     if (this->getNameOfElement(P) == "putties") {

     }
     if (this->getNameOfElement(P) == "red") {
          sf::Sprite s;
          s.setTexture(t);
          s.setTextureRect(sf::IntRect(145, 846, 32, 32));
          s.setPosition(x*32,y*32);
          window.draw(s);
          _mapTile[x][y] = s;
     }
     if (this->getNameOfElement(P) == "blue") {
          sf::Sprite s;
          s.setTexture(t);
          s.setTextureRect(sf::IntRect(203, 842, 32, 32));
          s.setPosition(x*32,y*32);
          window.draw(s);
          _mapTile[x][y] = s;
     }
     if (this->getNameOfElement(P) == "green") {
          sf::Sprite s;
          s.setTexture(t);
          s.setTextureRect(sf::IntRect(311, 844, 32, 32));
          s.setPosition(x*32,y*32);
          window.draw(s);
          _mapTile[x][y] = s;
     }
     if (this->getNameOfElement(P) == "pink") {
          sf::Sprite s;
          s.setTexture(t);
          s.setTextureRect(sf::IntRect(364, 844, 32, 32));
          s.setPosition(x*32,y*32);
          window.draw(s);
          _mapTile[x][y] = s;
     }
     if (this->getNameOfElement(P) == "yellow") {
          sf::Sprite s;
          s.setTexture(t);
          s.setTextureRect(sf::IntRect(259, 844, 32, 32));
          s.setPosition(x*32,y*32);
          window.draw(s);
          _mapTile[x][y] = s;
     }
     if(this->getNameOfElement(P) == "Tree"){
          sf::Sprite s;
          s.setTexture(t);
          s.setTextureRect(sf::IntRect(207, 282, 32, 32));
          s.setPosition(x*32,y*32);
          window.draw(s);
          _mapTile[x][y] = s;
     }else if(this->getNameOfElement(P) == "Water"){
          sf::Sprite s;
          s.setTexture(t);
          s.setTextureRect(sf::IntRect(886, 91, 32, 32));
          s.setPosition(x*32,y*32);
          window.draw(s);
          _mapTile[x][y] = s;

     }else if(this->getNameOfElement(P) == "Hill"){
          sf::Sprite s;
          s.setTexture(t);
          s.setTextureRect(sf::IntRect(772, 625, 32, 32));
          s.setPosition(x*32,y*32);
          window.draw(s);
          _mapTile[x][y] = s;
     }

}

void Map::createWorld(sf::RenderWindow &window){
     int nbTree =0;
     int nbWater =0;
     int nbHill =0;
     std::cout << "Generating map..." << '\n';
     sf::Texture texture;
     texture.loadFromFile("./Textures/LPC_Terrain/terrain.png");
     for(int i = 0; i< this->_sizeX/32; i++){
          for(int j = 0; j< this->_sizeY/32; j++){
               int k = rand() %3 +1;
               std::cout << "k: " << k << '\n';
               if(k == 1){
                    Scenery *t = new Tree;
                    _world2[i][j] = *t;
                    nbTree++;
               }
               if((k == 2)){
                    Scenery *w = new Water;
                    _world2[i][j] = *w;
                    nbWater++;
               }
               if((k == 3)){
                    Scenery *h = new Hill;
                    _world2[i][j] = *h;
                    nbHill++;
               }
          }
     }
}

void Map::drawWorld(sf::RenderWindow &window){
     std::cout << "Loading map..." << '\n';
     sf::Texture texture;
     texture.loadFromFile("./Textures/LPC_Terrain/terrain.png");
     for(int i = 0; i< this->_sizeX/32; i++){
          for(int j = 0; j< this->_sizeY/32; j++){
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

void Map::handleClick(sf::RenderWindow &window,sf::Event &e,Player &p,Ui& ui){
     sf::Event mapEvent =e;
     int i = 0;
     int j =0;
     _tileClicked = 0;
     struct timeval debut,fin;                // variable temps
     float tempspasse;
     float tempsjeux = 0.4;
     gettimeofday(&debut,NULL);
     if (mapEvent.type == sf::Event::MouseButtonPressed) {
          Menu m;
          Position pos,posUi;


          while ((i < (_sizeX/32)) && (_tileClicked == 0)) {
               while ((j < (_sizeY/32)) &&(_tileClicked ==0)) {
                    if (_mapTile[i][j].getGlobalBounds().contains(sf::Mouse::getPosition(window).x/32,sf::Mouse::getPosition(window).y/32)) {
                         pos.setX(sf::Mouse::getPosition(window).x/32);
                         pos.setY(sf::Mouse::getPosition(window).y/32);
                         std::cout << "x: " << sf::Mouse::getPosition(window).x<< " y: " << sf::Mouse::getPosition(window).y << '\n';
                         std::cout << "You clicked on: " << getNameOfElement(pos) <<'\n';
                         // std::cout<<"typeid: "<< typeid(getNameOfElement(pos))<< std::endl;

                    }
                    j++;
               }
               i++;
          }
          p.showUnitOwned();
          if(ui.getState()==1){
            //ui.handleClick()

          }
          if (_unitSelected.getX() == -1) {
                window.clear();
                drawWorld(window);
               if((getNameOfElement(pos) == "blue")||(getNameOfElement(pos) == "pink")||(getNameOfElement(pos) == "green")||(getNameOfElement(pos) == "yellow")||(getNameOfElement(pos) == "red")) {
                    _unitSelected = pos;
                    ui.setState(1);
                    std::cerr << "saving position of unit selected" << '\n';
                    gettimeofday(&fin,NULL);
                    while (tempspasse < tempsjeux){
                      gettimeofday(&fin,NULL);
                      tempspasse = (((fin.tv_sec - debut.tv_sec)*1000000L+fin.tv_usec) - debut.tv_usec);
                      tempspasse = (tempspasse/1000)/1000;
                    }
                    //ui.displayInfoUnit(window,getElementW1(_unitSelected));

               }else{

                    ui.setState(0);
                    _unitSelected.setX(-1);
                    _unitSelected.setY(-1);

               }
          }else{
               //Actuellement ne déplace pas

               getElementW1(_unitSelected).move(_unitSelected,pos,this,1,p);
               std::cerr << "_unitSelected: " << '\n';
               std::cout << _unitSelected << '\n';
               std::cerr << "pos: " << '\n';
               std::cout << pos << '\n';
               drawWorld(window);
               _unitSelected.setX(-1);
               _unitSelected.setY(-1);
          }
     }
}

/* ====================  Game UI   ========================== */
Ui::Ui(){
 _state = 0;
 _mapTile = new sf::Sprite[10];
}

Ui::~Ui(){

}

void Ui::setState(int st){
  this->_state = st;
}

int Ui::getState()const{
  return(this->_state);
}

void Ui::drawUi(sf::RenderWindow &window, Player &p1, Player &p2){
     std::cout << "Loading Ui..." << '\n';
     sf::Texture texture;
     texture.loadFromFile("./Textures/LPC_Terrain/terrain.png");
     sf::Sprite alpha,separationBar;
     sf::RectangleShape whosPlaying(sf::Vector2f(100, 100));

     if (p1.getWhosPlaying())
          whosPlaying.setFillColor(sf::Color::Green);
     else
          whosPlaying.setFillColor(sf::Color::Red);

     whosPlaying.setPosition(800-350,600-100);

     alpha.setTexture(texture);
     alpha.setTextureRect(sf::IntRect(768, 926, 250, 100));
     alpha.setPosition(800-250,600-100);

     separationBar.setTexture(texture);
     separationBar.setTextureRect(sf::IntRect(355,476,45,20));
     for (double i = 0; i < window.getSize().x/45+1; i++) {
          separationBar.setPosition(i*45,600-120);
          window.draw(separationBar);
     }
     window.draw(whosPlaying);
     window.draw(alpha);
     // _mapTile[x][y] = s;



}

void Ui::handleClick(sf::RenderWindow &window, sf::Event &event){
  sf::Event test;
  while(window.pollEvent(test)){
    // if(ui._mapTile[i].getGlobalBound().contain(sf::Mouse::getPosition(window).x/32,sf::Mouse::getPosition(window).y/32)){
    //   posUi.setX(sf::Mouse::getPosition(window).x/32);
    //   posUi.setY(sf::Mouse::getPosition(window).y/32);
    // }

  }
}

void Ui::displayInfoUnit(sf::RenderWindow &_window, Unit& u){
      sf::Texture t;
      t.loadFromFile("./Textures/LPC_Terrain/terrain.png");
      int x = 0;
      int y = 0;

     // sf::Text info;
     // std::stringstream ss;
     // ss << p.getEnergy();
     // info.setString( ss.str().c_str() );
     // window.draw(info);
     // window.display();

     if(u.getName()=="Putties"){
       Putties pu;
       sf::Sprite s;
       s.setTexture(t);

       pu = u;

       if(u.getPrimaryW()->getName()=="Canon a eau"){
         s.setTextureRect(sf::IntRect());
       } else if (u.getPrimaryW()->getName()=="Lancer de terre"){
         s.setTextureRect(sf::IntRect());
       } else if (u.getPrimaryW()->getName()=="Lancer de tronc"){
         s.setTextureRect(sf::IntRect());
       } else {
         s.setTextureRect(sf::IntRect());
       }
       //x= ;
       //y= ;
       s.setPosition(x*50,y*50);
       _window.draw(s);
     } else if (u.getName()=="zedd"){
              Zedd zed;
              sf::Sprite s1,s2,s3,s4;
              s1.setTextureRect(sf::IntRect()); // GRENADE
              s2.setTextureRect(sf::IntRect()); //PUTTIES CALLING
              s3.setTextureRect(sf::IntRect()); // INVOCATION
              s4.setTextureRect(sf::IntRect()); // APOCALYPSE HOLLE
              //x= ;
              //y= ;
              s1.setPosition(x*50,y*50);
              //x= ;
              //y= ;
              s2.setPosition(x*50,y*50);
              //x= ;
              //y= ;
              s3.setPosition(x*50,y*50);
              //x= ;
              //y= ;
              s4.setPosition(x*50,y*50);

              zed = u;

              _window.draw(s1);
              _window.draw(s2);
              _window.draw(s3);
              _window.draw(s4);

      } else  if(u.getName()=="green"){
              PowerRanger green;
              sf::Sprite s1,s2;
              s1.setTextureRect(sf::IntRect());    // FIST
              s2.setTextureRect(sf::IntRect());    // FLUTE
              //x= ;
              //y= ;
              s1.setPosition(x*50,y*50);
              //x= ;
              //y= ;
              s2.setPosition(x*50,y*50);
              green = u;

              _window.draw(s1);
              _window.draw(s2);


            } else {
              PowerRanger pr;
              sf::Sprite s1,s2;

              pr = u;

              s1.setTextureRect(sf::IntRect()); // FIST
              s2.setTextureRect(sf::IntRect()); // GUN

              //x= ;
              //y= ;
              s1.setPosition(x*50,y*50);
              //x= ;
              //y= ;
              s2.setPosition(x*50,y*50);

              _window.draw(s1);
              _window.draw(s2);

            }

}
