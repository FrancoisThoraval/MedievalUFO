#ifndef element_hpp
#define element_hpp

//#include <iostream>
#include <string>


class Element;
class Position;

/****** Classe d'element, classe mère des unites et des décors, *********/

class Element {
private:
  Position _pos;
public:
  Element ();
  virtual ~Element ();
  Element getElementOnPos();

};

/** classe pour gerer la position et le deplacement des unités **/

class Position {
private:
  int _x;
  int _y;
public:
  Position ();
  virtual ~Position ();
  /** Getter **/
  int getX()const;
  int getY()const;
  /** Setter **/
  void setX(int);
  void setY(int);
};

#endif
