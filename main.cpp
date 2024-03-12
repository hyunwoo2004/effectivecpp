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
// 사용자의 망각을 사전에 차단하기 위해 DBConnection에 대한 자원 관리 클래스를 만듦(소멸자에 close() 함수를 호출)
class DBConn {                  // DBConnection 객체를 관리하는 
public:                         // 클래스
  ...
  ~DBConn() {                   // 데이터베이스 연결이 항상 닫히도록
    db.close();                 // 확실히 챙겨주는 함수
  }
private:
  DBConnection db;
};
// 이를 통해 다음과 같은 프로그래밍이 가능
int main() 
{                                        // 블록 시작
  DBConn dbc(DBConnection::create());    // DBConnection 객체를 생성하고
                                         // 이것을 DBConn 객체로 넘겨서
                                         // 관리를 맡김

                                         // DBConn 인터페이스를 통해
                                         // 그 DBConnection 객체를 사용
  
}                                        // 블록 끝. DBConn 객체가
                                         // 여기서 소멸됨. 따라서
                                         // DBConnection 객체에 대한 close
                                         // 함수의 호출이 자동으로 이루어짐 

// close 호출만 일사천리로 성공하면 아무런 문제가 없는 코드
// 그러나 close를 호출했는데 예외가 발생한다면?
// -> DBConn의 소멸자는 분명히 이 예외를 전파할 것
//    쉽게 말해, 그 소멸자에서 예외가 나가도록 내버려 두게 됨 (문제 발생!!!)
// 예외를 던지는 소멸자 --> 우리의 '걱정거리'
