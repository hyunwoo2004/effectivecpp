#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 7: 다형성을 가진 기본 클래스에서는 소멸자를 반드시 가상 소멸자로 선언하자

// 가상 함수가 전혀 없는데도 비가상 소멸자 때문에 뒤통수를 맞는 경우도 있음
// 예시: 표준 string 타입 - 가상 함수를 갖고 있지 않지만, 전후 사정 무시하고 이 타입을 기본 클래스로 잡아버리는 짓을 하는 사람도 있음
class SpecialString : public std::string {   // 가당찮은 아이디어임! std::string은
  ...                                        // 가상 소멸자가 없음!!!
};
// 겉으로는 티가 안나지만 어딘가에서 SpecialString의 포인터를 string의 포인터로 어떻게든 변환한 후에 그 string 포인터에 delete를 적용하면
// 그 순간부터 우리는 '미정의 동작'행 급행 열차로 갈아타게 됨
int main() {
  SpecialString* pss = new SpecialString("Impending Doom");
  std::string* ps;
  ...
  ps = pss;        // SpecialString* => std::string*
  ...
  delete ps;       // 정의되지 않은 동작이 발생
}                  // 실질적으로 *ps의 SpecialString 부분에 있는 자원이 누출되는데
                   // 그 이유는 SpecialString의 소멸자가 호출되지 않기 때문임!








