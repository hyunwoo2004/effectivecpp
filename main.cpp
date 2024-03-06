#include<iostream>

// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 2: #define을 쓰려거든 const, enum, inline을 떠올리자
// -> 다른 말로, '가급적 선행 처리자보다 컴파일러를 더 가까이 하자'이다.

// #define 에서 상수로 교체할 때 주의할 점
// 2. 클래스 멤버로 상수를 정의하는 경우 (클래스 상수를 정의하는 경우) --> 그렇다고 클래스 상수를 #define을 만든다는 생각은 버리
// 어떤 상수의 유효 범위를 클래스로 한정하고자 할 때는 그 상수를 멤버로 만들어야 하는데, 
// 그 상수의 사본 개수가 한 개를 넘지 못하게 하고 싶다면 정적(static) 멤버로 만들어야 함
// 예시
class GamePlayer {
private:
  static const int NumTurns = 5;   // 상수 선언
  int scores[NumTurns];            // 상수를 사용하는 부분
};
const int GamePlayer::NumTurns; // 상수 정의

// 조금 오래된 컴파일러는 위의 문법이 받아들이지 않는 경우가 존재(선언된 시점에 값을 주는 것이 대개 맞지 않는다고 판단할 수 있음)
// 이 때는 이렇게 해야 함 (특히 정수류가 아닌 자료형의 경우도 포함)
class GamePlayer {
private:
  static const double HP;   // 상수 선언
 // ...
};
const double
  GamePlayer::HP = 5.0; // 상수 정의

int main() {
  
}
