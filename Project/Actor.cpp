#include "Actor.hpp"

#include "Dungeon.hpp"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

/******************************************
    SETTERS
*******************************************/
void Actor::setStats(char c)
{
  x = y = 0;
  sprite = c;
  switch (sprite)
  {
  case 'a':
    name = "Angry Aardvark";
    maxHp = hp = 25;
    str = 5;
    end = 5;
    sen = 5;
    agi = 5;
    exp = 1;
    gold = 1;
    break;
  case 'A':
    name = "Almighty Aardvark";
    maxHp = hp = 70;
    str = 15;
    end = 15;
    sen = 15;
    agi = 15;
    exp = 10;
    gold = 15;
    break;
  default:
    name = "Player";
    maxHp = hp = 100;
    str = 15;
    end = 15;
    sen = 15;
    agi = 15;
    exp = 0;
    gold = 0;
  }
  setBattleSprite();
}

void Actor::setBattleSprite()
{
  string s;
  ifstream fin;
  switch (sprite)
  {
  case 'a':
  case 'A':
    fin.open("Aardvark.txt");
    while (getline(fin, s))
    {
      battleSprite.push_back(s);
    }
    break;
  default:
    fin.open("Player.txt");
    while (getline(fin, s))
    {
      battleSprite.push_back(s);
    }
  }
}

/******************************************
DUNGEON FUNCTIONS
*******************************************/

void Actor::placeAtStart(Dungeon& d)
{
  x = d.startX;
  y = d.startY;
  d.map[y][x] = sprite;
}

void Actor::placeRandomly(Dungeon& d)
{
  char randum;
  bool placed = false;
  do
  {
    randum = rand() % Dungeon::WIDTH;
    x = randum;
    randum = rand() % Dungeon::HEIGHT;
    y = randum;
    placed = (d.map[y][x] == ' ') && (d.map[y][x] = sprite);
  } while (!placed);
}

void Actor::respawn(Dungeon& d)
{
  hp = maxHp;
  d.map[y][x] = ' ';
  placeRandomly(d);
}

bool Actor::move(int xDir, int yDir, Dungeon& d)
{
  bool enemyEncountered = false;
  int randum;
  switch (d.map[y+yDir][x+xDir])
  {
  case '$':
    d.map[y][x] = ' ';
    y += yDir;
    x += xDir;
    d.map[y][x] = sprite;
    randum = d.level + rand() % (d.level*10);
    break;
  case ' ':
    d.map[y][x] = ' ';
    y += yDir;
    x += xDir;
    d.map[y][x] = sprite;
    break;
  case Dungeon::WALL:
    break;
  case Dungeon::EXIT:
    d.generateMap();
    break;
  default:
    enemyEncountered = true;
  }
  return enemyEncountered;
}

bool Actor::moveToTarget(const Actor& a, Dungeon& d)
{
  bool enemyEncountered = false; //Return value
  char dirPrefs[4] = {'x', 'y', 'Y', 'X'}; // x = left, X = right, y = up, Y = down
  int xDist = x - a.x;
  int yDist = y - a.y;

  (xDist < 0) && (dirPrefs[0] = 'X') && (dirPrefs[3] = 'x');
  (yDist < 0) && (dirPrefs[1] = 'Y') && (dirPrefs[2] = 'y');
  if (abs(yDist) > abs(xDist))
  {
    char temp = dirPrefs[0];
    dirPrefs[0] = dirPrefs[1];
    dirPrefs[1] = temp;
    temp = dirPrefs[2];
    dirPrefs[2] = dirPrefs[3];
    dirPrefs[3] = dirPrefs[2];
  }

  bool moved = false;
  for (int i = 0; i < 4 && !moved; i++)
  {
    switch (dirPrefs[i])
    {
    case 'x':
      if (d.map[y][x-1] != Dungeon::WALL)
      {
        enemyEncountered = move(-1, 0, d);
        moved = true;
      }
      break;
    case 'X':
      if (d.map[y][x+1] != Dungeon::WALL)
      {
        enemyEncountered = move(1, 0, d);
        moved = true;
      }
      break;
    case 'y':
      if (d.map[y-1][x] != Dungeon::WALL)
      {
        enemyEncountered = move(0, -1, d);
        moved = true;
      }
      break;
    default:
      if (d.map[y+1][x] != Dungeon::WALL)
      {
        enemyEncountered = move(0, 1, d);
        moved = true;
      }
    }
  }
  return enemyEncountered;
}

/******************************************
BATTLE FUNCTIONS
*******************************************/

int Actor::attack(Actor& a) const
{
  int damage = str + rand() % str - a.end;
  (rand() % a.agi > sen || damage <= 0) && (damage = 1);
  a.hp -= damage;
  (a.hp < 0) && (a.hp = 0);
  return damage;
}