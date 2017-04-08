#include "game.hpp"

#include <iostream>
Game::Game(int x, int y){
     _gameState = 0; //Initialization
     _xWindow = x;
     _yWindow = y;
     _isFullScreen = false;
}

Game::~Game(){

}

void Game::start(){
     if (_gameState != 0)
          return;

     _window.create(sf::VideoMode(_xWindow,_yWindow,32),"Power Rangers - Ultimate Battle Simulator (Alpha)",sf::Style::Default);
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




void Game::gameLoop(){
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
                    enterName();
                    //Création des éléments du jeu
                    Map m(800,500);
                    m.createWorld(_window);
                    Ui ui;
                    //Création Unité p1 (power ranger)
                    Zedd zedd;
                    PowerRanger pink("pink"), red("red"), blue("blue"), green("green"),yellow("yellow");
                    Position posPink(9,13),posRed(7,13),posBlue(8,13),posGreen(10,13),posYellow(11,13);
                    Position posZedd(1,1);
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
                    m.getElementW1(posRed).setDefault(4);
                    // p1.getUnit(1).setDefault(4);
                    m.getElementW1(posBlue).setDefault(4);
                    // p1.getUnit(2).setDefault(4);
                    m.getElementW1(posGreen).setDefault(4);
                    // p1.getUnit(3).setDefault(4);
                    m.getElementW1(posYellow).setDefault(4);
                    // p1.getUnit(4).setDefault(4);
                    m.getElementW1(posPink).setDefault(4);
                    // p1.getUnit(0).setDefault(4);

                    std::cout<<"NAME TEST : "<<m.getElementW1(posRed).getName()<<"\n"<<"NAME TEST 2 : "<<red.getName()<<"\n"<<"NAME TEST 3  : "<<p1.getUnit(1).getName()<<std::endl;
                    std::cout<<"DEFAULT TEST : "<<m.getElementW1(posRed).getDefault()<<"\n"<<"DEfault TEST 2 : "<<red.getDefault()<<"\n"<<"DEFAULT TEST 3 :"<<p1.getUnit(1).getDefault()<<std::endl;

                    std::cout<<"TYPE : "<<typeid(m.getElementW1(posRed)).name()<<std::endl;

                    _window.clear(sf::Color(0,0,0));
                    m.drawWorld(_window);
                    ui.drawUi(_window,p1,p2);
                    while (_gameState == 4) {
                         _window.display();
                         // ui.displayInfoPlayer(_window,p);
                         while (_window.pollEvent(currentEvent)) {
                              if (currentEvent.type == sf::Event::Closed) {
                                   _gameState = 5; //End
                              }
                              if(currentEvent.type == sf::Event::KeyPressed)
                              {

                                   // Il doit y avoir un souci avec la sfml peut-être qui fais que le code de l'event pour la touche entrée est pris pour celui de la touche echap.
                                   // Si on commente l'event du menu y'a plus le bug du spam de la touche entrée.
                                   if(currentEvent.key.code == sf::Keyboard::Escape){
                                        std::cout << "Opening menu" << '\n';
                                        showMenu(); //Créer un menu spécial
                                   }
                                   if(currentEvent.key.code == sf::Keyboard::Return){
                                        std::cerr << "ending turn" << '\n';
                                        endTurn(p1,p2,&m); //Créer un menu spécial
                                        ui.drawUi(_window,p1,p2);
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
                         if (p1.getWhosPlaying()) {
                           m.handleClick(_window,currentEvent,p1,ui);

                         } else if(p2.getWhosPlaying()){
                           m.handleClick(_window,currentEvent,p2,ui);
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
               }
          }
     }
}

void Game::showSpashScreen(){
     SplashScreen s;
     s.show(_window);
     _gameState = 3;
}


void Game::showMenu(){
     Menu m;
     m.show(_window);
     m.handleClick(_window);
     switch (m.getMenuChoice()) {
          case 1: _gameState = 4;
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

void Game::endTurn(Player &p1, Player &p2,Map *m){
     if (p1.getWhosPlaying()) {
          p1.setWhosPlaying(false);
          p2.setWhosPlaying(true);
          std::cerr << "Player 2, Your turn !" << '\n';
          p1.EndOfTurn(m);
     }else{
          p2.setWhosPlaying(false);
          p1.setWhosPlaying(true);
          std::cerr << "Player 1, Your turn !" << '\n';
          p2.EndOfTurn(m);
     }
}


void Game::enterName(){
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
  text.setPosition(0,500);
  text.setColor(sf::Color::White);
  text.setCharacterSize(24);
  int k = 0;
  bool end = false;
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

  std::cout <<"=====\nPlayer 2: ";
  _window.draw(text);
  _window.display();
  k = 0;
  end = false;
  text.setPosition(0,550);
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
  std::cout<<"nom complet : "<<nomtest<<std::endl;
  p2.setName(nomtest);

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
}
