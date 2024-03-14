#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 10: 대입 연산자는 *this의 참조자를 반환하게 하자

// "좌변 객체의 참조자를 반환하게 만들자"라는 규약은 위에서 본 단순 대입형 연산자 말고도
// 모든 형태의 대입 연산자에서 지켜져야 함
class Widget {
public:
  ...
  Widget& operator*=(const Widget& rhs)   // +=, -= *= 등에도 동일한
  {                                       // 규악이 적용함
    ... 
    return *this;                         // 좌변 객체(의 참조자)를 반환함
  }
  Widget& operator=(int rhs)             // 대입 연산자의 매개변수 타입이
  {                                      // 일반적이지 않은 경우에도
    ...                                  // 동일한 규약을 적용함
    return *this; 
  }
};

int main() 
{
}
