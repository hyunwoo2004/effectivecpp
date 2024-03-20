#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 15: 자원 관리 클래스에서 관리되는 자원은 외부에서 접근할 수 있도록 하자

// RAII 클래스의 객체를 그 객체가 감싸고 있는 실제 자원(예시: Investment*)으로 변환한 방법이 필요함
// 이런 목적에 일반적인 방법을 쓴다면 두가지가 있음
// 1. 명시적 변환(explicit conversion)
// 2. 암시적 변환(implicit conversion)

// tr1::shared_ptr 및 auto_ptr은 명시적 변환을 수행하는 get이라는 멤버 함수를 제공함
// 다시 말해 이 함수를 사용하면 각 타입으로 만든 스마트 포인터 객체에 들어 있은 실제 포인터(의 사본)을 얻어낼 수 있음

int days = datsHeld(pInv.get());                          // 이제 문제없음. pInv에 들어 있는
                                                          // 실제 포인터를 daysHeld에 넘기기 때문

// 제대로 만들어진 스마트 포인터 클래스라면 거의 모두가 그렇듯, tr1::shared_ptr과 auto_ptr은 
// 포인터 역참조 연산자(operator-> 및 operator*)도 오버로딩하고 있음
// 따라서 자신이 관리하는 실제 포인터에 대한 암시적 변환도 쉽게 할 수 있음

class Investment {                                        // 여러 형태의 투자를 모델링한
public:                                                   // 투자 클래스들의 최상위 클래스
  bool isTaxFree() const;
  ...
};

Investment* createInvestment();                           // 팩토리 함수

std::tr1::shared_ptr<Investment>                          // tr1::shared_ptr이 자원
  pi1(createInvestment());                                // 관리를 맡도록 함

bool taxable1 = !(pi1->isTaxFree());                      // operator->를 써서
                                                          // 자원에 접근함

...
std::auto_ptr<Investment> pi2(createInvestment());        // auto_ptr로 하여금
                                                          // 자원 관리를 맡도록 함

bool taxable2 = !((*pi2).isTaxFree());                    // operator*를 써서
                                                          // 자원에 접근함
...
// RAII 객체 안에 들어 있는 실제 자원을 얻어낼 필요가 종종 생기기 때문에, RAII 클래스 설계자 중에는
// 암시적 변환 함수를 제공하여 자원 접근을 매끄럽게 할 수 있도록 만드는 사람도 있음


int main() 
{

}



