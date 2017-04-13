#ifndef scenery_hpp
#define scenery_hpp

#include "../Element/element.hpp"
#include <string>
#include <iostream>

class Scenery;
class Tree;
class Water;
class Hill;

/** Class principal du decors **/

class Scenery : public Element {
protected:
  std::string _name;
public:
  Scenery ();
  ~Scenery ();
  virtual std::string getName()const;
  void setName(std::string);
};


class Tree : public Scenery{
private:
  /* Vide */
public:
  Tree ();
  ~Tree ();

};

class Water : public Scenery {
private:
  /* Vide */
public:
  Water ();
  ~Water ();

};

class Hill : public Scenery {
private:
  /* Vide */
public:
  Hill ();
  ~Hill ();

};

class Lava : public Scenery {
private:
  int _waitToTransform;
public:
  Lava ();
  ~Lava ();
  int getTransformation()const;
  void setTransformation(int);
};

#endif
