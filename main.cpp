#include<iostream>
#include <vector>
// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 3: 낌새만 보이면 const를 들이대 보자!

// 상수 멤버 및 비상수 멤버 함수에서 코드 중복 현상을 피하는 방법
// 그렇다면 이렇게 생각해보자. -> operator[] 양 버전들 중 하나만 제대로 만들고 다른 버전은 이것을 호출하면 어떨까?
// 상수 버전을 만들고 const 껍데기를 캐스팅으로 날리면 가능?
// 예시
class TextBlock {
public:
  //...
  const char& operator[](std::size_t position) const // 이전과 동일
  {
    //...      
    //...     
    //...      
    return text[position];
  }

  char& operator[](std::size_t position) // 상수 버전 op[]를 호출하고 끝
  {
    return 
      const_cast<char&>(                 // op[]의 반환 타입에 반환캐스팅을 적용, 
                                         // const를 때어냄
      static_cast<const TextBlock&>      // *this타입에 const를 붙임
        (*this)[position]                // op[]의 상수 버전을 호출함
      );
  }
private:
  std::string text;
};
// 위 코드를 보면 캐스팅을 두번함
// 1. *this에 const를 붙이는 캐스팅 (static_cast)
// 2. 상수 operator[]의 반환 값에서 const를 때어내는 캐스팅 (const_cast)

// +a
// 기본적으로, 캐스팅은 일반적으로도 통념적으로도 좋은 아이디어가 아님
// 그렇다고 코드를 중복하기에도 문제점이 많음

int main() {

} 

