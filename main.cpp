#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 12: 객체의 모든 부분을 빠짐없이 복사하자

Customer::Customer(const Customer& rhs) 
  : name(rhs.name)                                 // rhs의 데이터를 복사함
{
  logCall("Customer copy constructor");
}

Customer& operator=(const Customer& rhs) 
{
  logCall("Customer copy assignmenr operator");
  
  name = rhs.name;                                 // rhs의 데이터를 복사함
   
  return *this;                                    // 항목 10 참고
}
// 문제될 것이 하나도 없어 보임. 실제로 그렇다
// 그런데 데이터 멤버 하나를 Customer에 추가하면서 행복에 금이 가기 시작함

class Date {...};                                  // 날짜 정보를 위한 클래스

class Customer {
public:
  ...                                              // 이전과 동일
private:
  std::string name;
};

int main() 
{

}


