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
// 여기서 생성자가 선언되어 있으므로 기본 생성자가 만들어지지 않음
// -> 꼭 인자가 필요한 생성자를 만들어야 겠다고 생각했다면 컴파일러는 인자가 없는 생성자를 만들어 결과가 이상해지지 않는다는 의미

int main() {

} 

