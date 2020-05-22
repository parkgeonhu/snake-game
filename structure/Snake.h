#pragma once
#include <ncurses.h>


class Snake : public IObject{
private:
    
public:

	Snake(Stage *stage, SoundMgr *sound);
	~Snake();

	Stage *stage;
    std::vector<CharPosition> entire
    
	int choiceCount;
	int select;

	void Update(float eTime);
    void Render();
    
    
};