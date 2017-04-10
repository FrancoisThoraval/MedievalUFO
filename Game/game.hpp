#ifndef game_hpp
#define game_hpp
// #include <SFML/Window.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "splashScreen.hpp"
#include "menu.hpp"
#include "../Element/map.hpp"
#include "../Player/player.hpp"
#include "../Unit/ayayay.cpp"
#include <typeinfo>

// _gameState  ->   0    =    Initialization
// _gameState  ->   1    =    Splash
// _gameState  ->   2    =    Pause
// _gameState  ->   3    =    Menu
// _gameState  ->   4    =    Playing
// _gameState  ->   5    =    End
class Game {
private:
     bool isExiting();
     void gameLoop();
     void showSpashScreen();
     void showMenu();
     int _gameState;
     sf::RenderWindow _window;
     int _xWindow;
     int _yWindow;
     bool _isFullScreen;
     // bool _isPlaying;
     Player p1,p2;
public:
     Game(int x, int y);
     ~Game();
     void start();
     void endTurn(Player &, Player &,Map*);
     void enterName();


};

#endif
