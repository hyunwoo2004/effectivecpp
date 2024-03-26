#include<iostream>

// Effective C++
// 4. 설계 및 선언
// 항목 18: 인터페이스 설계는 제대로 쓰기엔 쉽게, 엉터리로 쓰기엔 어렵게 하자

// 이런 가정도 한번 해 보자 -  createInvestment를 통해 얻은 Investment* 포인터를 직접 삭제하지 않게 하고 
//                             getRidOfInvestment라는 이름의 함수를 준비해서 여기에 넘기게 하면 어떤가?
// 왠지 더 깔끔해 보이지만 이런 인터페이스는 되레 사용자 실수를 하나 더 열어놓는 결과를 가져옴
// 자원 해제 매커니즘을 잘못 사용할 수가 있음 (getRidOfInvestment를 잊고 delete를 쓰는 경우)
// createInvestment를 살짝 고쳐서, getRidOfInvestment가 삭제자로 묶인 tr1::shared_ptr을 반환하도록 
// 구현해 둔다면 이런 문제는 발도 못 들여놓을 것이다.

// tr1::shared_ptr에는 두 개의 인자를 받는 생성자가 있다
// 첫번째 인자는 이 스마트 포인터로 관리할 실제 포인터고, 두 번쨰 인자는 참조 카운트가 0이 될 때 호출될 삭제자임
// -> 그러니까 tr1::shared_ptr이 널(null) 포인터를 물게 함과 동시에 삭제자로 getRidOfInvestment를 
//    갖게 하는 방법으로 다음과 같은 코드를 쓰면 안 될까라는 생각이 들 수 있음

std::tr1::shared_ptr<Investment>                      // 이렇게 해서 사용자 정의 삭제자를 가진
  pInv(0, getRidOfInvestment);                        // 널 shared_ptr을 생성했으면 좋겠다.
                                                      // 그런데 컴파일이 안 되니 난감할 뿐임

// 이것은 제대로 쓴 C++ 코드가 아님

int main() 
{
}


