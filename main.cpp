#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 7: 다형성을 가진 기본 클래스에서는 소멸자를 반드시 가상 소멸자로 선언하자

// 그 코드는 근본적인 약점(문제점)이 존재함
// 1. getTimeKeeper 함수가 반환하는 포인터가 파생 클래스 객체에 대한 포인터임
// 2. 이 포인터가 가리키는 객체가 사라질 때는 기본 클래스 포인터를 통해 삭제됨
// 3. 기본 클래스에 들어 있는 소멸자가 비가상 소멸자(non-virtual dtor)임

// 해결법
// 지극히 간단함. 기본 클래스에 가상 소멸자를 만들자
// 그러면 파생 클래스 객체를 기본 클래스 포인터로 삭제할 때 우리가 원하는 쪽으로 동작이 됨
class TimeKeeper {
public:
  TimeKeeper();
  virtual ~TimeKeeper();
  ...
};
int main() {
  TimeKeeper* ptk = getTimeKeeper();

  ...
  delete ptk;                          // 이제는 제대로 동작함
} 

