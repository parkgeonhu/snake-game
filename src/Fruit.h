#ifndef Included_Fruit_H
#define Included_Fruit_H
#include <vector>
#include "CharPosition.h"
#include "Item.h"
#include <ncurses.h>
#include <cstdlib>
#include <string>

class Fruit : public Item
{
public:
    Fruit(std::string t, float eTime);
    ~Fruit() {}
};
#endif