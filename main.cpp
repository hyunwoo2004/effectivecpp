#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 8: 예외가 소멸자를 떠나지 못하도록 붙들어 놓자

// 위에 두 방법은 어느 쪽을 선택하든 특별히 좋을 건 없음 (둘 다 문제점이 있음)
// 중요한 것은 close가 최초로 예외를 던지게 된 요인에 대해 프로그램이 어떤 조치를 취할 수 있는가인데
// 이런 부분에 대한 대책이 전무함

int main() 
{
  
}

