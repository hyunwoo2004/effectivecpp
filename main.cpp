#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 10: 대입 연산자는 *this의 참조자를 반환하게 하자

// 이렇게 대입 연산이 사슬처럼였이려면 대입 연산자가 좌변 인자에 대한 참조자를 반환하도록 구현되어 있을 것임
// 이런 구현은 일종의 관레(convention)인데, 우리가 나름대로 만드는 클래스에 대입 연산자가 혹시 들어간다면
// 이 관례를 지키는 것이 좋음
class Widget {
public:
  ...
  Widget& operator=(const Widget& rhs)   // 반환 타입은 현재의 클래스에 대한
  {                                      // 참조자임
    ... 
    return *this;                        // 좌변 객체(의 참조자)를 반환함
  }
};

int main() 
{
}
