#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 11: operator=에서는 자기대입에 대한 처리가 빠지지 않도록 하자

// 언뜻 보기에 명확하지 않은 이러한 자기대입이 생기는 이유는 여러 곳에서 하나의 객체를 참조하는 상태, 즉 중복참조(aliasing) 때문임
// 같은 타입으로 만들어진 객체 여러 개를 참조자 혹은포인터로 물어 놓고 동작하는 코드를 작성한 때는 같은 객체는 사용될 가능성을 
// 고려하는 것이 일반적으로 바람직한 자세임!

// 사실, 같은 클래스 계통에서 만들어진 객체라 해도 굳이 똑같은 타입으로 선언할 필요까지는 없음
// 파생 클래스 타입의 객체를 참조하거나 가리키는 용도로 기본 클래스의 참조자나 포인터를 사용하면 됨
// 예시
class Base {...};
class Derived {...};      
void something(const Base& rb,                // rb 및 *pd는 원래 같은
                Derived* pd);                 // 객체였을 수도 있음

int main() 
{

}


