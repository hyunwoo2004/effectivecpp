#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 9: 객체 생성 및 소멸 과정 중에는 절대로 가상 함수를 호출하지 말자

// 객체 생성 및 소멸 과정 중에는 가상 함수를 호출하면 안 됨!
// 예시: 주식 거래를 본떠 만든 클래스 계톧 구조
class Transaction {
public:                                          // 모든 거래에 대한
 Transactoin();                                  // 기본 클래스

 virtual void logTransaction() const = 0;        // 타입에 따라 달라지는
                                                 // 로그 기록을 만듦
 ...
};

Transiaction::Transaction()                      // 기본 클래스 생성자의
{                                                // 구현
 ...
 logTransaction();                               // 마지막 동작으로, 이 거래를
}                                                // 로깅(하기 시작)함.


int main() 
{
  
}

