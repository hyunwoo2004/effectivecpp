#include<iostream>
#include <vector>
// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 4: 객체를 사용하기 전에 반드시 그 객체를 초기화하자

// 객체 값을 초기화하는 데 있어 C++의 행보는 이랬다저랬다 하는 게 영 마음에 들지 않음
// 예시
class Point { 
  int x, y;
};
//...
Point p;
// 여기서 p의 데이터 멤버 역시 어떤 상황에서는 초기화가 보장되지만
// 어쩔 떄는 또 보장 안됨...

int main() {

} 

