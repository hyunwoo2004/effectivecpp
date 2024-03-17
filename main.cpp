#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 13: 자원 관리에는 객체가 그만!

// auto_ptr은 소멸될 때 자신이 가리키는 대상에 대해 자동으로 delete를 먹이기 때문에, 어떤 객체를 가리키는 auto_ptr의 개수가 둘 이상이면 절대로 안 됨
// -> 만에 하나 이런한 사태가 되면 결국 자원이 두 번 삭제되는 결과를 낳게 되고, 프로그램은 미정의 동작의 수렁에 빠지게 욈
// 이를 막기 위해 auto_ptr에는 유별난 특성이 있음 - auto_ptr 객체를 복사하면, 원본 객체는 null로 만듦
//                                                  (복사하는(copying) 객체만이 그 자원의 유일한 소유권(ownership)을 갖는다고 가정)
// 예시
int main() 
{
  std::auto_ptr<Investment>                                 // pInv1이 가리키는 대상은
              pInv1(createInvestment());                    // createInvestment 함수에서
                                                            // 반환된 객체임

  std::auto_ptr<Investment> pInv2(pInv1);                   // pInv2는 현재 그 객체를 가리키고
                                                            // 있는 반면, 이제 pInv1은 null임
  
  pInv1 = pInv2;                                            // 지금 pInv1는 그 객체를 가리키고
                                                            // 있으며, pInv2은 null임
}


