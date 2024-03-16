#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 12: 객체의 모든 부분을 빠짐없이 복사하자

// 사정이 어쨌든, 파생 클래스에 대한 복사 함수를 우리가 스스로 만든다고 결심했으면
// 기본 클래스 부분을 복사해서 빠뜨리지 않도록 각별히 주의하자!
// 물론 기본 클래스 부분은 private 멤버일 가능성이 높기 때문에(항목 22 참조), 이들을 직접 건드리긴 어려움
// 그 대신, 파생 클래스의 복사 함수 안에서 기본 클래스의 복사 함수를 호출하도록 만들면 됨
PriorityCustomer::PriortyCustomer(const PriorityCustomer& rhs)
  : Customer(rhs),                                               // 기본 클래스의 복사 생성자를 호출함
    Priority(rhs.Priority)
{
  logCall("PriorityCustomer copy constructor");
}

PriorityCustomer& PriorityCustomer::operator=(const PriorityCustomer& rhs)                                             
{
  logCall("PriorityCustomer copy assignment operator");

  Customer::operator=(rhs);                                      // 기본 클래스 부분을 대입함
  priority = rhs.priority;

  return *this;
}
// 이번 항목의 제목으로 "모든 부분을 복사하자"라는 말의 말귀를 이제 이해할 수 있을 것임
// 객체의 복사 함수를 작성할 때는 다음의 두 가지를 확인하자
// 1. 해당 클래스의 데이터 멤버를 모두 복사하기
// 2. 이 클래스가 상속한 기본 클래스의 복사 함수도 꼬박꼬박 호출하기

//   사실, 클래스의 양대 복사 함수는 본문이 비슷하게 나오는 경우가 자주 있어서, 한쪽에서 다른 쪽을 
// 호출하게 만들어서 코드 판박이를 피하면 좋겠다는 유혹 떄문에 손가락이 간질거리는 사람도 있을 것임
// 코드 중복을 피하려는 기특한 마음이야 뭐라 할 건 아니지만, 한쪽에서 다른 쪽을 호출하는 식으로 두 개의
// 복사 함수를 만드면 그걸로 끝난 것은 전혀 아니다.

// 복사 대임 연산자에서 복사 생성자를 호출하는 것부터 말이 안되는 발상임
// 이미 만들어져 버젓이 존재하는 객체를 '생성'하고 있으니 문제임
// 이렇게 할 수 있는 문법도 없음



int main() 
{

}


