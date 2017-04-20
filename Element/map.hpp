#ifndef map_hpp
#define map_hpp

// #include "element.hpp"
#include "../Unit/unit.hpp"
#include "../Scenery/scenery.hpp"
#include "../Game/menu.hpp"
#include "../Player/player.hpp"
#include <SFML/Graphics.hpp>
// #include "../Unit/ayayay.cpp"
#include <iostream>
#include <sstream>
#include <sys/time.h>
#include <typeinfo>

const int TILESIZE = 32; 											//Taille d'une tuile (carré)

class Unit;
class Player;
class Ui;


// 	********************************************
//		MAP
// 	- Gère la position des élements dans le jeux
// 	- Affiche ces éléments
// 	- Gère les clics sur ces éléments
//	********************************************

class Map {
protected:
  Unit ***_world1;													//Tableau contenant les unités (premier plan)

  Scenery **_world2;												//Tableau contenant le décor (second plan)

  int _sizeX;														//Taille X de world1 et world2.
  int _sizeY;														//Taille Y de world1 et world2.

  sf::Sprite **_mapTile; 											//Tableau contenant les sprites de chaque élément visible pour ensuite gérer les clics.

  int _tileClicked;

  Unit *_tabUnit;

  int _compttab;

  Position _unitSelected; 											//Position de l'unité cliquée.
public:
  Map (int, int);
  ~Map ();
  friend class Element;
  Scenery getElementW2(Position)const;  								//Récupère un élément du décor dans World2

  Unit* getElementW1(Position)const;    								//Récupère un élément du décor dans World1

  void setElementW1(Position,Unit*);    								//Place un élément du décor dans World1

  void setElementW2(Position,Scenery&);									//Place un élément du décor dans World2

  std::string getNameOfElement(Position)const;							//Récupère le nom d'un élement en position pos d'abord
  																//dans world1, sinon dans world2.

  void createWorld(sf::RenderWindow &);									//Rempli wordl2 d'élements du décor de façon aléatoire

  void drawWorld(sf::RenderWindow &);									//Affiche les élements du jeu (appelle createTile)

  void createTile(int,int,sf::RenderWindow &,sf::Texture &);				//Dessine une tuile du jeu en fonction de ce qu'elle contient.

  bool isOnMap(Position pos);											//Vérifie qu'une position est possible sur la map.

  void handleClick(sf::RenderWindow &, sf::Event &,Player &, Player &,Ui &);	//Gère les clics sur la map.

  int getSizeX();													//Récupère la taille X de la map (world1 + world2).
  int getSizeY();													//Récupère la taille Y de la map (world1 + world2).



  void setSizeX(int);												//Défini la taille X de la map (world1 + world2).
  void setSizeY(int);												//Défini la taille Y de la map (world1 + world2).

  int getCompt()const;												//Gestion des power ranger groupés dans le super robot
  Unit getTab(int)const;												//
  void setCompt(int);												//
  void setInTab(Unit&);												//

  Position   getUnitSelected();										//Récupère la position de l'unité séléctionnée.
};

// 	********************************************
//		USER INTERFACE (UI)
// 	- Gère les élements de l'interface
// 	- Affiche les bons boutons correspondant aux différents éléments du jeu
// 	- Gère les clics sur ces boutons
//	********************************************
class Ui{
private:
  int _state;														//Indique s'il faut afficher l'interface (on s'en sert ?)

  sf::Sprite *_buttonArray;											//Tableau contenant les sprites de chaque boutons pour gérer les clics

  int _numattack;													//Le numéro de l'attaque séléctionnée via les boutons.

  int _unitClicked;													//Numéro de l'unité cliquée pour afficher les bons boutons.

  sf::Sprite _alpha;												//sprite du bouton d'aide.

public:
     Ui ();
     ~Ui ();
     void drawUi(sf::RenderWindow &,Player &, Player &,Unit*);					//Dessine l'interface et ses éléments.

     void handleClick(sf::RenderWindow &,Position pos, Map *);				//Gère les clics sur l'interface.

     void setState(int);
     int getState()const;

     int getAttack() const;											//Récupère le numéro de l'attaque choisie.

     void setAttack(int);											//Insère la valeur de l'attaque choisie.

     void setUnitClicked(int);										//Insère le numéro de l'unité séléctionnée.

     void setUnitClicked(std::string);									//Insère le numéro de l'unité séléctionnée en fonction de son nom.
};

#endif
