#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 7: 다형성을 가진 기본 클래스에서는 소멸자를 반드시 가상 소멸자로 선언하자

// 정리: 추상 클래스가 될 클래스에 순수 가상 소멸자를 만들자!
class AWOV {             // AWOV = "Abatract w/o Virtuals"
public:
  virtual ~AMOV() = 0;   // 순수 가상 소멸자를 선언함
};
// AWOV 클래스는 순수 가상 함수를 갖고 있으므로, 우선 추상 클래스임.
// 동시에 이 순수 가상 함수가 가상 소멸자이므로, 앞에서 말한 소멸자 호출 문제로 고민할 필요X


int main() {

}          
