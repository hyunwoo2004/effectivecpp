#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 15: 자원 관리 클래스에서 관리되는 자원은 외부에서 접근할 수 있도록 하자

// 항목 13에 대한 이야기로 시작함
// createInvestment 등의 팩토리 함수를 호출한 결과를 담기 위해 auto_ptr 혹은 tr1::shared_ptr과 같은 스마트 포인터를 사용하는 아이디어를 소개했었음
// 예시
std::tr1::shared_ptr<Investment> pInv(createInvestment());
                                            // 항목 13에서 가져온 예제
// 이때 어떤 Investment 객체를 사용하는 함수로서 우리가 사용하려고 하는 것이 다음과 같다고 가정
// 예시
int daysHeld(const Investment* pi);                            // 투자금이 유입된 이후로
                                                               // 경과한 날수

int main() 
{

}



