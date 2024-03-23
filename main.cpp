#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 17: new로 생성한 객체를 스마트 포인터에 저장하는 코드는 별도의 한 문장으로 만들자

// 예시
processWidget(std::tr1::shared_ptr<Widget>(new Widget), priority());

// 컴파일러는 processWidget 호출 코드를 만들기 전에 우선 이 함수의 매개변수로 넘겨지는 인자를 평가하는 순서를 밟음
// 여기서 두번째 인자는 priority 함수의 호출문 밖에 없지만, 첫 번째 인자("tr1::shared_ptr<Widget>(new Wieget)")는 두 부분으로 나누어져 있음

// - "new Widget" 표현식을 실행하는 부분
// - tr1::shared_ptr 생성자를 호출하는 부분

// 사정이 이렇기 떄문에, processWidget 함수 호출이 이루어지기 전에 컴파일러는 다음의 세 가지 연산을 위한 코드를 만들어야 함

// - priority을 호출함
// - "new Widget"을 실행함
// - tr1::shared_ptr 생성자를 호출함

// 그런데, 여기서 각각의 연산이 실행되는 순서는 컴파일의 제작사마다 다르다는 게 문제임
// C++ 컴파일러의 경우엔 이들의 순서를 정하는 데 있어서 상당한 자유도를 갖고 있음! (자바, C#은 매개변수의 평가 순서가 특정하게 고정됨)
// "new Widget" 표현식은 tr1::shared_ptr 생성자가 실행될 수 있기 전에 호출되어야 함
// 왜냐하면 이 표현식의 결과가 tr1::shared_ptr 생성자의 인자로 넘어가니까 당연함
// 그러나 priority 호출은 처음 호출될 수도 있고, 두 번쨰나 세 번째에 호출될 수 있음

int main() 
{

}



