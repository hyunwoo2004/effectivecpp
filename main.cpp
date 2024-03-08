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

  mutable std::size_t textlength;    // 이 데이터 멤버들은 어떤 순간에도
  mutable bool lengthIsValid;        // 수정이 가능함. 심지어 상수 멤버
};                                   // 함수 안에서도 수정 가능함

std::size_t CTextBlock::length() const 
{
  if (!lengthIsValid) {
    textLength = std::strlen(pText);  // 이제 문제없음
    lengthIsValid = true;             // 당연히 문제없음
  }                                   

  return textLength;
}
// 다음 문제를 해결할 방법: mutable 키워드
// mutable은 비정적 데이터 멤버를 비트수준 상수성의 족쇄에서 풀어 주는 아름다운 오색약수 같은 키워드


int main() {

} 

