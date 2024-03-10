#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 5: C++가 은근슬쩍 만들어 호출해버리는 함수들에 촉각을 세우자

// 클래스가 비어 있지만(empty) 비어 있는게 아닌 때가 있음
// 에시
class Empty {}; // 우리가 이렇게 썼다고 가정해 보자

// --- 실제 컴파일러 ---
class Empty {
public:
  Empty() {}                             // ctor
  Empty(const Empty& rhs) {}             // copy ctor
  ~Empty() {}                            // dtor: 가상 함수 여부에 대해서느
                                         // 밑에서 더 자세히 설명하겠음
  Empty& operator=(const Empty& rhs) {}  // copy assignment operator
};

int main() {

} 

