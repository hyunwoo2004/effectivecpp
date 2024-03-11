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
// 팩토리 함수의 기존 규약을 그대로 따라간다면 getTimeKeeper 함수에서 반환되는 객체는 힙(Free store의 옛 명칭, 영어로는 Heap)에 있게 되므로
// 결국 메모리 및 기타 자원의 누출을 막기 위해 해당 객체를 적절히 delete 해야 함
int main() {
  TimeKeeper* ptk = getTimeKeeper();    // TimeKeeper클래스 계통으로부터
                                        // 동적으로 할당된 객체를 얻음
  
  ...                                   // 이 객체를 사용
  
  delete ptk;                           // 자원 누출을 막기 위해 해제(삭제)함
} 
// 아쉬운 점 - 우선 지나가는 이야기
// 객체 삭제를 사용자에게 전가하는 것은 에러 발생에 노출될 소지가 있음
// 팩토리 함수의 인터페이스를 수정하면 흔히 발생할 수 있는 사용자 에러를 방지할 수 있음 

