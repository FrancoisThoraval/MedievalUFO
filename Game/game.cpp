#include "game.hpp"

#include <iostream>
Game::Game(int x, int y){                                                                                                                   //constructeur game
     _gameState = 0; //Initialization
     _xWindow = x;
     _yWindow = y;
     _isFullScreen = false;
}

Game::~Game(){                                                                                                                              // destructeur game

}

void Game::start(){                                                                                                                         //Lancement du jeux
     if (_gameState != 0)
          return;

     _window.create(sf::VideoMode(_xWindow,_yWindow,32),"Power Rangers - Ultimate Battle Simulator (Alpha)",sf::Style::Default);            // Creation de la fenetre de jeux
     _gameState = 2;

     while (!isExiting()) {
          gameLoop();
     }

     _window.close();
}

bool Game::isExiting(){
     if (_gameState == 5) {
          return true;
     }else
          return false;
}




// In event loop...




void Game::gameLoop(){                                                                                                      // Boucle du jeux
     sf::Event currentEvent;
     while (_window.pollEvent(currentEvent)) {
          std::cout << "isFullscreen: "<< _isFullScreen << '\n';

          switch (_gameState) {
               case 2 : {
                    showSpashScreen();
               break;
               }
               case 3: {
                    showMenu();
                    break;
               }
               case 4 : {
                    //_window.clear();
                    //Saisie des noms de joueurs

                    // JUSQUICI
                    /*                                        (J'ai enlever sa pour esseyer mon truc)
                      std::cout << "=====\nPlayer 1: ";
                      std::cin>>name;
                      p1.setName(name);
                      p1.setWhosPlaying(true);
                      std::cout << "=====\nPlayer 2: ";
                      std::cin>>name;
                      p2.setName(name);
                      p2.setWhosPlaying(false);
                    */
                    //Création des éléments du jeu
                    Map m(800,500);
                    m.createWorld(_window);
                    Ui ui;
                    //Création Unité p1 (power ranger)
                    // Zedd zedd;
                    // PowerRanger pink("pink"), red("red"), blue("blue"), green("green"),yellow("yellow");
                    Position posPink(9,13),posRed(7,13),posBlue(8,13),posGreen(10,13),posYellow(11,13);                     //Creation des personnages du jeux
                    Position posZedd(1,1);
                    Unit *red = new PowerRanger("red");
                    Unit *blue = new PowerRanger("blue");
                    Unit *yellow = new PowerRanger("yellow");
                    Unit *pink = new PowerRanger("pink");
                    Unit *green = new PowerRanger("green");
                    Unit *zedd = new Zedd;

                    // pink.setPosition(posPink);
                    zedd->setPosition(posZedd);                                                                             // placement des joueurs sur la map
                    red->setPosition(posRed);
                    blue->setPosition(posBlue);
                    yellow->setPosition(posYellow);
                    pink->setPosition(posPink);
                    green->setPosition(posGreen);
                    std::cout<<"POS PINK : "<<pink->getPosition()<<std::endl;
                    //  std::cout<<"DEFAULT : "<<pink.getDefault()<<std::endl;
                    m.setElementW1(posZedd,zedd);
                    m.setElementW1(posRed,red);
                    m.setElementW1(posGreen,green);
                    m.setElementW1(posYellow,yellow);
                    m.setElementW1(posBlue,blue);
                    m.setElementW1(posPink,pink);
                    p1.pushUnit(pink);
                    p1.pushUnit(red);
                    p1.pushUnit(blue);
                    p1.pushUnit(green);
                    p1.pushUnit(yellow);
                    p2.pushUnit(zedd);
                    m.getElementW1(posRed)->setDefault(4);
                    // p1.getUnit(1).setDefault(4);
                    m.getElementW1(posBlue)->setDefault(4);
                    // p1.getUnit(2).setDefault(4);
                    m.getElementW1(posGreen)->setDefault(4);
                    // p1.getUnit(3).setDefault(4);
                    m.getElementW1(posYellow)->setDefault(4);
                    // p1.getUnit(4).setDefault(4);
                    m.getElementW1(posPink)->setDefault(4);
                    // p1.getUnit(0).setDefault(4);

                    _window.clear(sf::Color(0,0,0));
                    m.drawWorld(_window);
                    ui.drawUi(_window,p1,p2,NULL);
                    while (_gameState == 4) {
                         _window.display();
                         while (_window.pollEvent(currentEvent)) {
                              if (currentEvent.type == sf::Event::Closed) {                                                                                                                           // evenement si on clique sur la croix rouge
                                   _gameState = 5; //End
                              }
                              if(currentEvent.type == sf::Event::KeyPressed)                                                                                                                          //evenement si on appuis sur une touche
                              {

                                   // Il doit y avoir un souci avec la sfml peut-être qui fais que le code de l'event pour la touche entrée est pris pour celui de la touche echap.
                                   // Si on commente l'event du menu y'a plus le bug du spam de la touche entrée.
                                   if(currentEvent.key.code == sf::Keyboard::Escape){                                                                                                                   // evenement si cette touche est la touche echape
                                        std::cout << "Opening menu" << '\n';
                                        showMenu(); //Créer un menu spécial
                                   }
                                   if(currentEvent.key.code == sf::Keyboard::Return){                                                                                                                     // evenement si cette touche est latouche entree
                                        std::cerr << "ending turn" << '\n';
                                        endTurn(p1,p2,&m,&ui,posZedd);
                                        m.drawWorld(_window);
                                        _window.display();
                                   }

                                   if (currentEvent.key.code == sf::Keyboard::F) {
                                        std::cout << "Toggling fullscreen" << '\n';
                                        if (_isFullScreen) {
                                             _window.create(sf::VideoMode(_xWindow,_yWindow,32),"Power Rangers - Ultimate Battle Simulator (Alpha)",sf::Style::Default);
                                             _isFullScreen = false;
                                             m.drawWorld(_window);
                                             _window.display();
                                        }else{
                                             _window.create(sf::VideoMode(_xWindow,_yWindow,32),"Power Rangers - Ultimate Battle Simulator (Alpha)",sf::Style::Fullscreen);
                                             _isFullScreen = true;
                                             m.drawWorld(_window);
                                             _window.display();
                                        }

                                   }

                              }
                         }
                         if (p1.getWhosPlaying()) {                                                             // fonction qui permet le jeux a la souris
                           m.handleClick(_window,currentEvent,p1,p2,ui);

                         } else if(p2.getWhosPlaying()){
                           m.handleClick(_window,currentEvent,p2,p1,ui);
                         }

                         if ((p1.getLost()!=false) || (p2.getLost()!= false )) {
                              std::cout << "one player lost, back to menu" << '\n';
                              _gameState = 3; //Retour au menu
                         }

                    }
               break;
               }
               case 5 : {
                    _window.close();
               }break;
               case 6 : {
                    _window.clear();
                    enterName();
               }
          }
     }
}

