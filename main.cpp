#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 13: 자원 관리에는 객체가 그만!

// 이것만은 잊지 말자!
// - 자원 누출을 막기 위해, 생성자 안에서 자원을 획득하고 소멸자에서 그것을 해제하는 RAII 객체를 사용함
// - 일반적으로, 널리 쓰이는 RAII 클래스는 tr1::shared_ptr 그리고 auto_ptr임
//   이 둘 가운데  tr1::shared_ptr이 복사 시의 동작이 직관적이기 때문에 대개 더 좋음
//   반면, auto_ptr은 복사되는 객체(원본 객체)를 null로 만들어버림

int main() 
{

}
