#pragma once
#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include "IObject.h"

class Format : public IObject
{
public:

    int maxheight, maxwidth;

    Format();
    ~Format();
    void Update(float eTime);
    void Render();
};
