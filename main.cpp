#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 8: 예외가 소멸자를 떠나지 못하도록 붙들어 놓자

// 예외를 던지고 실패할 수 있는 코드를 소멸자에 넣어야만 하는 경우?
// 예시: 데이터베이스 연결을 나타내는 클래스
class DBConnection {
public:
  ...
  static BDConnection create(); // DBConnection 객체를 반환하는
                                // 함수. 매개변수는 편의상 생략함

  void close();                 // 연결을 닫음. 이때,
};                              // 연결을 실패하면 예외를 던짐
// 사용자가 BDConnection 객체에 대해 close를 직접 호출해야 함

int main() {

}          
