#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 13: 자원 관리에는 객체가 그만!

// auto_ptr을 사용한 버전과 거의 똑같아 보이는 코드이지만, shared_ptr의 복사가 훨씬 자연스러워졌음
// 예시
void f() 
{
  //...
  std::tr1::shared_ptr<Investment>         // pInv1이 가리키는 대상은
    pInv1(createInvestment());             // createInvestment 함수에서
                                           // 반환된 객체임

  std::tr1::shared_ptr<Investment>         // pInv1 및 pInv2가 동시에
    pInv2(pInv1);                          // 그 객체를 가리키고 있음
                                           
  pInv1 = pInv2;                           // 마찬가지 - 변한 것도 하나도
                                           // 없음

  //...                                    // pInv1 및 pInv2는 소멸되며,
}                                          // 이들이 가르키고 있는 객체도
                                           // 자동으로 삭제됨
// 복사 동작이 '예상대로' 이루어지기 때문에, tr1::shared_ptr은 괴상한 복사 동작으로
// 인해 auto_ptr을 쓸 수 없는 STL 컨테이너 등의 환경에 딱 맞게 쓸 수 있음

// auto_ptr 혹은 tr1::shared_ptr 등 스마트 포인터 이야기를 늘어놓으려고 이번 항목을 준비한 것은 아님
// 자원을 관리하는 객체를 써서 자원을 관리하는 것이 중요하다는 이야기가 진짜임
// auto_ptr과 tr1::shared_ptr(항목14, 18, 54 참고)은 그렇게 하는 여러 가지 방법들 중 몇 가지일 뿐임

int main() 
{

}



