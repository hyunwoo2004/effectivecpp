#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 14: 자원 관리 클래스의 복사 동작에 대래 진지하게 고찰하자

// 사실, 힙에 생기지 않는 자원은 auto_ptr 혹은 shared_ptr 등의 스마트 포인터로 처기해 주기엔 맞지 않다는 것이 일반적인 견해임
// 항상 그런 것은 아니지만, 자원 관리 클래스를 우리가 스스로 만들어야 할 필요를 느끼는 경우가 바로 이런 경우임

// 예시: Mutex 타입의 뮤텍스 객체를 조작하는 C API를 우리가 사용하는 중이라고 가정
//       -> 이 C API에서 제공하는 함수 중엔 lock 및 unlock이 있음
void lock(Mutex *pm);            // pm이 가리키는 뮤텍스에 잠금을 킴

void unlock(Mutex *pm);          // pm이 가리키는 해당 뮤텍스에 잠금을 품
// 그런데 뮤텍스 잠금을 관리하는 클래스를 하나 만들고 싶음
// 이전에 걸어 놓은 뮤텍스 잠금을 잊지 않고 풀어 줄 목적임
// 이런 용도의 클래스는 기본적으모 RAII 법칙을 따라 구성함
// 즉, 생성 시에 자원을 획득하고, 소멸 시에 그 자원을 해제하는 것
// 예시
class Lock {
public:
  explicit Lock(mutex* pm)
    : mutexPtr(pm)
  {  lock(mutexPtr);  }                          // 자원을 획득함

  ~Lock() { unlock(mutexPtr); }                  // 자원을 해제함
private:
  Mutex* mutexPtr;
};
// 사용자는 Lock을 사용할 때 RAII 방싱에 맞추어 쓰면 됨
int main() 
{
  Mutex m;                                       // 우리가 쓰고 싶은 뮤텍스를 정의함
  ...
  {                                              // 임계 영역을 정하기 위해 블록을 만듦
    
    Lock m1 (&m);                                // 뮤텍스에 짐금을 검

    ...                                          // 임계 영역에서 할 연산을 수행
    
  }                                              // 블록의 끝임. 뮤텍스에 걸렸던 잠금이
                                                 // 자동으로 풀림
}
