#include<iostream>

// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 2: #define을 쓰려거든 const, enum, inline을 떠올리자
// -> 다른 말로, '가급적 선행 처리자보다 컴파일러를 더 가까이 하자'이다.

// "나열자 둔갑술"을 알아두어야 하는 이유
// 1. 동작 방식이 const보다 #define에 더 가까움 
// -> const는 주소를 취할 수 있지만 enum은 #define처럼 주소를 얻는 것이 불법임
// + 불필요한 메모리 할당이 일어나지 않음


int main() {}
