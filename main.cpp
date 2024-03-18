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

// auto_ptr을 사용한 버전과 거의 똑같아 보이는 코드이지만, shared_ptr의 복사가 훨씬 자연스러워졌음
// 예시
void f() 
{
  ...
  std::tr1::shared_ptr<Investment>         // pInv1이 가리키는 대상은
    pInv1(createInvestment());             // createInvestment 함수에서
                                           // 반환된 객체임

  std::tr1::shared_ptr<Investment>         // pInv1 및 pInv2가 동시에
    pInv2(pInv1);                          // 그 객체를 가리키고 있음
                                           
  pInv1 = pInv2;                           // 마찬가지 - 변한 것도 하나도
                                           // 없음

  ...                                      // pInv1 및 pInv2는 소멸되며,
}                                          // 이들이 가르키고 있는 객체도
                                           // 자동으로 삭제됨

int main() 
{

}



