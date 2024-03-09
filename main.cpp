#include<iostream>
#include <list>

// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 4: 객체를 사용하기 전에 반드시 그 객체를 초기화하자

// 만약 기본생성자를 만들고 싶을 때도 초기화 리스트를 사용해라
// 생성자 인자로 아무것도 줄 필요도 없으니 더 좋음
// 예시
ABEtry::ABEtry(const std::string& name, const std::string& address,
          const std::list<PhoneNumber>& phones) 
: theName {},                    // theName의 ctor 호출
  theAddress {},                 // theAddress의 ctor 호출
  thePhones {},                  // thePhones의 ctor 호출
  numTimesConsulted {0}          // 0으로 초기화
{}
// 이렇게 하는 게 과하다는 생각을 할 수도 있겠지만 하는게 좋음
// 이유: 만약 numTimesConsulted가 초기화 리스트에 빠진다면 이 객체가 초기화되었는지 알 수 없음
// 그러다가 미정의 동작으로 빠질 가능성+++


int main() {

} 

