#ifndef Included_Poison_H
#define Included_Poison_H
#include <vector>
#include "CharPosition.h"
#include "Item.h"
#include <ncurses.h>
#include <cstdlib>

class Poison : public Item
{
public:
    Poison(std::string t, float eTime);
    ~Poison() {}
};
#endif