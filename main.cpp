#include<iostream>
#include <list>

// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 4: 객체를 사용하기 전에 반드시 그 객체를 초기화하자

// 생성자에서 지킬 규칙 - 그 객체의 모든 것을 초기화하자!
// 쉬운 규칙 같지만 주의 할 점 -> 대입(Assignment)을 초기화(initialization)와 헷갈리지 않아야 함
// 예시
class PhoneNumber {...};

class ABEtry {       // ABEtry = "Address Book Entry"
public:
  ABEtry(const std::string& name, const std::string& address,
          const std::list<PhoneNumber>& phones);
private:
  std::string theName;
  std::string theAddress;
  std::list<PhoneNumber> thePhones;
  int numTimesConsulted;
};

ABEtry::ABEtry(const std::string& name, const std::string& address,
          const std::list<PhoneNumber>& phones) 
{
  theName = name;                    // 지금은 모두 '대입'을 하고 있음
  theAddress = address;              // '초기화'가 아님
  thePhones = phones;
  numTimesConsulted = 0;
}
// 원하는 결과는 나오겠지만 썩 좋지 않음
// C++ 규칙에 의하면 어떤 객체이든 그 객체의 데이터 멤버는 생성자의 본문이 실행되기 '전에' 초기화되어야 한다고 명시됨
// 위에 있는 생성자에서 '대입'하기 전에 데이터 멤버는 기본 생성자가 호출됨 (기본제공 타입의 데이터 멤버는 제외)

int main() {

} 

