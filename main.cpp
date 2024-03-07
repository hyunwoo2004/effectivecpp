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
  const char* const p4 = greeting;  
  // const가 *의 왼쪽에 있으면 포인터가 가리키는 대상이 상수인 반면
  // const가 *의 오른쪽에 있으면 포인터 자체가 상수임
}
