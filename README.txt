<    단    계    별     과    제    >
------------------------------------
1단계 : Map의 구현 (V)
-> Stage를 3단계로 구분하고 Stage 별로 형태가 다른 Map을 출력합니다. Map의 세로길이는 32, 가로길이는 62으로 설정합니다. MapManager의 char data 배열의 값 중 0은 뱀이 움직일 수 있는 빈칸, 1은 Snake의 머리와 충돌할 경우의 죽는 벽, 2는 gate가 생성될 수 없는 벽, 3은 Snake의 머리, 4는 Snake의 몸통, 5는 Snake의 크기가 늘어나는 아이템, 6은 Snake의 크기가 줄어드는 아이템, 7은 Gate, 8은 빈칸입니다.

2단계 : Snake 표현 및 조작 (V)
-> Snake의 y좌표, x좌표를 묶어 vector에 저장합니다. CharPosition는 Object의 좌표 x,y를 효율적으로 나타내기 위해서 사용했습니다. CharPosition test; 와 같은 코드를 타이핑 했다면 test.x, test.y 형식으로 접근할 수 있습니다. 이는 Snake의 몸을 표현할 때도 쓰이고, 아이템, 게이트의 위치를 표현할 때 사용됩니다. Map에서 Snake의 Head는 3, Body는 4로 구분합니다. 실행화면에서 머리는 H, 몸통은 B로 표시합니다. 사용자의 입력에 따라 스네이크의 위치가 변합니다. 사용자 입력이 없을 시 진행방향으로 이동하며 사용자의 입력이 진행방향과 같으면 그 진행방향 그대로 유지합니다. 반면 진행방향과 반대방향이면 게임오버입니다.

3단계 : Item 요소의 구현 (V)
-> Map에서 Fruit Item과 Poison Item은 각각 5, 6으로 구분하여 생성합니다. 5는 Snake의 크기가 늘어나는 아이템으로 G로 출력됩니다. 6은 Snake의 크기가 줄어드는 아이템으로 P로 출력됩니다. 모든 아이템을 관리하는 것은 ItemManager 클래스입니다. 이 클래스는 아이템을 일정 시간이 지나면 생성해줍니다. 또, 아이템이 생성된 뒤, 모든 아이템을 isExceedTime 함수로 일정 시간이 지났는지 검사합니다. 참값을 반환한다면 일정 시간이 지난 것이고 그 아이템은 vector로 생성된 data 에서 사라집니다.

4단계 : Gate 요소의 구현 (V)
-> Map에서 Gate는 7로 구분합니다. Gate는 실행 시, ?로 표시합니다. Gate 한 쌍이 겹치지 않고 벽에만 생성 될 수 있게 합니다. Gate 생성 후 10초가 지나면 사라지게 하였지만 Snake가 Gate를 통과 중일 땐 Gate가 사라지지 않고 다른 위치에서 Gate가 생성되지 않게 합니다. 다음 게이트의 위치에 따라서 Snake가 나오는 위치가 달라지니 게이트가 위치한 곳을 MapManager에서 data 배열을 가져와 동서남북 검사하여 어느 쪽으로 나갈지 구분합니다. 동서남북 검사한다는 말의 의미는 snake가 나갈 수 있는 쪽을 탐색한다는 것입니다. 예를 들어 게이트의 동쪽 좌표에 '0' 이 있다면 Snake가 나갈 수 있습니다. 따라서 possibleRight=true; 로 만들어주어 if 문으로 다음 게이트 좌표에서 나갈 수 있는 좌표를 반환합니다. Gate가 나타나는 벽이 Map의 가장자리일 때와 Map의 가운데에 있을 경우를 구분하고 벽이 Map 가장자리에 있을 경우 항상 Map의 안쪽 방향으로 진출하도록 하고 벽이 Map 가운데 있을 경우 진출하는 방향의 순서를 진입방향과 일치, 진입방향의 시계방향, 진입방향의 역시계방향, 진입방향의 반대방향으로 정합니다. 생성 조건은 Snake의 크기가 4이상일 때입니다.


5단계 : 점수 요소의 구현 (V)
-> GameScene 우측 상단에 ScoreBoard 및 Mission 화면을 구현합니다. ScoreBoard에는 Snake의 size와 Fruit item, Poison Item을 먹은 갯수, Gate를 통과한 횟수를 나타내도록 하고 Mission은 Stage마다 다른 조건이 존재합니다.

6단계 : 메인 화면 구현 및 스테이지 번호 구성 (V)
프로그램 실행 시, WaitingScene이 nowScene으로 설정됩니다. WaitingScene에는 Snake game 대기 화면이 출력되며 입력한 스테이지 번호에 해당하는 스테이지로 실행될 수 있도록 Stage 클래스의 nowStage를 설정합니다

<     기         여         도     >

------------------------------------
src
------------------------------------
<Snake>
Snake.h 기여자 : 박건후(90%), 민대인(10%)
Snake.cpp : 박건후(90%), 민대인(10%)
word 파일 내 기여도 사진 수정해야돼. master로 머지되면서 결과값이 좀 달라졌어. 이건 시간 남으면 하시고.

<Player>
Player.h : 박건후(90%), 민대인(10%)

<Manager>
Item.cpp : 박건후(80%), 민대인(20%)
Item.h : 박건후(80%), 민대인(20%)
ItemManager.h : 박건후(80%), 민대인(20%)
ItemManager.cpp : 박건후(80%), 민대인(20%)
GateManager.h : 박건후(100%), 민대인(0%)
GateManager.cpp : 박건후(100%), 민대인(0%)
MapManager.h : 박건후(100%), 민대인(0%)
MapManager.cpp : 박건후(100%), 민대인(0%)

<Stage>
Stage.h : 박건후(80%), 민대인(20%)
Stage.cpp : 박건후(80%), 민대인(20%)

<Format>
Format.h : 박건후(0%), 민대인(100%)
Format.cpp : 박건후(0%), 민대인(100%)

<Scene>
IScene.h : 박건후(90%), 민대인(10%)
WaitingScene.h : 박건후(10%), 민대인(90%)
WaitingScene.cpp : 박건후(10%), 민대인(90%)
GameScene.h : 박건후(10%), 민대인(90%)
GameScene.cpp : 박건후(10%), 민대인(90%)
GameCoverScene.h : 박건후(100%), 민대인(0%)
GameCoverScene.cpp : 박건후(100%), 민대인(0%)
GameOverScene.h : 박건후(10%), 민대인(90%)
GameOverScene.cpp : 박건후(10%), 민대인(90%)

<CharPosition>
CharPosition.h : 박건후(100%), 민대인(0%)

<main>
main.cpp : 박건후(100%), 민대인(0%)
------------------------------------
map
------------------------------------
map1.txt : 박건후(100%), 민대인(0%)
map2.txt : 박건후(100%), 민대인(0%)
map3.txt : 박건후(100%), 민대인(0%)
------------------------------------
scene
------------------------------------
GameOverScene.txt : 박건후(0%), 민대인(100%)
WaitingScene.txt : 박건후(0%), 민대인(100%)
------------------------------------
Makefile
------------------------------------
Makefile : 박건후(100%), 민대인(0%)
------------------------------------
