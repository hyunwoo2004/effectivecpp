#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 17: new로 생성한 객체를 스마트 포인터에 저장하는 코드는 별도의 한 문장으로 만들자

// 처리 우선순위를 알려 주는 함수가 하나 있고, 동적으로 할당한 Widget 객체에 대해 어떤 우선순위에 따라 처리를 적용하는 함수가 하나 있다고 가정함

int priority{};

void processWidget(std::tr1::shared_ptr<Widget> pw, int priority);

// 자원 관리에는 객체를 사용하는 것이 좋다는 겨레의 가르침(항목 13 참조)을 코드에 되살려, 
// process Widget 함수는 동적 할당된 Widget 객체에 대해 스마트 포인터(여기서 tr1::shared_ptr)를 사용하도록 만들어짐

int main() 
{

}



