#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 5: C++가 은근슬쩍 만들어 호출해버리는 함수들에 촉각을 세우자

// 그렇다면 컴파일러가 만드는 함수가 하는 일이 무엇이기에 저절로 만들어주는 것일까?
// 2. 복사 생성자와 복사 대입 연산자
// 컴파일러가 만들어주는 NameObject<int>의 복사 대입 연산자도 근본적으로 동작 원리는 같음
// 일반적인 것만 보면, 복사 대입 연산자의 동작이 아까와 같게 되려면
// -> 최종 결과 코드가
// 1. 적법해야 하고(legal)
// 2. 이치에 닿아야만(resonable) 함
// 2개 중 하나라도 검사를 통과하지 못하면 컴파일러는 operator=의 자동생성을 거부함
// 예시
template<typename T>
class NamedObject { 
public:
  // 이 생성자는 이제 상수 타입의 name을 취하지 않음. nameValue가
  // 비상수 string의 참조자가 되었기 때문임. 참조할 string을 가져야 하기 
  // 때문에 char*는 없애버림
  NamedObject(consst std::string& name, const T& value);
  //...
                    // 위의 경우와 마찬가지로 operator=는
                    // 선언된 게 없다고 가정
private:
  std::string& nameValue;    // 이제 이 멤버는 참조자임
  const T ObjectValue;       // 이제 이 멤버는 상수임.
};
// 여기서 어떤 일이 일어날 지는 밑에서 보자
std::string newDog("Persephone");
std::string oldDog("Satch");

NameObject<int> p(newDog, 2); 
NameObject<int> s(oldDog, 36); 

p = s;                         // p에 들어있는 데이터 멤버에서 어떤 일이
                               // 일어날까요?
// 대입 연산이 일어나기 전, p.nameValue와 s.nameValue는 각각 다른 string 객체를 참조하고 있음
// p의 string참조자 자체를 바꿔야 하나? -> C++의 참조자는 원래 자신이 참조하고 있는 것과 다른 객체를 참조할 수 없음
// p가 참조하는 newDog를 바꿔야 하나? -> 그 string에 대한 포인터나 참조자를 품고 있는 다른 객체들, 즉 실제 대입 연산에
// 직접적으로 관여하지 않는 객체까지 영향을 받게 됨 -> 마땅한 일이 아님 (연산자 자동 생성 거부)

int main() {

} 