void Game::showSpashScreen(){                                                                                     // affichage du fond decran du debut
     SplashScreen s;
     s.show(_window);
     _gameState = 3;
}


void Game::showMenu(){                                                                                            // affichage du menus
     Menu m;
     m.show(_window);
     m.handleClick(_window);
     switch (m.getMenuChoice()) {
          case 1: _gameState = 6;
               break;
          case 2: _gameState = 5;
               break;
     }
     if (_gameState == 4) {
          std::cout << "Starting game..." << '\n';
     }else if(_gameState == 5){
          std::cout << "Closing game" << '\n';
     }
}

void Game::LavaDetector(Map* m){                                                                                  // foction qui fais progresser l'attaque de zed "apocalypse holl"
  std::cout << "/* message5 */" << std::endl;
  Position p1 ;
  Position p2 ;
  Position p3 ;
  Position p4 ;
  Position currentPos;
  Scenery *lava = new Lava;
  lava->setName("Lava1");
  for(int i =0;i<m->getSizeX();i++){
    for(int j = 0;j< m->getSizeY();j++){
      currentPos.setX(i);
      currentPos.setY(j);

      p1 = currentPos;
      p1.setX(currentPos.getX());
      p1.setY(currentPos.getY()+1);

      p2 = currentPos;
      p2.setX(currentPos.getX());
      p2.setY(currentPos.getY()-1);

      p3 = currentPos;
      p3.setX(currentPos.getX()+1);
      p3.setY(currentPos.getY());

      p4 = currentPos;
      p4.setX(currentPos.getX()-1);
      p4.setY(currentPos.getY());
      if((m->getElementW2(currentPos).getName()=="Lava2")){

            if((m->isOnMap(p1))) {
              m->setElementW2(p1,*lava);
              //m->getElementW2(p1).setName("Lava1");
            }
            if(m->isOnMap(p2)) {
              m->setElementW2(p2,*lava);
              //m->getElementW2(p2).setName("Lava1");
            }
            if(m->isOnMap(p3)) {
              m->setElementW2(p3,*lava);
            //  m->getElementW2(p3).setName("Lava1");
            }
            if(m->isOnMap(p4)) {
              m->setElementW2(p4,*lava);
              //m->getElementW2(p4).setName("Lava1");
            }

      }
    }
  }
  std::cout << "middle of lava detector" << '\n';
  lava->setName("Lava2");
  for(int i =0;i<m->getSizeX();i++){
    for(int j = 0;j< m->getSizeY();j++){
      currentPos.setX(i);
      currentPos.setY(j);
      if(m->getElementW2(currentPos).getName()=="Lava1"){
            //m->getElemm-ntW2(currentPos).setName("Lava2");
            m->setElementW2(currentPos,*lava);
      }
    }
  }
  std::cout << "FIN DE LVADETECTOR" << '\n';
}

