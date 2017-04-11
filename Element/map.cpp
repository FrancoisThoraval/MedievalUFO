#include "map.hpp"
#include "../Unit/ayayay.cpp"
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
     if (this->getNameOfElement(P) == "Zedd") {
          sf::Sprite s;
          s.setTexture(t);
          s.setTextureRect(sf::IntRect(409, 844, 32, 32));
          s.setPosition(x*32,y*32);
          window.draw(s);
          _mapTile[x][y] = s;
     }
     if (this->getNameOfElement(P) == "Putties") {
      //  sf::Sprite s;
      //  s.setTexture(t);
      //  s.setTextureRect(sf::IntRect(409, 844, 32, 32));
      //  s.setPosition(x*32,y*32);
      //  window.draw(s);
      //  _mapTile[x][y] = s;
      sf::Sprite s;
      s.setTexture(t);
      s.setTextureRect(sf::IntRect(145, 846, 32, 32));
      s.setPosition(x*32,y*32);
      window.draw(s);
      _mapTile[x][y] = s;
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
     } else if(this->getNameOfElement(P) == "Lava2"){
       sf::Sprite s;
       s.setTexture(t);
       s.setTextureRect(sf::IntRect(510, 94, 32, 32));
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
     if(((pos.getX()<0)||(pos.getX()>_sizeX))||((pos.getY()<0)||(pos.getY()>_sizeY))) {
          std::cerr << "You cannot access this position !" << '\n';
          return false;
     }else
          return true;
}

int Map::getSizeY(){return this->_sizeY;}
int Map::getSizeX(){return this->_sizeX;}
void Map::setSizeY(int y){this->_sizeY = y;}
void Map::setSizeX(int x){this->_sizeX = x;}

void Map::handleClick(sf::RenderWindow &window,sf::Event &mapEvent,Player &p1, Player &p2,Ui& ui){
     // sf::Event mapEvent =e;
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
          // Si on a cliqué dans une zone hors map (ici en dessous)
          if (sf::Mouse::getPosition(window).y > 500) {
               pos.setX(sf::Mouse::getPosition(window).x);
               pos.setY(sf::Mouse::getPosition(window).y);
               ui.handleClick(window,pos,this);
               ui.drawUi(window,p1,p2);//Je crois que ça pose probleme comme c'est deux fois le même player (au niveau de la couleur du carré rouge ou vert)
          }else{
               // Si on a cliqué sur la map
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

               p1.showUnitOwned();
               // Si on n'a pas sélectionner d'unité
               if (_unitSelected.getX() == -1) {
                    //window.clear();
                    drawWorld(window);
                    ui.setState(1);
                    if (p1.isMineUnit(getNameOfElement(pos))) {
                         ui.setUnitClicked(getNameOfElement(pos));
                    }else{
                         std::cout << "TEST zedd health points:"<<getElementW1(pos).getHealthPoints() << '\n';
                         std::cout << "This unit is not yours !" << '\n';
                    }
                    ui.drawUi(window,p1,p2);
                    if((getNameOfElement(pos) == "blue")||(getNameOfElement(pos) == "pink")||(getNameOfElement(pos) == "green")||(getNameOfElement(pos) == "yellow")||(getNameOfElement(pos) == "red")||(getNameOfElement(pos) == "Zedd")||(getNameOfElement(pos) == "Putties")) {
                         //if (p1.isMineUnit(getElementW1(pos))) {

                              _unitSelected = pos;
                              ui.setState(1);
                              std::cerr << "saving position of unit selected" << '\n';
                              gettimeofday(&fin,NULL);
                              //Advice_ayayay(window,getElementW1(_unitSelected));
                              // while (tempspasse < tempsjeux){
                              //      gettimeofday(&fin,NULL);
                              //      tempspasse = (((fin.tv_sec - debut.tv_sec)*1000000L+fin.tv_usec) - debut.tv_usec);
                              //      tempspasse = (tempspasse/1000)/1000;
                              // }
                         //}
                         //ui.displayInfoUnit(window,getElementW1(_unitSelected));

                    }else{ //Si on a cliqué sur élement autre qu'une unité

                         ui.setState(0);
                         _unitSelected.setX(-1);
                         _unitSelected.setY(-1);
                         ui.setUnitClicked(-1);

                    }
               }else{//Si une unité est déjà sélectionnée.
                    getElementW1(_unitSelected).move(_unitSelected,pos,this,ui.getAttack()+1,p1,p2);
                    drawWorld(window);
                    _unitSelected.setX(-1);
                    _unitSelected.setY(-1);
                    ui.setUnitClicked(-1);
                    ui.drawUi(window,p1,p2);
                    p2.hasLost();
                    //p1.haslost();
               }

          }
          std::cout << "_unitSelected:" << _unitSelected<< '\n';

     }

}

