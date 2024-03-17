#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 13: 자원 관리에는 객체가 그만!

// TR1에서 제공되는 tr1::shared_ptr(항목 54참조)이 대표적인 RCSP임
// 이것을 써서 f 함수를 다시 작성하면 이렇다
void f() 
{
  ...
  std::tr1::shared_ptr<Investment>
    pInv1(createInvestment());             // 팩토리 함수 호출

  ...                                      // 예전처럼 pInv를 사용

}                                          // shared_ptr의 소멸자를 통해
                                           // pInv를 자동으로 삭제

int main() 
{

}



