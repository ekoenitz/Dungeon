#include <iostream>
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

void dungeonLoop(Actor& p1, vector<Actor>& monsters, Dungeon& d)
{ 
  int monsterMove = 0;
  bool enemyEncountered = false;
  do
  {
    cout << d << endl << p1.getName() << "'s HP: " << p1.getHp() << '/' << p1.getMaxHp();
    if (GetAsyncKeyState(VK_UP))
    {
      enemyEncountered = p1.move(0, -1, d);
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
      enemyEncountered = p1.move(0, 1, d);
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
      enemyEncountered = p1.move(-1, 0, d);
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
      enemyEncountered = p1.move(1, 0, d);
    }
    monsterMove == 0 ? enemyEncountered = monsters[0].moveToTarget(p1, d), monsterMove = MONSTERMOVEINTERVAL : monsterMove--;
    this_thread::sleep_for(chrono::milliseconds(SPEED));
  } while (!enemyEncountered);
}