#include "Dungeon.hpp"

#include <string>
#include <cstdlib>
#include "Windows.h"

using namespace std;

void Dungeon::generateMap()
{
  map.clear();
  string s(WIDTH, WALL);
  for (int i = 0; i < HEIGHT; i++) {map.push_back(s);}
  char randum;

  for (int y = 1; y < HEIGHT-3; y+=3)
  {
    for (int x = 1; x < WIDTH-3; x+=3)
    {
      randum = rand() % 26;
      randum += 'A';
      switch (randum)
      {
      case 'A':
        (y > 1 && map[y-1][x+1] == WALL) && (map[y-1][x+1] = ' ');
        (x > 1 && map[y+1][x-1] == WALL) && (map[y+1][x-1] = ' ');
        map[y][x] = ' ';
        map[y][x+1] = ' ';
        map[y][x+2] = ' ';
        map[y+1][x] = ' ';
        map[y+1][x+2] = ' ';
        map[y+2][x] = ' ';
        map[y+2][x+2] = ' ';
        break;
      case 'B':
      case 'C':
        (y > 1 && map[y-1][x] == WALL) && (map[y-1][x] = ' ');
        (x > 1 && map[y+1][x-1] == WALL) && (map[y][x-1] = ' ');
        map[y][x] = ' ';
        map[y][x+1] = ' ';
        map[y][x+2] = ' ';
        map[y+1][x] = ' ';
        map[y+2][x] = ' ';
        map[y+2][x+1] = ' ';
        map[y+2][x+2] = ' ';
        break;
      case'E':
      case 'F':
      case 'G':
      case 'I':
        (y > 1 && map[y-1][x+1] == WALL) && (map[y-1][x+1] = ' ');
        (x > 1 && map[y+1][x-1] == ' ') && (map[y+1][x] = ' ');
        map[y][x+1] = ' ';
        map[y+1][x+1] = ' ';
        map[y+2][x+1] = ' ';
        break;
      case 'H':
        (x > 1 && map[y+1][x-1] == WALL) && (map[y][x-1] = ' ');
        (y > 1 && map[y-1][x+1] == ' ') && (map[y][x+1] = ' ') && (map[y+1][x+1] = ' ');
        map[y][x] = ' ';
        map[y][x+2] = ' ';
        map[y+1][x] = ' ';
        map[y+1][x+1] = ' ';
        map[y+1][x+2] = ' ';
        map[y+2][x] = ' ';
        map[y+2][x+2] = ' ';
        break;
      case 'J':
        (y > 1 && map[y-1][x+1] == WALL) && (map[y-1][x+1] = ' ');
        (x > 1 && map[y+1][x-1] == WALL) && (map[y+1][x-1] = ' ');
        map[y][x+1] = ' ';
        map[y+1][x] = ' ';
        map[y+1][x+1] = ' ';
        break;
      case 'K':
      case 'L':
        ((y > 1 && map[y-1][x+1] == WALL) && (map[y-1][x] = ' ')) || (y > 1 && map[y-1][x+1] == ' ') && (map[y][x+1] = ' ') && (map[y+1][x+1] = ' ');;
        (x > 1 && map[y+1][x-1] == ' ') && (map[y+1][x] = ' ');
        map[y][x+1] = ' ';
        map[y+1][x+1] = randum == 0 ? TREASURE : ' ';
        map[y+1][x+2] = ' ';
        break;
      case 'M':
      case 'N':
      case 'O':
        (x > 1 && map[y+1][x-1] == WALL) && (map[y+1][x-1] = ' ');
        (y > 1 && map[y-1][x+1] == ' ') && (map[y][x+1] = ' ');
        map[y+1][x] = ' ';
        map[y+1][x+1] = ' ';
        map[y+1][x+2] = ' ';
        break;
      case 'P':
        (x > 1 && map[y+1][x-1] == ' ') && (map[y+1][x] = ' ');
        (y > 1 && map[y-1][x+1] == ' ') && (map[y][x+1] = ' ');
        map[y+1][x+1] = ' ';
        map[y+1][x+2] = ' ';
        map[y+2][x+1] = ' ';
        break;
      case 'Q':
        (y > 1 && map[y-1][x+1] == WALL) && (map[y-1][x+1] = ' ');
        (x > 1 && map[y+1][x-1] == WALL) && (map[y+1][x-1] = ' ');
        map[y][x] = ' ';
        map[y][x+1] = ' ';
        map[y][x+2] = ' ';
        map[y+1][x] = ' ';
        map[y+1][x+2] = ' ';
        map[y+2][x] = ' ';
        map[y+2][x+1] = ' ';
        map[y+2][x+2] = ' ';
        break;
      case 'R':
        (x > 1 && map[y+1][x-1] == WALL) && (map[y+1][x-1] = ' ');
        (y > 1 && map[y-1][x+1] == ' ') && (map[y][x+1] = ' ');
        map[y+1][x] = ' ';
        map[y+1][x+1] = ' ';
        map[y+2][x+1] = ' ';
        break;
      case 'T':
        (x > 1 && map[y+1][x-1] == WALL) && (map[y+1][x-1] = ' ');
        (y > 1 && map[y-1][x+1] == ' ') && (map[y][x+1] = ' ');
        map[y+1][x] = ' ';
        map[y+1][x+1] = ' ';
        map[y+1][x+2] = ' ';
        map[y+2][x+1] = ' ';
        break;
      case 'U':
      case 'V':
        (x > 1 && map[y+1][x-1] == WALL) && (map[y+1][x-1] = ' ');
        (y > 1 && map[y-1][x+1] == ' ') && (map[y][x+1] = ' ');
        map[y][x] = ' ';
        map[y][x+2] = ' ';
        map[y+1][x] = ' ';
        map[y+1][x+2] = ' ';
        map[y+2][x] = ' ';
        map[y+2][x+1] = ' ';
        map[y+2][x+2] = ' ';
        break;
      case 'W':
      case 'X':
      case 'Y':
      case 'Z':
        (y > 1 && map[y-1][x+1] == WALL) && (map[y-1][x+1] = ' ');
        (x > 1 && map[y+1][x-1] == WALL) && (map[y+1][x-1] = ' ');
        map[y][x+1] = ' ';
        map[y+1][x] = ' ';
        map[y+1][x+1] = ' ';
        map[y+1][x+2] = ' ';
        map[y+2][x+1] = ' ';
        break;
      default:
        (y > 1 && map[y-1][x+1] == WALL) && (map[y-1][x+1] = ' ');
        (x > 1 && map[y+1][x-1] == WALL) && (map[y+1][x-1] = ' ');
        map[y][x] = ' ';
        map[y][x+1] = ' ';
        map[y][x+2] = ' ';
        map[y+1][x] = ' ';
        map[y+1][x+1] = ' ';
        map[y+1][x+2] = ' ';
        map[y+2][x] = ' ';
        map[y+2][x+1] = ' ';
        map[y+2][x+2] = ' ';
      }
    }
  }
  //Place Start
  bool placed = false;
  do
  {
    randum = rand() % WIDTH;
    startX = randum;
    randum = rand() % HEIGHT;
    startY = randum;
    placed = map[startY][startX] == ' ';
  } while (!placed);
  //Place Exit
  placed = false;
  do
  {
    randum = rand() % WIDTH;
    exitX = randum;
    randum = rand() % HEIGHT;
    exitY = randum;
    placed = (map[exitY][exitX] == ' ') && (map[exitY][exitX] = EXIT);
  } while (!placed);
  //Place Treasure
  randum = rand() % 4;
  for (int i = 0; i < randum; i++)
  {
    placed = false;
    do
    {
      int randX = rand() % WIDTH;
      int randY = rand() % HEIGHT;
      placed = (map[randY][randX] == ' ') && (map[randY][randX] = TREASURE);
    } while (!placed);
  }
}

BOOL gotoxy(const WORD x, const WORD y);

ostream& operator << (ostream& out, const Dungeon& d)
{
  gotoxy(0, 0);
  for (const string& s : d.map)
  {
    out << s << endl;
  }
  return out;
}