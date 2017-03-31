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
                    _window.clear();
                    //Saisie des noms de joueurs
                    std::string name,name2;
                    // COMMENTAIRE ICI JUSQUA
                    std::cout << "=====\nPlayer 1: ";
                    sf::Event evenementnom;
                    std::string nomtest;
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
                            if((evenementnom.text.unicode == 10)||(evenementnom.text.unicode == 13)){
                              end = true;
                            }
                          }
                        }
                      }
                    }
                    sf::Font font;
                    font.loadFromFile("/home/taiqui/Documents/FAC/MedievalUFO/Game/arial.ttf");
                    sf::Text text;
                    text.setFont(font);
                    // text.setString(nomtest);
                    text.setColor(sf::Color::White);
                    text.setCharacterSize(24);
                    // _window.clear();
                    // _window.draw(text);
                    // _window.display();
                    //_window.display();
                    std::cout<<"nom complet : "<<nomtest<<std::endl;
                    p1.setName(nomtest);
                    p1.setWhosPlaying(true);
                    std::cout << "=====\nPlayer 2: ";
                    //std::cin>>name;
                    k = 0;
                    end = false;
                    //nomtest = "";
                    while((k<10)&&(end == false)){

                      while(_window.pollEvent(evenementnom)){
                        if(evenementnom.type == sf::Event::TextEntered){
                          if(evenementnom.text.unicode <128){
                            //name += static_cast<char>(evenementnom.text.unicode);
                            std::cout<<"test carac : "<<static_cast<char>(evenementnom.text.unicode)<<std::endl;
                            name2 += static_cast<char>(evenementnom.text.unicode);
                            k++;
                            if((evenementnom.text.unicode == 10)||(evenementnom.text.unicode == 13)){
                              end = true;
                            }
                          }
                        }
                      }
                    }
                    std::cout<<"nom complet : "<<nomtest<<std::endl;
                    p2.setName(nomtest);
                    text.setString("Joueur 1 :"+nomtest+"\n"+"Joueur 2 : "+name2);
                    _window.clear();
                    _window.draw(text);
                    _window.display();
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
                    Ui ui;
                    //Création Unité p1 (power ranger)
                    PowerRanger pink("pink"), red("red"), blue("blue"), green("green"),yellow("yellow");
                    Position posPink(9,13),posRed(7,13),posBlue(8,13),posGreen(10,13),posYellow(11,13);
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
                                   std::cout << "Opening menu" << '\n';
                                   if(currentEvent.key.code == sf::Keyboard::Escape){
                                        showMenu(); //Créer un menu spécial
                                   }
                                   if(currentEvent.key.code == sf::Keyboard::Return){
                                        std::cerr << "ending turn" << '\n';
                                        endTurn(p1,p2); //Créer un menu spécial
                                        ui.drawUi(_window,p1,p2);
                                   }

                                   if (currentEvent.key.code == sf::Keyboard::F) {
                                        std::cout << "Toggling fullscreen" << '\n';
                                        if (_isFullScreen) {
                                             _window.create(sf::VideoMode(_xWindow,_yWindow,32),"Medieval UFO",sf::Style::Default);
                                             _isFullScreen = false;
                                             m.drawWorld(_window);
                                             _window.display();
                                        }else{
                                             _window.create(sf::VideoMode(_xWindow,_yWindow,32),"Medieval UFO",sf::Style::Fullscreen);
                                             _isFullScreen = true;
                                             m.drawWorld(_window);
                                             _window.display();
                                        }

                                   }

                              }
                         }
                         if (p1.getWhosPlaying()) {
                           m.handleClick(_window,currentEvent,p1);
                         } else if(p2.getWhosPlaying()){
                           m.handleClick(_window,currentEvent,p2);
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

void Game::endTurn(Player &p1, Player &p2){
     if (p1.getWhosPlaying()) {
          p1.setWhosPlaying(false);
          p2.setWhosPlaying(true);
          std::cerr << "Player 2, Your turn !" << '\n';
     }else{
          p2.setWhosPlaying(false);
          p1.setWhosPlaying(true);
          std::cerr << "Player 1, Your turn !" << '\n';
     }
     p1.setEnergy(100);
     p2.setEnergy(100);
}
