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
// 이렇듯 상식을 살짝 비껴가는 복사 동작도 그렇고, auto_ptr이 관리하는 객체는 두 개 이상의 auto_ptr 객체가 물고 있으면 안 된다는 요구사항까지 깔려 있는 통에
// 동적으로 할당되는 모든 자원에 대한 관리 객체로서 auto_ptr을 쓰는 것은 최선이 아닐 듯하다는 느낌이 듬
// 예시로, STL 컨테이너의 경우엔 원소들이 '정상적인' 복사 동작을 가져야 하기 때문에, auto는 이들의 원소로 허용되지 않음


