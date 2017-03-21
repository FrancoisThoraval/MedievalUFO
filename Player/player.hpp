#ifndef player_hpp
#define player_hpp

class Player {
private:
  int _energy;
  bool  _lost;
public:
  Player ();
  ~Player ();

  int getEnergy()const;
  bool getLost()const;

  void setEnergy(int);
  void setLost(bool);

  void EndOfTurn();
};

#endif
