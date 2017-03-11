#ifndef element_hpp
#define element_hpp

//#include <iostream>
#include <string>


class Element;
class Position;

<<<<<<< HEAD

=======
>>>>>>> 6a1aaf458564ca985e411b81e6bc1c45c351d50c
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

<<<<<<< HEAD

/****** Classe d'element, classe mère des unites et des décors, *********/

class Element {
private:
=======
/****** Classe d'element, classe mère des unites et des décors, *********/

class Element {
protected:
>>>>>>> 6a1aaf458564ca985e411b81e6bc1c45c351d50c
  Position _pos;
public:
  Element ();
  virtual ~Element ();
<<<<<<< HEAD
  Position getElementOnPos()const;
  void setElementPosition(Position,Element);

};



=======
  Position getElementOnPos();
  void setElementPosition(Position,Element);

  Element &operator=(const Element &e){
      this->_pos = e._pos;
      return (*this);
  }
};

>>>>>>> 6a1aaf458564ca985e411b81e6bc1c45c351d50c
#endif
