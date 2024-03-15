/*
	나머지 로직들
	ex) 입출력 및 랜덤 생성 등...
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



// 정답(answer)을 입력받는 함수
int enterAnswer() {
	int answer;

	std::cout << "Enter a answer: ";
	std::cin >> answer;

	return answer;
}



// 맞추는 수(guess)를 입력받는 함수
int enterGuess() {
	int guess;

	std::cout << "Enter a guess: ";
	std::cin >> guess;

	return guess;
}



// 현황을 출력하는 함수 (strike, ball 의 개수)
void showResult(int a, int g) {
	std::cout << "Strikes: " << strike(a, g);                  // 결과값 표시
	std::cout << ", Balls: " << ball(a, g) << std::endl;       // 만약 정답을 맞추었다면 축하 메시지(congratulation 함수)가 뜨며 결과값 메시지는 뜨지 않는다!
}



// 게임 승리 시 승리 메시지를 출력하는 함수
void congratulation() {
	std::cout << "You Win!" << std::endl;
}