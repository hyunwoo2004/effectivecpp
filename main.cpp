#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 13: 자원 관리에는 객체가 그만!

// createInvestment 함수로 얻어낸 자원이 항상 해제되도록 만들 방법은, 자원을 객체에 넣고 그 자원 해제를 소멸자가 맡도록 하며,
// 그 소멸자는 실행 제어가 f를 떠날 때 호출되도록 만드는 것임
// 사실 이 부분은 이번 항목에서 소개할 아이디어에 전반부이니 새겨 들자!
// 자원을 객체에 넣음으로써, C++가 자동으로 호출해 주는 소멸자에 의해 해당 자원을 저절로 해제할 수 있음!

// 소프트웨어 개발에 쓰이는 상당수의 자원이 Freestore(Heap)에서 동적으로 할당되고, 하나의 블록(block) 혹은 함수 안에서만 쓰이는 경우가 잦기 때문에
// 그 블록 혹은 함수로부터 실행 제어가 빠져나올 때 자원이 해제되는 게 맞음
// 표준 라이브러리를 보면 auto_ptr아린 것이 있는데, 바로 이런 용도에 쓰라고 마련된 클래스임
// auto_ptr은 포인터와 비슷하게 동작하는 객체[스마트 포인터(smart pointer)]로서, 가리키고 있는 대상에 대해 소멸자가 자동으로 delete를 불러주도록 설계되어 있음
// 그럼, f에서 생길 수 있는 자원 누출을 막기 위해 auto_ptr을 사용하는 방법을 보자
// 예시
void f()
{
  std::auto_ptr<Investment> pInv(createInvestment());  // 팩토리 함수를
                                                       // 호출함
  
  ...                                                  // 예전처럼
                                                       // pInv를 사용함

}                                                      // auto_ptr의
                                                       // 소멸자를 통해
                                                       // pInv를 삭제함
// 아주 간단한 예제이지만, 자원 관리에 객체를 사용하는 방법의 중요한 두 가지 특징을 여기서 끄집어낼 수 있음
// 1. 자원을 획득한 후에 자원 관리 객체에게 넘김
// 위의 예제를 보면, createInvestment 함수가 만들어준 자원은 그 자원을 관리할 auto_ptr 객체를 초기화하는 데 쓰이고 있음
// 실제로, 이렇게 자원 관리에 객체를 사용하는 아이디어에 대한 업계 용어도 자주 통용되고 있는데, 자원 획득 즉 초기화(Resource Acquisition Is Intialization: RAII)임
// 이런 이름이 나온 이유는 자원 획득과 자원 관리 객체의 초기화가 바로 한 문장에서 이루어지는 것이 너무나도 일상적이기 때문임
// 획득된 자원으로 자원 관리 객체를 초기화하지 않고 그 자원을 그 객체에 대입하는 경우도 종종 있긴 하지만, 
// 어찌 됐든 "자원을 획득하고 나서 바로 자원 관리 객체에 넘겨 준다"는 점 같음

int main() 
{

}


