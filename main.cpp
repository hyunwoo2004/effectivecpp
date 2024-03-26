#include<iostream>

// Effective C++
// 4. 설계 및 선언
// 항목 18: 인터페이스 설계는 제대로 쓰기엔 쉽게, 엉터리로 쓰기엔 어렵게 하자

// tr1::shared_ptr에는 엄청 좋은 특징이 하나 있음
// 바로 포인터별(per-pointer) 삭제자를 자동으로 씀으로써 사용자가 저지를 수 있는 또 하나의 잘못을 미연에 없애 준다는 점인데,
// 이 또 하나의 잘못이란 바로 '교차 DLL 문제(cross-DLL problem)'임
// 이 문제가 생기는 경우가 언제냐 하면, 객체 생성 시에 어떤 동적 링크 라이브러리(dynamically linked library: DLL)의 new를 썼는데
// 그 객체를 삭제할 떄는 이전의 DLL과 다른 DLL에 있는 delete을 썼을 경우임
// 이렇게 new/delete 짝이 실행되는 DLL이 달라서 꼬이게 되면 대다수의 플랫폼에서 런타임 에러가 일어남
// 그런데 tr1::shared_ptr은 이 문제를 피할 수 있음

int main() 
{
}


