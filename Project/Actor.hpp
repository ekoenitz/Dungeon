#ifndef Actor_hpp
#define Actor_hpp

#include "Dungeon.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Actor
{
public:
  Actor(char c) {setStats(c);}
  int getHp() const {return hp;}
  int getMaxHp() const {return maxHp;}
  int getSpriteSize() const {return battleSprite.size();}
  string getName() const {return name;}
  string getLineofBSprite(int i) const {return battleSprite[i];}
  void setStats(char c);
  void setBattleSprite();

  //Dungeon Functions
  void placeAtStart(Dungeon& d); //Currently supperfluous
  void placeRandomly(Dungeon& d);
  void respawn(Dungeon& d);
  bool move(int xDir, int yDir, Dungeon& d);
  bool moveToTarget(const Actor& a, Dungeon& d);

  //Battle Functions
  int attack(Actor& a) const;

private:
  //Map
  int x;
  int y;
  char sprite;
  //Stats
  vector<string> battleSprite;
  string name;
  int maxHp;
  int hp;
  int str;
  int end;
  int sen;
  int agi;
  int exp; //Given when defeated
  int gold;
};

#endif