#include<iostream>

// Effective C++
// 4. 설계 및 선언
// 항목 20: '값에 의한 전달'보다는 '상수객체 참조자'방식을 택하는 편이 대개 낫다

// 기본적으로 C++는 함수로부터 객체를 전달받거나 함수에 객체를 전달할 때 '값에 의한 전달(pass-by-value)' 방식을 사용함(C에서 물려받은 특성)
// 특별히 다른 방식을 지정하지 않는 한, 함수 매개변수는 실제 인자의 '사본'을 통해 초기화되며, 어떤 함수를 호출한 쪽은 그 함수가 반환한 값의 '사본'을 돌려 받음
// 이들 사본을 만들어내는 원천이 바로 복사생성자인데, 이 점 떄문에 '값에 의한 전달'이 고비용의 연산이 되기도 함 - 이유는?
// 예시: 아래의 클래스 계통을 보고 생각해보자!

class Person {
public:
  Person();                                                     // 매개변수는 간결함을 위해 생략
  virtual ~Person();                                            // 가상 소멸자인 이유는 항목 7 참고
  ...
private:
  std::string name;
  std::string address;
};


int main() 
{
} 


