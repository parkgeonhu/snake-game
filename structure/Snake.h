#pragma once

class Snake : public IObject{
private:
    
public:

	Snake(Stage *stage, SoundMgr *sound);
	~Snake();

	Stage *stage;
    
	int choiceCount;
	int select;

	void Update(float eTime);
    void Render();
    
    
};