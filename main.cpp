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
// 이 코드는 앞 코드와 비교하면 개념적으로는 똑같은 코드이지만, 사악한 걸로 따지면 이 코드임
// 이유는 앞의 코드와 달리 컴파일도 되고 링크도 말끔하게 되기 때문임.
// 이 코드가 실행된다고 생각해 보자
// logTransaction은 Transaction 클래스 안에서 순수 가상 함수이기 때문에, 대부분의 시스템은 
// 순수 가상 함수가 호출될 때 프로그램을 바로 끝내(abort) 버림(대개 갑작스런 종료라는 메시지도 출력) - 이런 경우는 그나마 좋은 거임
// 만약 logTransaction 함수가 '보통'가상 함수(순수가 아닌)이며, Transaction의 멤버 버전이 구현되어 있을 경우엔 머리가 터지기 시작하게 됨
// 앞에서 말한 것처럼 Transaction의 버전이 호출될 것이고 우리는 왜 BuyTransaction 객체를 생성하는데 Transaction 버전이 나온 이유를 알지 못하게 됨

int main() 
{
}
