#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 17: new로 생성한 객체를 스마트 포인터에 저장하는 코드는 별도의 한 문장으로 만들자

// 이런 문제를 피해가는 방법은 간단함 - Widget을 생성해서 스마트 포인터에 저장하는 코드를 별도의 문장 하나로 만들고, 그 스마트 포인터를 processWidget에 넘기는 것임
// 예시
std::tr1::shared_ptr<Widget> pw(new Widget);              // new로 생성한 객체를 
                                                          // 스마트 포인터에 담는 코드를
                                                          // 하나의 독립적인 문자응로 만듦

processWidget(pw, priority());                            // 이제는 자원 누출 걱정이 없음

// 한 문장 안에 있는 연산들보다 문장과 문장 사이에 있는 연산들이 컴파일러의 재조정을 받을 여지가 적기 때문에 위의 코드는 자원 누출 가능성이 없음
// 고쳐진 코드를 보면 "new Widget" 표현식과 tr1::shared_ptr 생성자는 한 문장에 들어 있고, priority를 호출하는 코드는 별도의 문장에 있음
// 그렇기 때문에 컴파일러가 priority 호출을 들 사이로 옮기고 싶어도 허용이 안 되는 거임

int main() 
{

}