void Game::LavaDamage(Map* m,Player& p){                                                                                    // fonction qui inflige les dommages de l'attaque apocalypse holl
  Position currentPos;
  for(int i =0;i<m->getSizeX()/32;i++){
    for(int j = 0;j<m->getSizeY()/32;j++){
      currentPos.setX(i);
      currentPos.setY(j);
      if(m->getElementW2(currentPos).getName()=="Lava2"){
        if(m->getElementW1(currentPos)!= NULL){
          if(p.isMineUnit(m->getNameOfElement(currentPos))){
            m->getElementW1(currentPos)->setHealthPoints(m->getElementW1(currentPos)->getHealthPoints()-1200);
            if(m->getElementW1(currentPos)->getHealthPoints()<=0){
              Unit *u = new Unit;
              p.removeUnit(*m->getElementW1(currentPos));
              m->setElementW1(currentPos,u);
            }
          }

        }
      }
    }
  }
}


void Game::endTurn(Player &p1, Player &p2,Map *m, Ui *ui,Position posZedd){                                                 // fonction de game qui passe la main a l'autre joueurs
     ui->setUnitClicked(-1);
     if (p1.getWhosPlaying()) {
          p1.setWhosPlaying(false);
          p2.setWhosPlaying(true);
          ui->drawUi(_window,p2,p1,NULL);
          std::cerr << p2.getName()<<", Your turn !" << '\n';
          // Substraction(p2);
          std::cerr<<" Player 2, Energy : "<<p2.getEnergy()<<std::endl;
          LavaDetector(m);
          //std::cout << "APOOOON : "<<zed.getApoon() << '\n';


          p1.EndOfTurn(m);
     }else{
          p2.setWhosPlaying(false);
          p1.setWhosPlaying(true);
          ui->drawUi(_window,p1,p2,NULL);
          std::cerr << p1.getName()<<", Your turn !" << '\n';
          std::cerr<<"Player 1, Energy : "<<p1.getEnergy()<<std::endl;
          LavaDamage(m,p1);

          p2.EndOfTurn(m);
     }
}


