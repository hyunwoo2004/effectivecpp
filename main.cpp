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

int main() 
{

}



