#include "WaitingScene.h"
#include "GameScene.h"
#include "myFunction.h"
#include "UI.h"
#include <fstream>

Stage * stage;

WaitingScene::WaitingScene(){
    stage= new Stage();
    stage->setNowStage(1);
	ChangeScene(new GameScene());
}

WaitingScene::~WaitingScene(){
    
}


void WaitingScene::Update(){
}



void WaitingScene::Render(){
	ui->menuBackGround->Render(&ui->mat);
	for (int i = 0; i<7; i++){
		ui->menu_star[i][stage->menuStar[i]]->Render(&ui->mat);
	}
}
