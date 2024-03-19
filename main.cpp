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
// 4. 관리하고 있는 자원의 소유권을 옮긴다.
// 그리 흔한 경우는 아니지만, 어떤 특정한 자원에 대해 그 자원을 실제로 참조하는 RAII 객체는 딱 하나만 존재하도록 만들고 싶어서,
// 그 RAII 객체가 복사될 때 그 자원의 소유권을 사본 쪽으로 아예 옮겨야 할 경우도 살다 보면 생김
// 이런 스타일의 복사는 이미 항목 13에서 본 적이 있음 - (바로 auto_ptr의 '복사'동작)


int main() 
{

}



