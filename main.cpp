#include<iostream>
#include <list>

// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 4: 객체를 사용하기 전에 반드시 그 객체를 초기화하자

// 생성자에서 지킬 규칙 - 그 객체의 모든 것을 초기화하자!
// 해결법 - 초기화 리스트 사용
// 예시
ABEtry::ABEtry(const std::string& name, const std::string& address,
          const std::list<PhoneNumber>& phones) 
: theName {name},                    // 이제 이들은 모두 '초기화'되고 있음
  theAddress {address},
  thePhones {phones},
  numTimesConsulted {0}
{}                                   // 생성자 본문에 이제 아무것도 없음
// 앞에 결과와 같지만, 지금의 생성자가 더 효율적일 가능성이 큼
// 이전 방법: 각 데이터 멤버의 기본 생성자를 호출하고 복사 대입 연산자를 호출함
// 위 방법: 각 데이터 멤버의 복사생성자만 호출

int main() {

} 

