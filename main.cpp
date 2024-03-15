#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 12: 객체의 모든 부분을 빠짐없이 복사하자

// 객체 복사 함수를 우리가 선언한다는 것은, 컴파일러가 만든 녀석의 기본 동작에 뭔가 마음에 안 드는 것이 있다는 이야기임
// 이에 대해 컴파일러도 썩 반기는 분위기는 아니라는 듯, 꽤나 까칠한 자세로 우리를 골탕 먹이려 함
// -> 우리가 구현한 복사 함수가 거의 확실히 틀렸을 경우에도 입을 다물어 버림
// 예시: 고객(customer)을 나타내는 클래스가 있다고 가정 -> 이 클래스의 복사 함수는 개발자가 직접 구현했고 복사 함수를 호출할 때마다 로그를 남기도록 작성
void logCall(const std::string& funcName);         //  로그 기록 내용을 만듦

class Customer {
public:
  ...
  Customer(const Customer& rhs);
  Customer& operator=(const Customer& rhs);
  ...
private:
  std::string name;
};


int main() 
{

}


