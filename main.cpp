#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 11: operator=에서는 자기대입에 대한 처리가 빠지지 않도록 하자

// 여기서 찾을 수 있는 자기 참조 문제는 operator= 내부에서 *this와 rhs가 같은 객체일 가능성이 있음
// 이 둘이 같은 객체이면, delete 연산자가 *this 객체의 비트맵에만 적용되는 것이 아니라 rhs의 객체까지 적용됨
//   이 함수가 끝나는 시점이 되면 해당 Widget 객체는 자신의 포인터 멤버를 통애 물고 있던 객체가 어처구니없게도
// 삭제된 상태가 되는 불상사를 당하게 됨

// 이런 에러에 대한 대책은 예전부터 있어 왔음. 전통적인 방법은 operator=의 첫머리에서 일치성 검사(identity test)를 통해
// 자기대입을 점검하는 것
Widget& operator=(const WIdget& rhs)
{
  if(*this == &rhs) return *this;      // 객체가 같은지, 즉 자기대입인지 검사함
                                       // 자기대입이면 아무것도 안함
  delete pb;
  pb = new Bitmap(rhs.pb);

  return *this;
}

int main() 
{

}


