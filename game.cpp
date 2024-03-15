/*
    게임의 로직을 맡는 함수들의 정의
    ex) 게임의 흐름, 스트라이크 / 볼 처리 등...
*/
#include <iostream>



// Prototypes
int enterAnswer();
int enterGuess();
void gameLoop();
int strike(int a, int g);
int ball(int a, int g);
void showResult(int a, int g);
void congratulation();



// Strike를 기록하는 함수
int strike(int a, int g) {                          // a : answer(정답), g : guess(추측하는 값)
    int a_num[3], g_num[3];                         // answer, guess의 세 자리 숫자를 분해하여 각각의 자릿수에 해당하는 값을 따로 보관
    int count = 0;                                  // strike 개수를 의미하는 변수

    a_num[0] = a / 100;                             // 배열의 0 번째에는 백의 자릿수를 담는다
    g_num[0] = g / 100;

    a_num[1] = ((a % 100) - (a % 10)) / 10;         // 배열의 1 번째에는 십의 자릿수를 담는다
    g_num[1] = ((g % 100) - (g % 10)) / 10;

    a_num[2] = a % 10;                              // 배열의 2 번째에는 일의 자릿수를 담는다
    g_num[2] = g % 10;

    for (int i = 0; i < 3; i++) {
        // 만일 각각 자릿수 위치의 숫자(값)가 서로 같다면?
        if (a_num[i] == g_num[i]) {
            // strike!
            count++;
        }
    }

    return count;                                   // strike의 개수를 반환한다
}



// Ball을 기록하는 함수
int ball(int a, int g) {
    int a_num[3], g_num[3];
    int count = 0;

    a_num[0] = a / 100;
    g_num[0] = g / 100;

    a_num[1] = ((a % 100) - (a % 10)) / 10;
    g_num[1] = ((g % 100) - (g % 10)) / 10;

    a_num[2] = a % 10;
    g_num[2] = g % 10;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {               // answer의 각 자릿수 하나마다 guess의 세 자릿수를 하나씩 비교
            // 만일 같은 숫자가 존재한다면?
            if (a_num[i] == g_num[j]) {
                // 그러나 자릿수까지 같으면 ball이 아니라 strike 이므로 제외
                if (i != j) {
                    // ball!
                    count++;
                }
            }
        }
    }

    return count;                                   // ball의 개수를 반환한다
}



// 게임의 흐름을 맡는 함수
void gameLoop() {
    int answer, guess;
    answer = enterAnswer();                         // 정답(answer)을 입력받는 함수

    while (true) {
        guess = enterGuess();                       // 추측값(guess)을 입력받는 함수

        if (strike(answer, guess) == 3) {           // strike가 3개라면? (즉, 정답을 맞추었다면?)
            congratulation();                       // ㅊㅊ
            break;                                  // 이후 반복문 및 함수 탈출 후 게임 종료(return 0;)
        }

        showResult(answer, guess);                  // 정답을 맞히지 않은 경우, 진행상황을 알려준다
    }
}