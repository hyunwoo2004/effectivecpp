#include<iostream>
#include <vector>
// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 3: 낌새만 보이면 const를 들이대 보자!

// STL 반복자(iterator)는 포인터를 본뜬 것이기 때문에, 기본적인 동작 원리가 T* 포인터와 진짜 흡사함
// 어떤 반복자를 const로 선언하는 일은 포인터를 상수로 선언하는 것과 같음(const ...iterator* == T* const)
// 반복자는 자신이 가리키는 대상이 아닌 것을 가리키는 경우가 허용되지 않지만, 반복자가 가리키는 대상 자체는 변경이 가능함
// 만약 변경이 불가능한 객체를 가리키는 반복자가 필요하다면 const_iterator를 쓰면 됨

int main() {
  std::vector<int> vec;
  const std::vector<int>::iterator iter = vec.begin();
                                          // iter는 T* const처럼 동작
  *iter = 10;                             // OK, iter가 가리키는 대상을 변경
  ++iter;                                 // 에러! iter는 상수입니다

  std::vector<int>::const_iterator cIter = vec.begin();
                                          // cIter는 const T*처럼 동작
  *cIter = 10;                            // 에러! *cIter가 상수이기 때문에 안됨
  ++cIter;                                // 이건 문제없습니다. cIter를 변경
}