// void Game::Substraction(Player& p){
//   for(int i = 0;i < p.getSizeOwnUnit();i++){
//     if(p.getUnit(i)->getName() == "Zedd"){
//     //  std::cout << "Invoc : "<<p.getUnit(i)->getInvocation() << '\n'<<"puttiesclling : "<<p.getUnit(i)->getPuttiesCalling()<<'\n'<<"Apoc : "<<p.getUnit(i)->getApocalypseHole()<<std::endl;
//       if(p.getUnit(i)->getInvocation()>0 ){
//         p.getUnit(i)->setInvocation(p.getUnit(i)->getInvocation() - 1);
//       }
//       if(p.getUnit(i)->getPuttiesCalling() > 0){
//         p.getUnit(i)->setPuttiesCalling(p.getUnit(i)->getPuttiesCalling() - 1);
//       }
//       if(p.getUnit(i)->getApocalypseHole()>0){
//         p.getUnit(i)->setApocalypseHole(p.getUnit(i)->getApocalypseHole() - 1);
//       }
//     }
//   }
// }
void Game::enterName(){                                                                                                     // fonction qui permet d'entree les noms des joueurs au debut du jeux
  std::string name2;
  std::cout << "=====\nPlayer 1: ";
  sf::Event evenementnom;
  std::string nomtest;
  // Unit u;
  // AYAYAY_Assistant<Unit> testayayay(u);
  // testayayay.test();
  sf::Font font;
  font.loadFromFile("./arial.ttf");
  sf::Text text;
  text.setFont(font);
  text.setPosition(0,0);
  text.setColor(sf::Color::White);
  text.setCharacterSize(35);
  int k = 0;
  bool end = false;
  text.setString("Joueur 1, Saisissez votre nom: ");
  _window.draw(text);
  _window.display();
  text.setPosition(0,100);
  while((k<10)&&(end == false)){

    while(_window.pollEvent(evenementnom)){
      if(evenementnom.type == sf::Event::TextEntered){
        if(evenementnom.text.unicode <128){
          //if(evenementnom.text.unicode == )
          //name += static_cast<char>(evenementnom.text.unicode);
          std::cout<<"test carac : "<<static_cast<char>(evenementnom.text.unicode)<<std::endl;
          nomtest += static_cast<char>(evenementnom.text.unicode);
          k++;
          text.setString(nomtest);
          _window.draw(text);
          _window.display();
          if((evenementnom.text.unicode == 10)||(evenementnom.text.unicode == 13)){
            end = true;
          }
        }
      }
    }
  }

  std::cout<<"nom complet : "<<nomtest<<std::endl;
  p1.setName(nomtest);
  p1.setWhosPlaying(true);
  _window.clear();
  text.setPosition(0,0);
  std::cout <<"=====\nPlayer 2: ";
  text.setString("Joueur 2, Saisissez votre nom: ");
  _window.draw(text);
  _window.display();
  text.setPosition(0,100);
  k = 0;
  end = false;
  while((k<10)&&(end == false)){

    while(_window.pollEvent(evenementnom)){
      if(evenementnom.type == sf::Event::TextEntered){
        if(evenementnom.text.unicode <128){
          //name += static_cast<char>(evenementnom.text.unicode);
          std::cout<<"test carac : "<<static_cast<char>(evenementnom.text.unicode)<<std::endl;
          name2 += static_cast<char>(evenementnom.text.unicode);
          k++;
          text.setString(name2);
          _window.draw(text);
          _window.display();
          if((evenementnom.text.unicode == 10)||(evenementnom.text.unicode == 13)){
            end = true;
          }
        }
      }
    }
  }
  std::cout<<"nom complet : "<<name2<<std::endl;
  p2.setName(name2);
  p2.setWhosPlaying(false);

  bool continuer = true;
  while(continuer){
    while(_window.pollEvent(evenementnom)){
      if(evenementnom.type == sf::Event::KeyPressed){
        if(evenementnom.key.code == sf::Keyboard::Return){
        continuer = false;
        }
      }
    }
  }
  _gameState = 4;
}

// bool Game::isloose(Map m){
//   Position currentPos;
//   bool zedAlive = false;
//   bool PowerrangerAlive = false;
//   int i =0;
//   int j = 0;
//   while((i<m._sizeX/32)&&((zedAlive != true) && (PowerrangerAlive != true))){
//     while((j<m._sizeY/32)&&((zedAlive != true) && (PowerrangerAlive != true))){
//       currentPos.setX(i);
//       currentPos.setY(j);
//       if(m.getNameOfElement(currentPos)=="zedd"){
//         zedAlive = true;
//       }
//       if((m.getNameOfElement(currentPos)=="red")||(m.getNameOfElement(currentPos)=="blue")||(m.getNameOfElement(currentPos)=="yellow")||(m.getNameOfElement(currentPos)=="pink")||(m.getNameOfElement(currentPos)=="green")){
//         PowerrangerAlive = true;
//       }
//       j++;
//     }
//     i++;
//   }
//   if((zedAlive == true)&&(PowerrangerAlive == true)){
//       return(false);
//   } else if((zedAlive == true)&&(PowerrangerAlive == false)){
//     return(true);
//   } else if((zedAlive == false)&&(PowerrangerAlive==true)){
//     return(true);
//   }
//
//
// }
