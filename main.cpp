#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 11: operator=에서는 자기대입에 대한 처리가 빠지지 않도록 하자

// 예외 안전성과 자기대입 안전성을 동시에 가진 operator=을 구현하는 방법으로, 방금 본 예처럼
// 문장의 실행 순서를 수작업으로 조정하는 것 외에 다른 방법을 하나 더 알려 주겠음
// '복사 후 맞바꾸기(copy and swap)'라고 알려진 기법인데, 이 기법은 사실 예외 안전성과 아주 밀접한 관계에 있기 때문에
// 항목 29에 자세이 있음. 하지만 이 기법은 operator= 작성에 아주 자주 쓰이기 떄문에 어떤 식으로 구현하는지만 여기서 봐도 아주 도움이 됨
class Widget {
  ...
  void swap(Widget& rhs);      // *this 데이터 및 rhs의 데이터를 맞바꾼다
  ...                          // 자세한 내용은 항목 29에 확인
};

Widget& Widget::operator=(const Widget& rhs)
{
  Widget temp(rhs);            // rhs의 데이터에 대해 사본을 하나 만듦

  swap(temp);                  // *this의 데이터를 그 사본의 것과 맞바꿈
  
  return *this;
}

// 이 방법은 C++가 가진 두가지 특징을 활용해서 조금 다르게 구현할 수도 있음
// 1. 클래스의 복사 대입 연산자는 인자를 값으로 취하도록 선언하는 것이 가능하다
// 2. 값에 의한 전달을 수행하면 전달된 대상의 사본이 생긴다
// 예시
Widget& Widget::operator=(Widget rhs)              // rhs는 넘어온 원래 객체의 사본임
{                                                  // - '값에 의한 전달'이라고 했음
  
  swap(temp);                                      // *this의 데이터를 이 사본의
                                                   // 데이터와 맞바꿈
  return *this;
}


int main() 
{

}


