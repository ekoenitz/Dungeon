#ifndef Dungeon_hpp
#define Dungeon_hpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Dungeon
{
public:
  Dungeon() {level = 1; generateMap();}
  void generateMap();

  const static char WALL = 178;
  const static char EXIT = '@';
  const static char TREASURE = '$';
  const static int WIDTH = 29; //Width and height should be divisble by 3 when -2
  const static int HEIGHT = 17;

  friend class Actor;
  friend ostream& operator << (ostream& out, const Dungeon& d);
private:
  vector<string> map;
  int startX;
  int startY;
  int exitX;
  int exitY;
  int level;
};

#endif