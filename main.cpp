#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 12: 객체의 모든 부분을 빠짐없이 복사하자

// 대신에 이런 방법은 생각해 볼 수 있음
//   어쩌다 보니 복사 생성자와 복사 대입 연산자의 코드 본문이 비슷하게 나온다는 느낌이 들면, 
// 양쪽에서 겹치는 부분을 별도의 멤버 함수에 분리해 놓은 후에 이 함수를 호출하게 만드는 것임
// 대개 이런 용도의 함수는 private 멤버로 두는 경우가 많고, 이름이 init 어쩌고 하는 이름을 가짐

int main() 
{

}


