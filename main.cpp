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
// 주의할 점
// 넷째 줄에서 발생한 에러는 순전히 operator[]의 반환 타입(return type)이 때문이라는 점!
// operator[] 호출이 잘못된 것은 없음. 이 에러는 const char* 타입에 대입 연산을 시도해서 생김
// operator[]의 반환 타입이 const char&이기 떄문에
