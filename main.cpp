#include<iostream>

// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 3: 낌새만 보이면 const를 들이대 보자!

// 포인터가 가리키는 대상을 상수로 만들 때 const를 사용하는 스타일은 조금씩 다름
// 예시
class Widget{};

void f1(const Widget *pw);  // f1은 상수 Widget에 대한
                            // 포인터를 매개변수로 취함
void f2(Widget const *pw);  // f2도 마찬가지
// 현역 프로그래머들은 두 형태를 잘 쓰므로 알아두기!


int main() {}
