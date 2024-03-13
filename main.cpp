#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 9: 객체 생성 및 소멸 과정 중에는 절대로 가상 함수를 호출하지 말자

// 위의 예제 코드를 다시 보자
//  Transaction 생성자에서 가상 함수를 직접 호출하는 코드는 이번 항목의 지침을 위반한 것인데
// 반론의 여지가 없을 뿐 아니라 눈에도 잘 띄는 위반이 되겠음
// 이런 위반은 누가 보더라도 발견이 쉽기 때문에 이런 경우에 대해 경고 메시지를 내어 주는 컴파일러도 꽤 있음
// 물론 컴파일러 경고가 나오지 않더라고 프로그램 실행 전에 문제가 드러남(logTransaction 함수가 Transaction 클래스에서 순수 가상 함수로 선언되어 있기 때문)
// 이 함수의 정의가 존재하지 않으면 링크 단계에서 에러가 발생(링크가 제대로 되려면 Transaction::logTransaction이 구현 코드가 있어야 함)
 
int main() 
{
}
