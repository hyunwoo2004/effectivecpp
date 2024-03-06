#include<iostream>

// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 2: #define을 쓰려거든 const, enum, inline을 떠올리자
// -> 다른 말로, '가급적 선행 처리자보다 컴파일러를 더 가까이 하자'이다.

// 예시: #define ASPECT_RATIO 1.623
// -> 우리에겐 ASPECT_RATIO가 보이지만 컴파일러는 보이지 않음! (전처리기에 의해 모두 1.623으로 볼 것이다)
// => 컴파일 오류가 발생 시 ASPECT_RATIO가 아니라 1.623으로 보이기에 찾기 어려움
// -> 이 문제는 기호식 디버거(symbolic debugger)에도 나타날 수 있으므로 안 쓰는 게 좋음

#define ASPECT_RATIO 1.623

int main() {
  
}
