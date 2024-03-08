#include<iostream>
#include <vector>
// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 3: 낌새만 보이면 const를 들이대 보자!

// 어떤 멤버 함수가 상수 멤버(const)라는 것이 어떤 의미인가?
// -> 두가지 의미가 있다.
// 1. 비트수준 상수성(bitness constness, 다른 말로 물리적 상수성(physical constness))
// 2. 논리적 상수성(logical constness)

// 비트수준 상수성
// 근데, '제대로 const'로 동작하지 않는데도 이 비트수준 상수성 검사를 통과하는 멤버 함수들도 있음
// 예시: 어떤 포인터가 가리키는 대상을 수정하는 멤버 함수들 중 상당수가 이에 해당됨!!!
// 하지만 이 포인터가 객체의 멤버에 있는 한, 이 함수는 비트 수준 상수성을 갖는 것으로 판별되고 컴파일러도 뭐라고 불평하지 않음
// 근데 이 때문에 상식적으로 이해할 수 없는 동작이 발생할 수 있음
// 예시
class TextBlock {
public:
  //...
  char& operator[] (std::size_t position) const {  // 부적절한 (그러나 비트수준
    return pText[position];                        // 상수성이 있어서 허용되는)
  }                                                // operator[]의 선언
private:
  char* pText;
};
// operator[] 함수가 상수 멤버 함수로 선언되어 있는데 char&를 반환함?!
// 이러면 다음에 이런 문제가 발생함
int main() {
  const CTextBlock cctb("Hello");   // 상수 객체 선언
  
  char* pc = &cctb[0];              // 상수 버전의 operator[]를 호출하여 cctb의
                                    // 내부 데이터에 대한 포인터를 얻음
  *pc = 'J';                        // 이젠 cctb는 "Jello"라는 값을 가지게 됨 -> ???
} 
// 분명 상수 객체를 하나 만들어 놓고 이것에다 상수 멤버 함수를 호출했더니 값이 바뀜 ?!
