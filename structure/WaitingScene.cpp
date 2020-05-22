#include "WaitingScene.h"
#include "CGameScene.h"
#include "myFunction.h"
#include "Title.h"
#include "Def.h"
#include "UI.h"
#include <fstream>

Stage * stage;

WaitingScene::WaitingScene(){
    stage= new Stage();
}

WaitingScene::~WaitingScene(){
}


void WaitingScene::Update(float eTime){
	if (MyKeyState(VK_LBUTTON) == 1){
		for (int i = 0; i < ui->eggCount; i++){
			if (inBounds(tempMouse, ui->menuRect[i])){
				stage->setNowStage(i);
				ChangeScene(new CGameScene());
			}
		}
	}
}



void WaitingScene::Render(){
	ui->menuBackGround->Render(&ui->mat);
	for (int i = 0; i<7; i++){
		ui->menu_star[i][stage->menuStar[i]]->Render(&ui->mat);
	}
}
