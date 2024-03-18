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

int main() 
{

}
