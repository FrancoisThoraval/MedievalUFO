#ifndef game_hpp
#define game_hpp
// #include <SFML/Window.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Audio.hpp>
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
// _gameState	->	6	=	Get player names
// _gameState	->	7	=	Rules
class Game {                                                       // class game, cette classe est la classe du jeux
private:
     bool isExiting();									//vérifie s'il on est en train de quitter le jeu ou non
     void gameLoop();									//gestion du jeu
     void showSpashScreen();								//affiche une image au lancement du jeu
     void showMenu();									//affiche le menu
     int _gameState;									//variable qui indique dans quel état du jeu on se trouve

	sf::RenderWindow _window;							//variables pour gérer l'affichage en sfml
     int _xWindow;										//
     int _yWindow;										//
     bool _isFullScreen;									// vérifie si on est ou non en plein écran
     // bool _isPlaying;
     Player p1,p2;										//Variables joueurs.
public:
     Game(int x, int y);
     ~Game();
     void start();
     void endTurn(Player &, Player &,Map*,Ui*,Position);		//Gestion de la fin du tour
     void enterName();									//Saisie des noms
     void LavaDetector(Map*);
     void LavaDamage(Map*,Player&);

};

#endif
