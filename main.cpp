#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 9: 객체 생성 및 소멸 과정 중에는 절대로 가상 함수를 호출하지 말자

// 이제는 이 문제의 대처방법에 대해 말하겠음
// 방법은 여러 가지이지만 한 가지만 설명할 것임
// -> logTransaction을 Transaction 클래스의 비가상 멤버 함수로 바꾸는 것임
//    그러고 나서 파생 클래스의 생성자들로 하여금 필요한 로그 정보를 Transaction의 생성자로 넘겨야 한다는 규칙을 만든다
// logTransaction이 비가상 함수이기 때문에 Transaction의 생성자는 이 함수를 안전하게 호출 가능
class Transaction {
public:
  explicit Transaction(const std::string& logInfo);
  void logTransaction(const std:: string& logInfo) const;  // 이제는 비가상
  ...                                                      // 함수임
};
Transaction::Transaction(const std::string& logInfo) 
{
  ...
  logTransaction(logInfo);                                 // 이제는 비가상 함수를
}                                                          // 호출함

class BuyTransaction : public Transaction {
public:
  BuyTransaction( parameters )
    : Tranaction(createLogString( parameters ))            // 로그 정보를
  {  ...  }                                                // 기본 클래스
  ...                                                      // 생성자로 넘김
private:
  static std::string createLogString( parameters );
};

// 기본 클래스 부분이 생성될 떄는 가상 함수를 호출한다 해도 기본 클랫의 울타리를 넘어 나려갈 수 없기 때문에, 필요한 초기롸 정보를 
// 파생 클래스 쪽에서 기본 클래스 생성자로 '올려'주도록 만듦으로써 부족한 부분을 역으로 채울 수 있다는 것

int main() 
{
}
