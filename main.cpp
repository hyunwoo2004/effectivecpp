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

class BuyTransaction : public Transaction {      // Transaction의 파생 클래스
public:
 virtual void logTransaction() const;            // 이 타입에 따른 거래내역
                                                 // 로깅을 구현함
 ...
};

class SellTransaction : public Transaction {     // 역시 파생 클래스
public:
 virtual void logTransaction() const;            // 이 타입에 따른 거래내역
                                                 // 로깅을 구현함
 ...
};
// 이제 아래의 코드가 실행될 때 어떻게 되는지 생각해보자.
int main() 
{
 BuyTransaction b;
}
// BuyTransaction 생성자가 호출되는 것은 맞음. 그러나 우선은 Transaction 생성자가 호출되어야 함
// 파생 클래스 객체가 생성될 때 그 객체의 기본 클래스 부분이 파생 클래스 부분보다 먼저 호출되는 것이 정석
// Transaction 생성자의 마지막 줄을 보면 가상 함수인 logTransaction을 호출하는 문장이 보이는데 무척 당혹스러운 사건이 벌어지는 부분이 바로 이 문장임
// 여기서 logTransaction 함수는 BuyTransaction의 것이 아니라 Transaction의 것이란 사실! (지금 생성되는 객체의 타입이 BuyTransaction 인데도)



