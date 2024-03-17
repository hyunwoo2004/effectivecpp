#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 13: 자원 관리에는 객체가 그만!

// auto_ptr를 쓰 수 없는 상황이라면 그 대안으로 '참조 카운팅 방식 스마트 포인터'(reference-counting smart pointer: RCSP)가 아주 괜찮음
// RCSP는 특정한 어떤 자원을 가리키는 외부 객체의 개수를 유지하고 있다가 그 개수가 0이 되면 해당 자원을 자동으로 삭제하는 스마트 포인터임
// 이것만 보면, RCSP의 동작은 가비지 컬렉션(garbage collection)의 그것과 상당히 흡사
// 단, 참조 상태가 고리를 이루는 경우를 없앨 수 없다는 점은 기비지 컬렉션과 다름

int main() 
{

}



