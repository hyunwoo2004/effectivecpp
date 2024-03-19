#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 14: 자원 관리 클래스의 복사 동작에 대래 진지하게 고찰하자

// 사실, 힙에 생기지 않는 자원은 auto_ptr 혹은 shared_ptr 등의 스마트 포인터로 처기해 주기엔 맞지 않다는 것이 일반적인 견해임
// 항상 그런 것은 아니지만, 자원 관리 클래스를 우리가 스스로 만들어야 할 필요를 느끼는 경우가 바로 이런 경우임

// 그런데 Lock 객체가 복사된다면 어떻게 해야 하는가?
{
  Lock m11(&m);                                  // m에 잠금을 검
  Lock m12(m11);                                 // m11을 m12로 복사함. 어떨게 되는가?
}
// 사실 이 질문은 약간 더 일반화해서 이렇게 정리할 수 있음 - RAII 클래스를 만들어 본 사람이라면 한 번쯤 고민해 볼만한 질문임
// "RAII 객체가 복사될 때 어떤 동작이 이루어져야 하는가?"임
// 아마도 열에 아홉은 다음의 선택지 중 하나를 골라야 함
// 2. 관리하고 있는 자원에 대해 참조 카운팅을 수행한다
// 자원을 사용하고 있는 마지막 객체가 소멸될 때가지 그 자원을 저 세상으로 안 보내는 게 바람직한 경우도 종종 있음
// 이런 경우에는, 해당 자원을 참조하는 객체의 개수에 대한 카운트를 증가하는 식으로 RAII 객체의 복사 동작을 만들어야 함
// 참고로, 이런 방식은 현재 tr1::shared_ptr이 사용하고 있음

// 자신의 RAII 클래스에 참조 카운틷 방식의 복사 동작을 넣고 싶을 때 tr1::shared_ptr을 데이터 멤버로 넣으면, 간단히 해결될까?
// 그러니까 Lock이 참조 카운팅 방식으로 돌아가면 졸을 것 같다고 생각했다면, mutexPtr의 타입을 Mutex*에서 tr1::shared_ptr<Mutex>로 바꾸라는 것임
// 단, 아쉽게도 tr1::shared_ptr은 참조 카운트가 0이 될 때 자신이 가리키고 있던 대상을 삭제해 버리도록 기본 동작이 만들어져 있어서
// 우리의 바람과는 다소 어긋남 -> Mutex를 다 썼을 때 이것에 대해 잠금 해제만 하명 되지, 삭제까지 하고 싶진 않음

// 참으로 다행인 것은 tr1::shared_ptr이 '삭제자(deleter)' 지정을 허용한다는 사실임
// 여기서 삭제자란, tr1::shared_ptr이 유지하는 참조 카운트 0이 되었을 때 호출되는 함수 혹은 함수 객체를 일컫음(반면, auto_ptr에는 이 기능이 없음)
// 삭제자는 tr1::shared_ptr 생성자의 두 번째 매개변수로 선택적으로 넣어 줄 수 있음
// 예시
class Lock {
public:
  explicit Lock(Mutex* pm)                       // shared_ptr을 초기화하는데, 가리킬 포인터로
  : mutexPtr(pm, unlock)                         // Mutex 객체의 포인터를 사용하고 삭제자로
  {                                              // unlock 함수를 사용
    
    lock(mutexPtr.get());                        // "get"의 이야기는 항목 15 참고
  }
private:
  std::tr1::shared_ptr<Mutex> mutexPtr;          // 원시 포인터 대신에
};                                               // shared_ptr을 사용함
// 이 예제에서는 눈 부릅뜨고 볼 부분은 Lock 클래스가 이제는 소멸자를 선언하지 않는다는 점임 (이유: 필요없음)
// 항목 5을 본 사람음 알겠지만 클래스의 소멸자는 비정적 데이터 멤버의 소멸자를 자동으로 호출하게 되어 있음
// 이 '비정적 데이터 멤버'에 해당하는 것이 mutexPtr임
// 그런데, mutexPtr의 소멸자는 뮤텍스의 참조 카운트가 0이 될 때 tr1::shared_ptr의 삭제자(예제: unlock)를 자동으로 호출할 거임
// "이런 코드에 주석문으로 '객체 소멸 과정을 잊는 게 아니라 컴파일러가 생성한 소멸자를 통해 동작한다'정도의 설명을 달아두면 좋음"

int main() 
{

}



