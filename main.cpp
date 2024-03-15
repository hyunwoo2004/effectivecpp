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

int main() 
{

}