Position Map::getUnitSelected(){
     std::cout << "UnitSelected: \n"<< _unitSelected << '\n';
     std::cout << "who is at that position: "<< getNameOfElement(_unitSelected) << '\n';
     return this->_unitSelected;
}

/* ====================  Game UI   ========================== */
Ui::Ui(){
 _state = 0;
 _buttonArray = new sf::Sprite[10];
 _numattack = 0;
 _unitClicked = -1;
}

Ui::~Ui(){

}

void Ui::setState(int st){
  this->_state = st;
}

int Ui::getState()const{
  return(this->_state);
}


void Ui::handleClick(sf::RenderWindow &window,Position pos, Map *m){
     bool found = false;
     int i =0;
     std::cout << "entering ui event handler" << '\n';
     // Tant qu'on a pas trouvé le sprite correspondant à pos
     while ((i < 4)&&(!found)) {
          if (_buttonArray[i].getGlobalBounds().contains(pos.getX(),pos.getY())) {
               found = true;
               std::cout << "clicked on a button !" << '\n';
               std::cout << "You clicked on the " << i<< " button" << '\n';
               // ****
               // Gestion des attaques
               // ****

               this->_numattack = i;

          }
          i++;
     }
     if(found == false){
       _numattack = 0;
       if (_alpha.getGlobalBounds().contains(pos.getX(),pos.getY())) {
          std::cout << "ayayay" << '\n';
          Advice_ayayay(window,m->getElementW1(m->getUnitSelected()));
       }
     }

}
void Ui::drawUi(sf::RenderWindow &window, Player &p1, Player &p2){
     std::cout << "Loading Ui..." << '\n';
     sf::Texture texture;
     texture.loadFromFile("./Textures/LPC_Terrain/terrain.png");
     sf::Sprite separationBar,b1,b2,b3,b4;
     sf::RectangleShape whosPlaying(sf::Vector2f(100, 100));
     // Rectangle pour effacer l'ui
     sf::RectangleShape clearUi(sf::Vector2f(450, 100));
     // Dessine un carré rouge ou vert pour indiquer qui doit jouer.
     if ((p1.isMineUnit("red"))||(p1.isMineUnit("blue"))||(p1.isMineUnit("yellow"))||(p1.isMineUnit("green"))||(p1.isMineUnit("pink")))
          whosPlaying.setFillColor(sf::Color::Green);
     else
          whosPlaying.setFillColor(sf::Color::Red);

     whosPlaying.setPosition(800-350,600-100);
     // Dessine le bouton demande d'aide du jeu.
     _alpha.setTexture(texture);
     _alpha.setTextureRect(sf::IntRect(768, 926, 250, 100));
     _alpha.setPosition(800-250,600-100);

     // Dessine une barre de séparation entre le terrain de jeu et les boutons de l'interface.
     separationBar.setTexture(texture);
     separationBar.setTextureRect(sf::IntRect(355,476,45,20));
     for (double i = 0; i < window.getSize().x/45+1; i++) {
          separationBar.setPosition(i*45,600-120);
          window.draw(separationBar);
     }
     window.draw(whosPlaying);
     window.draw(_alpha);

     // En fonction de l'unité qu'on a cliqué, on affiche les bons boutons
     // Voir -> setUnitClicked pour les valeurs des unités.

     // Reset
     sf::Sprite bidon;
     for (int i = 0; i < 4; i++) {
          _buttonArray[i]=bidon;
     }
     // On dessine un carré noir pour "effacer" les boutons dessinés.
     clearUi.setFillColor(sf::Color::Black);
     clearUi.setPosition(0,600-100);
     window.draw(clearUi);

     switch (_unitClicked) {
          case 0:{ //Red
               std::cout << "now drawing ui's character 0." << '\n';
               b1.setTexture(texture);
               b1.setTextureRect(sf::IntRect(616,975,50,50)); //fist
               b1.setPosition(0,600-100);
               //
               b2.setTexture(texture);
               b2.setTextureRect(sf::IntRect(402,973,50,50)); //pistol
               b2.setPosition(50,600-100);
               //
               b3.setTexture(texture);
               b3.setTextureRect(sf::IntRect(296,973,50,50)); //robot
               b3.setPosition(100,600-100);
               //
               b4.setTexture(texture);
               b4.setTextureRect(sf::IntRect(457,975,50,50));
               b4.setPosition(150,600-100);
               // On rempli le tableau de boutons
               _buttonArray[0]=b1;
               _buttonArray[1]=b2;
               _buttonArray[2]=b3;
               _buttonArray[3]=b4;
               // On dessine les boutons
               window.draw(b1);
               window.draw(b2);
               window.draw(b3);
               window.draw(b4);
          }break;
          case 1 : {
            std::cout << "now drawing ui's character 1." << '\n';
            b1.setTexture(texture);
            b1.setTextureRect(sf::IntRect(616,975,50,50)); //fist
            b1.setPosition(0,600-100);
            //
            b2.setTexture(texture);
            b2.setTextureRect(sf::IntRect(402,973,50,50)); //pistol
            b2.setPosition(50,600-100);
            //
            b3.setTexture(texture);
            b3.setTextureRect(sf::IntRect(296,973,50,50)); //robot
            b3.setPosition(100,600-100);
            //
            b4.setTexture(texture);
            b4.setTextureRect(sf::IntRect(457,975,50,50));
            b4.setPosition(150,600-100);
            //
            // On rempli le tableau de boutons
            _buttonArray[0]=b1;
            _buttonArray[1]=b2;
            _buttonArray[2]=b3;
            _buttonArray[3]=b4;
            // On dessine les boutons
            window.draw(b1);
            window.draw(b2);
            window.draw(b3);
            window.draw(b4);
          }break;
          case 2 : {
            std::cout << "now drawing ui's character 2." << '\n';
            b1.setTexture(texture);
            b1.setTextureRect(sf::IntRect(616,975,50,50)); //fist
            b1.setPosition(0,600-100);
            //
            b2.setTexture(texture);
            b2.setTextureRect(sf::IntRect(402,973,50,50)); //pistol
            b2.setPosition(50,600-100);
            //
            b3.setTexture(texture);
            b3.setTextureRect(sf::IntRect(296,973,50,50)); //robot
            b3.setPosition(100,600-100);
            //
            b4.setTexture(texture);
            b4.setTextureRect(sf::IntRect(457,975,50,50));
            b4.setPosition(150,600-100);
            // On rempli le tableau de boutons
            _buttonArray[0]=b1;
            _buttonArray[1]=b2;
            _buttonArray[2]=b3;
            _buttonArray[3]=b4;
            // On dessine les boutons
            window.draw(b1);
            window.draw(b2);
            window.draw(b3);
            window.draw(b4);
          }break;
          case 3 : {
            std::cout << "now drawing ui's character 3." << '\n';
            b1.setTexture(texture);
            b1.setTextureRect(sf::IntRect(616,975,50,50)); //fist
            b1.setPosition(0,600-100);
            //
            b2.setTexture(texture);
            b2.setTextureRect(sf::IntRect(402,973,50,50)); //pistol
            b2.setPosition(50,600-100);
            //
            b3.setTexture(texture);
            b3.setTextureRect(sf::IntRect(296,973,50,50)); //robot
            b3.setPosition(100,600-100);
            //
            b4.setTexture(texture);
            b4.setTextureRect(sf::IntRect(457,975,50,50));
            b4.setPosition(150,600-100);
            // On rempli le tableau de boutons
            _buttonArray[0]=b1;
            _buttonArray[1]=b2;
            _buttonArray[2]=b3;
            _buttonArray[3]=b4;
            // On dessine les boutons
            window.draw(b1);
            window.draw(b2);
            window.draw(b3);
            window.draw(b4);
          }break;
          case 4 : {
            std::cout << "now drawing ui's character 4." << '\n';
            b1.setTexture(texture);
            b1.setTextureRect(sf::IntRect(616,975,50,50)); //fist
            b1.setPosition(0,600-100);
            //
            b2.setTexture(texture);
            b2.setTextureRect(sf::IntRect(563,975,50,50)); //pistol
            b2.setPosition(50,600-100);
            //
            b3.setTexture(texture);
            b3.setTextureRect(sf::IntRect(296,973,50,50)); //robot
            b3.setPosition(100,600-100);
            //
            b4.setTexture(texture);
            b4.setTextureRect(sf::IntRect(457,975,50,50));
            b4.setPosition(150,600-100);
            // On rempli le tableau de boutons
            _buttonArray[0]=b1;
            _buttonArray[1]=b2;
            _buttonArray[2]=b3;
            _buttonArray[3]=b4;
            // On dessine les boutons
            window.draw(b1);
            window.draw(b2);
            window.draw(b3);
            window.draw(b4);
          }break;
          case 5:{
            std::cout << "now drawing ui's character 5." << '\n';
            b1.setTexture(texture);
            b1.setTextureRect(sf::IntRect(667,975,50,50)); //Grenade
            b1.setPosition(0,600-100);
            //
            b2.setTexture(texture);
            b2.setTextureRect(sf::IntRect(510,973,50,50)); //Invocation
            b2.setPosition(50,600-100);
            //
            b3.setTexture(texture);
            b3.setTextureRect(sf::IntRect(350,973,50,50)); //PuttiesCalling
            b3.setPosition(100,600-100);
            //
            b4.setTexture(texture);                       //Apocalypse
            b4.setTextureRect(sf::IntRect(718,975,50,50));
            b4.setPosition(150,600-100);
            // On rempli le tableau de boutons
            _buttonArray[0]=b1;
            _buttonArray[1]=b2;
            _buttonArray[2]=b3;
            _buttonArray[3]=b4;
            // On dessine les boutons
            window.draw(b1);
            window.draw(b2);
            window.draw(b3);
            window.draw(b4);
          }break;
          case 6:{
            std::cout << "now drawing ui's character 6." << '\n';
            b1.setTexture(texture);
            b1.setTextureRect(sf::IntRect(616,975,50,50)); //fist
            b1.setPosition(0,600-100);
            //
            // On rempli le tableau de boutons
            _buttonArray[0]=b1;
            // On dessine les boutons
            window.draw(b1);
          }
     }
}

void Ui::setAttack(int a){
  this->_numattack = a;
}

int Ui::getAttack()const{
  return(_numattack);
}

void Ui::setUnitClicked(int value){
     _unitClicked = value;
}

void Ui::setUnitClicked(std::string nameOfUnit){
     if (nameOfUnit == "red") {
          setUnitClicked(0);
     }
     if (nameOfUnit == "blue") {
          setUnitClicked(1);
     }
     if (nameOfUnit == "yellow") {
          setUnitClicked(2);
     }
     if (nameOfUnit == "pink") {
          setUnitClicked(3);
     }
     if (nameOfUnit == "green") {
          setUnitClicked(4);
     }
     if (nameOfUnit == "Zedd") {
          setUnitClicked(5);
     }
     if(nameOfUnit == "Putties"){
          setUnitClicked(6);
     }
}
