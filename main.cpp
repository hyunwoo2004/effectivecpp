#include<iostream>
#include <vector>
// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 4: 객체를 사용하기 전에 반드시 그 객체를 초기화하자

// 가장 좋은 방법: 모든 객체를 사용하기 전에 항상 초기화(initialization)하는 것
// 기본제공 타입으로 만들어진 비멤버 객체에 대해서는 초기화를 손수해야 함
// 예시
int main() {
  int x = 0;                                  // int의 직접 초기화
  const char* text = "A C-style string";      // 포인터의 직접 초기화
                                              // (항목 3도 참조)

  double d;                                   // 입력 스트림에서 읽음으로써
  std::cin >> d;                              // "초기화"수행
} 
// 이런 부분을 제외하면, C++ 초기화의 나머지 부분은 생성자로 귀결됨
// 생성자에서 지킬 규칙 - 그 객체의 모든 것을 초기화하자!
