#include<iostream>
#include <vector>
// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 3: 낌새만 보이면 const를 들이대 보자!

// 중요!
// 앞에 문제에서 상수버전에서 비상수버전을 호출하는 방법은 결코 하선 안됨
// 상수 멤버 함수는 해당 객체의 논리적인 상태를 바꾸지 않겠다고 컴파일러가 굳게 약속하지만
// 비상수 멤버 함수는 이런 약속 따윈 하지 않음
// 즉, 상수 멤버에서 비상수 멤버를 호출하게 되면 수정하지 않겠다고 약속한 그 객체를 배신하는 셈이 됨
// 그래서 상수 멤버 함수에서 비상수 멤버 함수를 호출하면 에러가 발생하는 이유임.
// 우리가 앞에서 했던 비상수버전에 상수버전을 호출하는 방법이 코드 중복을 막는 유일한 방법(그렇다고 그 방법도 좋은 건 아님...)

int main() {

} 

