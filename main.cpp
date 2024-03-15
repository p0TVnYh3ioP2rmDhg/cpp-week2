// main 함수
#include <iostream>



// ProtoTypes
void generateAnswer(int* a);
int enterGuess();
void gameLoop();
int strike(int* a, int g);
int ball(int* a, int g);
void showResult(int* a, int g);
void congratulation();



int main() {
    gameLoop();                             // 만일 gameLoop 탈출 시 (즉, 게임에서 이겼다면?)
    return 0;                               // 게임 종료...
}