#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Windows.h"
#include <thread>
#include <chrono>

#include "Dungeon.hpp"
#include "Actor.hpp"

using namespace std;

const int SPEED = 50;
const int MONSTERMOVEINTERVAL = 4;

void dungeonLoop(Actor& p1, vector<Actor>& monsters, Dungeon& d);
void battleLoop(Actor& p1, Actor& p2);

BOOL gotoxy(const WORD x, const WORD y) //Really shouldn't be here but whatever
{
  COORD xy;
  xy.X = x;
  xy.Y = y;
  return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

int main()
{
  srand(time(0));
  Dungeon d;
  Actor p1(233);
  vector<Actor> monsters;
  monsters.push_back(Actor('a'));
  p1.placeAtStart(d);
  monsters[0].placeRandomly(d);
  do
  {
    dungeonLoop(p1, monsters, d);
    battleLoop(p1, monsters[0]);
    if (monsters[0].getHp() <= 0)
    {
      monsters[0].respawn(d);
    }
  } while (p1.getHp() > 0);
  gotoxy(0, 0);
  cout << "Game Over!" << endl << endl << "Press Enter to quit";
  cin.get();
}