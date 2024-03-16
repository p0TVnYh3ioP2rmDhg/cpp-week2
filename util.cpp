/*
	나머지 로직들
	ex) 입출력 및 랜덤 생성 등...
*/

#include <iostream>
#include <stdlib.h>												// 랜덤한 수를 선언하기 위한 헤더 파일
#include <time.h>												// 랜덤한 수를 선언하기 위한 헤더 파일



// Prototypes
void generateAnswer(int* a);
int testDuplication(int* a, int i, int n);
int enterGuess();
int gameLoop();
int strike(int* a, int g);
int ball(int* a, int g);
void showResult(int* a, int g);
void congratulation();
void youLose();
void printChance(int c);



// 정답(answer)을 랜덤으로 입력받는 함수
void generateAnswer(int* a) {									// 정답 세 자리 숫자는 100의 자리에 0이 올 수도 있으므로 '배열' 포인터로 받음
	srand(time(NULL));											// 랜덤 수를 생성하기 위한 난수 초기화

	for (int i = 0; i < 3; i++) {
		// 0 ~ 9 까지의 난수를 a[i]에 대입		
		a[i] = rand() % 10;										// 배열의 각 칸에 난수를 대입하여 3칸 배열을 초기화

        // 중복 검사 시 중복임이 확인되면? (즉, if(1)이 성립되면?)
        if (testDuplication(a, i, a[i])) {                      // 중복 검사
            i--;                                                
            continue;                                           // 다시 순서를 직전으로 돌려서 다시 한 번 더 반복문 수행
        }
	}
}



// 숫자의 중복을 검사하는 함수
// a: 배열 포인터, i: 현재 자릿수(배열의 번호), n:생성된 랜덤 숫자
int testDuplication(int* a, int i, int n) {
    for (int x = 0; x < i; x++) {
        if (a[x] == n) {                                        // 만약 중복이 하나라도 있다면?
            return 1;                                           // 중복되는 값이 있으면 1을 리턴
        }
    }
    return 0;                                                   // 중복되는 값이 없으면 0을 리턴
}



// 맞추는 수(guess)를 입력받는 함수
int enterGuess() {
	int guess;

	std::cout << "Enter a guess: ";
	std::cin >> guess;

	return guess;
}



// 현황을 출력하는 함수 (strike, ball 의 개수)
void showResult(int* a, int g) {
	std::cout << "Strikes: " << strike(a, g);                  // 결과값 표시
	std::cout << ", Balls: " << ball(a, g) << std::endl;       // 만약 정답을 맞추었다면 축하 메시지(congratulation 함수)가 뜨며 결과값 메시지는 뜨지 않는다!
}



// 게임 승리 시 승리 메시지를 출력하는 함수
void congratulation() {
	std::cout << "You Win!" << std::endl;
}



// 게임 패배 시 패배 메시지를 출력하는 함수
void youLose() {
    std::cout << "You lose!" << std::endl;
}



// 찬스 개수를 출력하는 함수
void printChance(int c) {
    std::cout << c << " chances left." << std::endl;
}