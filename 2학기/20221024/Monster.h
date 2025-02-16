#ifndef __MONSTER_H__
#define __MONSTER_H__

#include <string>
#include <cstdlib>
#include <ctime>
#include "Canvas.hpp"

class Monster {
protected:
    string name;
    char icon;
    int x, y, nItem;

    void clip(int xMax, int yMax) {
      if(x < 0) x = 0;
      if(x >= xMax) x = xMax - 1;
      if(y < 0) y = 0;
      if(y >= xMax) y = yMax - 1;
    }

    void eat(int map[DIM][DIM]) {
      if(map[y][x] == 1) {
        map[y][x] = 0;
        nItem++;
      }
    }
public:
    Monster(string name = "±´π∞", char icon = '@', int x = 0, int y = 0) : name(name), icon(icon), x(x), y(y), nItem(0) {}

    virtual ~Monster() {
      cout << name << icon << " ≈¿Â«’¥œ¥Ÿ~~" << endl;
    }

    void draw(Canvas& canvas) {
      canvas.draw(x, y, icon);
    }
    
    virtual void move(int map[DIM][DIM], int xMax, int yMax) = 0;

    void print() {
      cout << name << icon << ":" << nItem << endl;
    }
};

#endif
