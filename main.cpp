#include<iostream>

// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 2: #define을 쓰려거든 const, enum, inline을 떠올리자
// -> 다른 말로, '가급적 선행 처리자보다 컴파일러를 더 가까이 하자'이다.

// #define 지시자에 대한 또 다른 오용 사례: 매크로 함수
// 해결법: 인라인(inline) 함수
// 인라인 함수는 기존 매크로 함수의 효율(함수 오버 헤드 0)을 그대로 유지하고
// 정규 함수의 모든 동작 방식 및 타입 안전성까지 완벽히 취할 수 있는 방법이다.
// 예시
template<typename T>
inline void callwithMax(const T& a, const T& b)
{
  f(a > b ? a : b);
}
// 이 함수는 템플릿이기 때문에 게열 함수군(family of functions)을 만들어냄
// 이 함수는 매크로에 단점을 모두 없애고 정규함수의 장점을 가져온 함수


int main() {}
