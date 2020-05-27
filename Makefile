all:
	g++ src/GameScene.cpp src/Snake.cpp src/Stage.cpp src/WaitingScene.cpp src/myFunction.cpp src/Fruit.cpp src/PoisonItem.cpp src/main.cpp -lncurses -o /tmp/a.out && /tmp/a.out
