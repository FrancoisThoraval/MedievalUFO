#include <iostream>
#include <typeinfo>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "unit.hpp"

/*******************************************************/
template<typename T>
void Advice_ayayay(sf::RenderWindow& _window,T type){
  // sf::Texture t;
  int x;
  int y;
  // t.loadFromFile("./Textures/LPC_Terrain/terrain.png");
  // sf::Sprite s;
  // sf::Text text;
  // s.setTexture(t);
  // s.setTextureRect(sf::IntRect());
  // s.setPosition(x*50,y*50);
  // _window.draw(s);

  if(type.getName()=="Zedd"){
     Zedd zed;
     zed = type;

    // text.setString("C'est Zedd ! il lui reste :"+std::to_string(zed.getHealthPoints()));
    // text.setPosition();
    std::cout << "c'est zedd magle" << '\n';
  } else if(type.getName()=="Putties"){
    Putties pu;
    pu = type;
    std::cout << "c'est un put magle" << '\n';
    // text.setString("C'est un Putties, il lui reste : "+pu.getHealthPoints());
  }  else if (type.getName()=="RobotPR"){
    RobotPR rpr;
    rpr = type;
    // text.setString("C'est LE RobotPR, il lui reste : "+std::to_string(rpr.getHealthPoints()));
  } else if(type.getName()=="TurtleTank"){
    TurtleTank tt;
    tt = type;
    // text.setString("C'est le ROBOT TORTUE ULTIME !!, il lui reste : "+std::to_string(tt.getHealthPoints()));
  } else {
    PowerRanger pr;
    pr = type;
    // text.setString("C'est un des PowerRanger ! il lui reste "++std::to_string(pr.getHealthPoints()));
    // std::cout<<"GROSSE BITE"<<std::endl;
    // std::string test = "Il lui reste "+std::to_string(type.getHealthPoints());
    // std::cout<<test<<std::endl<<"FIN"<<std::endl;;
  }
  // text.setPosition();
  // _window.draw(text);
  // */

}
/******************************************************/
