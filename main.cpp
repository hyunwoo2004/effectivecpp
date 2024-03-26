#include<iostream>

// Effective C++
// 4. 설계 및 선언
// 항목 18: 인터페이스 설계는 제대로 쓰기엔 쉽게, 엉터리로 쓰기엔 어렵게 하자

// 이런 가정도 한번 해 보자 -  createInvestment를 통해 얻은 Investment* 포인터를 직접 삭제하지 않게 하고 
//                             getRidOfInvestment라는 이름의 함수를 준비해서 여기에 넘기게 하면 어떤가?
// 왠지 더 깔끔해 보이지만 이런 인터페이스는 되레 사용자 실수를 하나 더 열어놓는 결과를 가져옴
// 자원 해제 매커니즘을 잘못 사용할 수가 있음 (getRidOfInvestment를 잊고 delete를 쓰는 경우)

int main() 
{
}


