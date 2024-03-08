#include<iostream>
#include <vector>
// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 3: 낌새만 보이면 const를 들이대 보자!

// 상수 멤버 및 비상수 멤버 함수에서 코드 중복 현상을 피하는 방법
// mutable은 비트수준 상수성의 단점을 해결하는 단어임은 틀림없음
// 그러나 이것만으로 const에 관련된 골칫거리 전부를 해결하는 것은 아님...
// 예시
class TextBlock {
public:
  //...
  const char& operator[](std::size_t position) const 
  {
    //...                                                  // 경계 검사
    //...                                                  // 접근 데이터 로깅
    //...                                                  // 자료 무결성 검증
    return text[position];
  }

  char& operator[](std::size_t position)
  {
    //...                                                  // 경계 검사
    //...                                                  // 접근 데이터 로깅
    //...                                                  // 자료 무결성 검증
    return text[position];
  }
private:
  std::string text;
};
// operator[]의 상수와 비상수 버전에 넣어 버려면 어느새 코드 판박이 괴물이 우리 앞에 나타남
// 코드 중복은 따라오는 골칫거리 친구들(컴파일 시간, 유지 보수, 코드 크기 부풀림) 감당X
// 경계 검사 등을 멤버 변수에 옮긴다고 해도 return문 까지도 같음...


int main() {

} 

