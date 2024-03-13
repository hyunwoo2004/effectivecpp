#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 9: 객체 생성 및 소멸 과정 중에는 절대로 가상 함수를 호출하지 말자

// 생성자 혹은 소멸자 안에서 가상 함수가 호출되는지를 잡아내는 일이 항상 쉬운 것은 아님
// Transaction의 생성자를 여러 개 된다고 가정해 보자
// -> 각 생성자에서 하는 일이 조금씩은 다르겠지만 몇가지 작업은 똑같을 텐데, 똑같은 작업을 모아 
//    공동의 초기화 코드로 만들어주면 코드 판박이 현상을 막을 수 있는가?
// 대개 이런 설계의 열매로 private멤버인 비가상 초기화 함수가 만들어지는데, 이 함수 안에서 logTransaction을 호출한다고 가정
class Transaction {
public:
 Transaction()
 { init(); }                   // 비가상 함수를 호출하고 있...
 virtual void logTransaction() const = 0;
 ...
private:
 void init()
 {
  ...
  logTransaction();            // ...는데 이 비가상 함수에서 가상 함수를 호출하고 있음!
 }
};


int main() 
{
}
