#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 5: C++가 은근슬쩍 만들어 호출해버리는 함수들에 촉각을 세우자

// 그렇다면 컴파일러가 만드는 함수가 하는 일이 무엇이기에 저절로 만들어주는 것일까?
// 2. 복사 생성자와 복사 대입 연산자
// 컴파일러가 몰래 만들어낸 복사 생성자/대입 연산자가 하는 일은 매우 단순함
// -> 원본 객체의 비정적 데이터를 사본 객체 쪽으로 그냥 복사만 함
// 예시
template<typename T>
class NamedObject { 
public:
  NamedObject(const char* name, const T& value);
  NamedObject(consst std::string& name, const T& value);
private:
  std::String nameValue;
  T ObjectValue;
};
// 반면, 복사 생성자나 복사 대입 연산자는 NamedObject에 선언되어 있지 않기 때문에
// 두 함수의 기본형이 컴파일러에 의해 만들어짐
NamedObject<int> no1("Smallest Prime Number", 2);
NameObject<int> no2(no1);  // 여기서 복사생성자가 호출됨

// 컴파일러가 만들어주는 NameObject<int>의 복사 대입 연산자도 근본적으로 동작 원리는 같음
// 일반적인 것만 보면, 복사 대입 연산자의 동작이 아까와 같게 되려면
// -> 최종 결과 코드가
// 1. 적법해야 하고(legal)
// 2. 이치에 닿아야만(resonable) 함
// 2개 중 하나라도 검사를 통과하지 못하면 컴파일러는 operator=의 자동생성을 거부함

int main() {

} 

