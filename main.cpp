#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 12: 객체의 모든 부분을 빠짐없이 복사하자

//  객체의 안쪽 부분을 캡슐화한 객체 지향 시스템 중 설계가 잘 된 것들을 보면 
// 객체를 복사하는 함수가 딱 둘만 있는 것을 알 수 있음
// 복사 생성자와 복사 대입 연산자라고, 성격에 따라 이름도 적절히 지어져 있음
// 이 둘을 통틀어 객체 복사 함수(copying function)라고 부름
// 객체 복사 함수는 컴파일러가 필요에 따라 만들어내기도 함
// 그리고 컴파일러가 생성한 복사 함수는 비록 저절로 만들어졌지만 동작은 기본적인 요구에 아주 충실함
// '복사되는 객체가 갖고 있는 데이터를 빠짐없이 복사한다', 바로 이거임

// 객체 복사 함수를 우리가 선언한다는 것은, 컴파일러가 만든 녀석의 기본 동작에 뭔가 마음에 안 드는 것이 있다는 이야기임
// 이에 대해 컴파일러도 썩 반기는 분위기는 아니라는 듯, 꽤나 까칠한 자세로 우리를 골탕 먹이려 함
// -> 우리가 구현한 복사 함수가 거의 확실히 틀렸을 경우에도 입을 다물어 버림

int main() 
{

}


