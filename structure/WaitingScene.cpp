#include "WaitingScene.h"
#include "GameScene.h"
#include "myFunction.h"

Stage * stage;

WaitingScene::WaitingScene(){
    stage= new Stage();
    stage->setNowStage(1);

}

WaitingScene::~WaitingScene(){
    
}


void WaitingScene::Update(){
    ChangeScene(new GameScene());
}



void WaitingScene::Render(){
	// ui->menuBackGround->Render(&ui->mat);
	// for (int i = 0; i<7; i++){
	// 	ui->menu_star[i][stage->menuStar[i]]->Render(&ui->mat);
	// }
}
