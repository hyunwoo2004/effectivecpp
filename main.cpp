#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 10: 대입 연산자는 *this의 참조자를 반환하게 하자

// C++의 대입 연산은 여러 개가 사슬처럼 엮일 수 있는 재미있는 성질을 갖고 있음
int x, y, z;
x = y = z = 15;           // 대입이 사술처럼 이어짐
// 대입 연산이 가진 또 하나의 재미있는 특성은 바로 우측 연관(right-associative) 연산이라는 점
// 즉 위의 대입 연산 사슬은 다음과 같이 분석됨
x = (y = (z = 15));

int main() 
{
}
