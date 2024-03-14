#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 11: operator=에서는 자기대입에 대한 처리가 빠지지 않도록 하자

// 자기대입(self assignment)이란, 자기 객체가 자기 자신에 대해 대입 연산자를 적용하는 것을 말함
// 예시
class Widget { ... };

int main() 
{
  Widget w;

  ...

  w = w;              // 자기에 대한 타입
}
