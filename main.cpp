#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 8: 예외가 소멸자를 떠나지 못하도록 붙들어 놓자

// 소멸자로부터 예외가 터져 나가는 경우를 C++ 언어에서 막는 것은 아니지만, 실제 상황을 보면
// 확실히 우리가 막아야 한다는 것을 알게 될 것임
// 예시
class Widget {
public:
  ...
  ~Widget() {...}      // 이 함수로부터 예외가 발생된다고 가정함
};

void doSomeThing() { 
  std::vector<Widget> v;
  ...
}  // v는 여기서는 자동으로 소멸됨

int main() {

}          
