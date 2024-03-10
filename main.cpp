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

// 컴파일러산 복사 생성자는 no1.nameValue와 no1.ObjectValue를 사용해서
// no2.nameValue 및 no2.ObjectValue를 각각 초기화해야 함
// 2. no2.ObjectValue
// 이 경우, 기본제공 타입(int)이므로 비트 그대로 복사해 오는 것으로 끝남.

int main() {

} 

