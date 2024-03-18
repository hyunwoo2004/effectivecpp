#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 13: 자원 관리에는 객체가 그만!

// 이번 항목에서 "자원 관리에 객체를 쓰자"라는 지침을 통해 필자가 강조하고 싶은 바는 이것임
// -> 자원 해제를 우리가 일일이 하다 보면 언젠가 잘못을 저지르고 만다는 이야기임
// 이미 널리 쓰이고 있는 auto_ptr이나 tr1::shared_ptr 같은 자원 관리 클래스를 
// 활용하는 것도 이번 항목의 조언을 쉽게 지킬 수 있는 한 가지 방법임
// 다만 이런 클래스로도 제대로 관리할 수 없는 자원도 있다는 사실은 잊지 말자
// 이런 경우엔 우리만의 자원 관리 클래스를 직접 만들 수 밖에 없음 - 이 클래스를 만들 떄는 각별히 신경쓰자!
// 이런저런 고혀 사항은 항목 14 및 15을 각각 참고하자!

int main() 
{

}
