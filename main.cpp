#include<iostream>
#include <vector>
// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 3: 낌새만 보이면 const를 들이대 보자!

// 어떤 멤버 함수가 상수 멤버(const)라는 것이 어떤 의미인가?
// -> 두가지 의미가 있다.
// 1. 비트수준 상수성(bitness constness, 다른 말로 물리적 상수성(physical constness))
// 2. 논리적 상수성(logical constness)

// 논리적 상수성
// 비트수준 상수성으로도 막지 못한 상수성 위반을 막기 위해서는 논리적 상수성이 필요
// 상수 멤버 함수라고 해서 객체의 한 비트도 수정할 수 없는 것이 아니라 일부 몇 비트 정도는 바꿀 수 있되,
// 그것을 사용자측에서 알아차리지 못하게만 한다면 상수 멤버 자격이 있다는 개념
// 예시
class CTextBlock {
public:
  //...
  std::size_t length() const;
private:
  char* pText;
  std::size_t textlength;    // 바로 직전에 계산한 텍스트 길이
  bool lengthIsValid;        // 이 길이가 현재 유효한가?
};

std::size_t CTextBlock::length() const 
{
  if (!lengthIsValid) {
    textLength = std::strlen(pText);  // 에러! 상수 멤버 함수 안에서는
    lengthIsValid = true;             // textLength 및 lengthIsValid에
  }                                   // 대입할 수 없음!

  return textLength;
}
// length의 구현은 '비트수준 상수성'과 멀리 떨어져 있음!
// 멤버 변수가 변할 수 있기 때문임


int main() {

} 

