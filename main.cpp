#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 7: 다형성을 가진 기본 클래스에서는 소멸자를 반드시 가상 소멸자로 선언하자

// 예를 들어, 시간 기록을 유지하는 TimeKeeper 클래스를 기본 클래스로 만들어 놓은 후에
//            적절한 용도에 따라 이것을 파생시키도록 설계
class TimeKeeper {
public:
  TimeKeeper();
  ~TimeKeeper();
  ...
};

class AtomicClock : public TimeKeeper {...};
class WaterClock : public TimeKeeper {...};
class WristClock : public TimeKeeper {...};
// 이 클래스의 혜택을 받는 사용자들은 시간 정보에 접근하고 싶음
// -> 어떤 시간 기록 객체에 대한 포인터를 손에 넣는 용도로 팩토리 함수(factory function, 새로 생성된 파생 클래스 객체에 대한 기본 클래스 포인터를 반환하는 함수)
//    를 만들기
TimeKeeper* getTimeKeeper();

int main() {

} 

