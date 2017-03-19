#ifndef zedd_hpp
#define zedd_hpp
#include "unit.hpp"
#include "../Element/map.hpp"

// Element -> Unit  -> Map
//                  -> Zedd   -> Map
//                            -> Unit
class Zedd;

class Zedd : public Unit{
private:
  bool _activeExpendNade;
  int _invocation;
  int _puttiesCalling;
  int _apocalypseHole;
  Weapon* _thirdWeapon;
  Weapon* _fourthWeapon;

public:
  Zedd ();
  virtual ~Zedd ();
  int getActiveExpendNade()const;
  int getInvocation()const;
  int getPuttiesCalling()const;
  int getApocalypseHole()const;

  void setActiceExpendNade(int);
  void setInvocation(int);
  void setPuttiesCalling(int);
  void setApocalypseHole(int);

  void ThrowExtendNade(Position,Map*);
  void Invocation(Position,Map*);
  //void PuttiesCalling(Position);
  //void ApocalypseHole();
};

#endif
