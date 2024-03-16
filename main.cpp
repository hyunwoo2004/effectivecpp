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

int main() 
{

}


