#include<iostream>
#include <vector>
// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 3: 낌새만 보이면 const를 들이대 보자!

// 가장 강력한 const의 용도: 함수 선언에 사용하는 경우
// 함수 선언문에 const는 함수 반환 값, 각각의 매개변수, 멤버 함수 앞에 붙을 수 있고, 함수 전체에 대해 const의 성질을 붙일 수 있다.
// 1. 함수 반환 값
// 함수 반환 값을 상수롤 정해 주면, 안전성이나 효율을 포기하지 않고도 사용자측의 에러 돌발 상황을 줄여주는 효과를 꽤 자주 볼 수 있게 됨.
// 예시: 유리수 클래스
class Rational {/...};
const Rational operator* (const Rational& lhs, const Rational& rhs);
// *연산자의 반환 값이 상수 객체인 이유: 다음과 같은 이상한 실수를 없애는 데 도움
Rational a, b, c;

(a * b) = c; // a*b의 결과에 대고 =를 호출하면 안됨!

int main() {}
