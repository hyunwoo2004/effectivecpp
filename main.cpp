#include<iostream>
#include <vector>
// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 3: 낌새만 보이면 const를 들이대 보자!

// operator[]를 '오버로드(overload)'해서 각 버전마다 반환 타입을 다르게 가져갔기 때문에, TextBlock의 상수 객체와 비상수 객체의 쓰임새가 달라짐

int main() {
  TextBlock tb{"Hello"};    
  const TextBlock ctb{"World"};

  std::cout << tb[0];     // OK, 비상수 버전의 TextBlock 객체를 읽음
  
  tb[0] = 'x';            // OK, 비상수 버전의 TextBlock 객체를 씀
  
  std::cout << ctb[0];    // OK, 상수 버전의 TextBlock 객체를 씀

  ctb[0] = 'x';           // 컴파일 에러!, 상수 버전의 TextBlock 객체에 대해 쓰기는 안됨
}
// +a
// operator[]의 비상수 멤버는 char의 참조자(reference)를 반환하는 데, char 하나만 쓰면 안된다는 점도 알아두기
// 만약 char&가 아닌 char라면 두번쨰가 컴파일 되지 않음.
// -> tb[0]이 값의 의한 반환이 되기 떄문에 tb[0]의 사본에 대입하는 것이므로 의도하지 않은 행동이 됨
