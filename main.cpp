#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 12: 객체의 모든 부분을 빠짐없이 복사하자

// 결국 우리가 할 일은 한 가지 - 클래스에 데이터 멤버를 추가했으면, 추가한 데이터 멤버를 처리하도록 복사 함수를 다시 작성해야 함
// 비표준형 operator= 함수도 전부 바꿔 줘야 함

// 이 문제가 가장 사악하게 프로그래머를 괴롭히는 경우가 하나 있는데, 바로 클래스 생속임
// 예시
class PriorityCustomer : public customer {
public:
  ...  
  PriorityCustomer(const PriorityCustomer& rhs);
  PriorityCustomer& operator=(const PriorityCustomer& rhs);
  ...
private:
  int priority;
};
PriorityCustomer::PriorityCustomer(const PriorityCustomer& rhs)
  :  priority(rhs.priority)
{
  logCall("PriorityCustomer copy constructor");
}

PriorityCustomer& 
PriorityCustomer::operator=(const PriorityCustomer& rhs)
{
 logCall("PriorityCustomer copy assignment operator");

  priority = rhs.priority;

  return *this;
}
// PriorityCustomer 클래스의 복사 함수는 언뜻 보기엔 PriorityCustomer의 모든 것을 복사하고 있는 것처럼 보이지만, 다시 한번 보라!
//  PriorityCustomer에 선언된 데이터 멤버를 모두 복사하고 있는 것은 사실이지만, Customer로부터 상속한 데이터 멤버들의 사본도 엄연히 
// PriorityCustomer클래스에 들어 있는데, 이들은 복사가 안 되고 있음!!!

int main() 
{

}


