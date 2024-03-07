#include<iostream>
#include <vector>
// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 3: 낌새만 보이면 const를 들이대 보자!

// 프로그랭에서 상수 객체가 생기는 경우
// 1. 상수 객체에 대한 포인터
// 2. 상수 객체에 대한 참조자로 객체가 전달될 때
// 예시
void print(const TextBlock& ctb)      // 이 함수에서 ctb는 상수 객체로 쓰임
{
  std::cout << ctb[0];                // TextBlock::operator[]의 상수
                                      // 멤버를 호출
}



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
