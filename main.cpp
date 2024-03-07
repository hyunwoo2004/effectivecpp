#include<iostream>

// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 3: 낌새만 보이면 const를 들이대 보자!

// const키워드는 생긴 것 답지 않게 그야말로 팔방미인!
// 그렇다면 포인터는?
// 기본적으로는 포인터 자체를 상수로, 혹은 포인터가 가리키는 데이터를 상수로 지정할 수 있음
// 둘다 지정할 수 있고, 아무것도 지정하지 않을 수도 있음

int main() {
  char greetinr[] = "Hello";

  char* p1 = greeting;              // 비상수 포인터
                                    // 비상수 데이터
  const char* p2 = greeting;        // 비상수 포인터
                                    // 상수 데이터
  char* const p3 = greeting;        // 상수 포인터
                                    // 비상수 데이터
  const char* const p4 = greeting;  // 상수 포인터
                                    // 상수 데이터
}
