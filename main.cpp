#include<iostream>

// C++ interface
// 언어의 차원에서 주어져 있지만, C++에는 없음
// 그러나 C++로도 인터페이스와 흡사하게 할 수 있음
// 보통 함수의 시그니처, 어떤 클래스의 접근가능 요소
// + 템플릿의 타입 매개변수로서 유효해야 하는 표현식 등

//함수의 시그니처
// 1. 함수의 이름 f
// 2. 매개변수의 개수 2
// 3. 매개변수의 자료형 (int, double)
void f(int n, double d) {}

class A {
public: //----]
protected://--|--> // 접근 가능 요소
private://----]
};

int main() {

}
