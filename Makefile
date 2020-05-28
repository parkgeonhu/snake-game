all:
	g++ src/GameScene.cpp src/Snake.cpp src/Stage.cpp src/WaitingScene.cpp src/myFunction.cpp src/ItemManager.cpp src/main.cpp -lncurses -o /tmp/a.out && /tmp/a.out
