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

int main() 
{

}



