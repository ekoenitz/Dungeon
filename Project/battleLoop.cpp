#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include "Windows.h"
#include <thread>
#include <chrono>

#include "Dungeon.hpp"
#include "Actor.hpp"

BOOL gotoxy(const WORD x, const WORD y);


void clearScreen()
{
  gotoxy(0, 0);
  string s(Dungeon::WIDTH*2, ' ');
  for (int i = 0; i < Dungeon::HEIGHT*2; i++)
  {
    cout << s << endl;
  }
  gotoxy(0, 0);
}

void outputCombatants(Actor& p1, Actor& p2)
{
  int p1Size = p1.getSpriteSize();
  int p2Size = p2.getSpriteSize();
  for (int i = 0; i < p1Size; i++)
  {
    cout << p1.getLineofBSprite(i) << (i == 6 ? "   VS   " : "        ") << (i < p2Size ? p2.getLineofBSprite(i) : " ") << endl;
  }
}

void battleLoop(Actor& p1, Actor& p2)
{
  clearScreen();
  do
  {
    gotoxy(0, 0);
    outputCombatants(p1, p2);
    cout << "Battle!" << endl;
    cout << p1.getName() << " VS " << p2.getName() << endl;
    cout << "HP: " << p1.getHp() << '/' << p1.getMaxHp() << endl;
    cout << endl << "Press Enter to begin attack!" << endl;
    cin.get();
    cout << p1.getName() << " Attacked " << p2.getName() << " For " << p1.attack(p2) << " Points of Damage!" << endl;
    cout << p2.getName() << " Attacked " << p1.getName() << " For " << p2.attack(p1) << " Points of Damage!" << endl;
    cout << endl << "Press Enter to continue";
    cin.get();
  } while (p1.getHp() > 0 && p2.getHp() > 0);
  clearScreen();
}