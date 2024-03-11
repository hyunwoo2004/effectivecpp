#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 7: 다형성을 가진 기본 클래스에서는 소멸자를 반드시 가상 소멸자로 선언하자

// 가상 함수 호출이 어떻게 구현되는지는 구체적으로 알 필요는 없음
// 중요한 것은 Point 클래스에 가상 함수가 들어가게 되면, Point 타입 객체의 크기가 증가함
// 프로그램 실행환경에 따라 크기가 달라짐
//  32비트 아키텍처 - 64비트 -> 96비트 
//  64비트 아키텍처 - 64비트 -> 128비트
// 포인터 하나 추가됐을 뿐인데 자료의 크기가 50% / 100% 증가됨을 알 수 있음
// 게다가 다른 언어(C 등)와의 호환성이 사라짐
// int 2개로 어떻게든 만들어도 vptr를 만드는 것은 거의 불가능함(다른 언어)
// 그러면 이식성에 대한 기대는 1도 할 수 없음

int main() {

} 









