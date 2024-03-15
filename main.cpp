#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 12: 객체의 모든 부분을 빠짐없이 복사하자

// 그런데 데이터 멤버 하나를 Customer에 추가하면서 행복에 금이 가기 시작함
class Date {...};                                  // 날짜 정보를 위한 클래스

class Customer {
public:
  ...                                              // 이전과 동일
private:
  std::string name;
  Date lastTransaction;
};
// 이렇게 되고 나면 복사 함수의 동작은 완전 복사가 아니라 부분 복사(partial copy)가 됨
// 고객의 name은 복사하지만, lastTransaction은 복사하지 않음
// 여기서 주의할 점이 있는데, 이런 상황에 대해 일언반구라도 해 주는 컴파일러가 거의 없음
// 컴파일러가 경고 수준을 최대로 높여도 마찬가지.
// 컴파일러가 복사 함수를 정성스레 마련해 주겠다는데 우리가 거절했으니, 우리 구현이 죽이 되든 밥이 되든 입도 뻥끗 하지 안함

int main() 
{

}


