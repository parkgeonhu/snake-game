#include "GameScene.h"
#include "Stage.h"
#include "CharPosition.h"


Stage::Stage(){
    nowStage=0;
}

Stage::~Stage(){
}

void Stage::Update(float eTime){
    
    if(clear){
        refresh();
        clear=false;
    }
	// if (nowStage == hippoStage[0])
	// {
	// 	for (int j = 0; j < hippoCount[0]; j++)
	// 	{
	// 		hippo[j]->Update(eTime);
	// 	}
	// }
	// if (nowStage == 5) { footHold->pos.y = stageRect[5][4].top - 400; }
	// if (nowStage == 6) { bossHippoAni->Update(eTime); }
	// if (nowStage == 6 && isStage7Button[0] && isStage7Button[1] && isStage7Button[2])
	// {
	// 	clear = 1;
	// }
	// if (clear)
	// {
	// 	if (stage7FootHold->pos.y  < 300)
	// 	{
	// 		stage7FootHold->pos.y += 50 * eTime;
	// 		bossHippoAni->pos.y += 50 * eTime;
	// 	}
	// 	else
	// 	{
	// 		clear = 2;
	// 		state = Clear;
	// 		sound->Stop(INGAME_BGM);
	// 		sound->Stop(BOSS_BGM);
	// 		sound->Play(CLEAR_BGM);
	// 	}
	// }
}

void Stage::Render() {
    
    
	// sky[0]->Render(&this->mat);

	// for (int i = 0; i < 2; i++)
	// {
	// 	if (nowStage == hippoStage[i])
	// 	{
	// 		for (int j = 0; j < hippoCount[i]; j++)
	// 		{
	// 			hippo[j]->Render(&this->mat);
	// 		}
	// 	}
	// }

	// if (nowStage == 5)
	// {
	// 	footHold->Render(&this->mat);
	// }
	// if (nowStage == 6)
	// {
	// 	stage7FootHold->Render(&this->mat);
	// 	bossHippoAni->Render(&this->mat);
	// }
}