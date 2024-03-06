#include<iostream>

// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 2: #define을 쓰려거든 const, enum, inline을 떠올리자
// -> 다른 말로, '가급적 선행 처리자보다 컴파일러를 더 가까이 하자'이다.

// #define 에서 상수로 교체할 때 주의할 점
// 1. 상수 포인터를 정의하는 경우
//  상수 정의는 대부분 헤더파일에 넣는 것이 관례이므로 포인터는 꼭 const로 선언, 또한 포인터가 가리키는 대상까지 const로 선언하는 게 보통
// 예시
const char * const authorName = "Scott Meyers";
const std::string authorName("Scott Meyers");   // 보완(char* 보다 std::string이 더 좋음)

int main() {
  
}
