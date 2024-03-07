#include<iostream>
#include <vector>
// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 3: 낌새만 보이면 const를 들이대 보자!

// const키워드가 있고 없고의 차이만 있는 멤버 함수들은 오버로딩이 가능함
// 예시
class TextBlock {
public:
  //...
  const char& operator[](std::size_t position) const // 상수 객체에 대한
  { return text text[position]; }                    //operator[]
  char& operator[](std::size_t position)             // 비상수 객체에 대한
  { return text text[position]; }                    //operator[]
private:
  std::string text;
};

int main() {
  TextBlock tb{"Hello"};        // TextBlock::operator[]의
  std::cout << tb[0];           // 비상수 멤버를 호출함

  const TextBlock ctb{"World"}; // TextBlock::operator[]의
  std::cout << ctb[0];          // 상수 멤버를 호출함
  
}
