#include<iostream>

// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 2: #define을 쓰려거든 const, enum, inline을 떠올리자
// -> 다른 말로, '가급적 선행 처리자보다 컴파일러를 더 가까이 하자'이다.

// 한가지 예외: 해당 클래스를 컴파일 하는 도중에 클래스 상수의 값이 필요할 때
// -> 예시: 배열 멤버를 선언할 때가 대표적임
// 이 때는 "나열자 둔갑술(enum hack)"이라는 통칭으로 멋스럽게 알려진 기법이 있음
// 이 기법의 원리: 나열자(enumerator)타입의 값은 int가 놓일 곳에도 쓸 수 있다는 C++의 진실을 적극 활용하는 것
class GamePlayer {
private:
  enum {NumTurns = 5}; // "나열자 둔갑술": NumTurns를
                       // 5에 대한 기호식 이름으로 만듦

  int scores[NumTurns];
  //...
};
