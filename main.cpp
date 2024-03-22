#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 16: new 및 delete를 사용할 떄는 형태를 반드시 맞추자

// 질문이 좀 복잡할 수도 있어 좀 풀어서 말하겠음 -> 삭제되는 포인터는 객체 하나만 가리키는가? 아니면 객체의 배열을 가리키는가?
// 이것이 진짜 핵심인데, 왜냐하면 (new로 힙에 만들어진) '단일 객체'의 메모리 배치구조(layout)는 '객체 배열'에 대한 메모리 구조'와 다르기 때문임
// 특히, 배열을 위해 만들어지는 힙 메모리에는 대개 배열원소의 개수가 박혀 들어간다는 검이 가장 결정적인데,
// 이 떄문에 delete 연산자는 소멸자가 몇번 호출될지를 쉽게 알 수 있음
// 반면, 단일 객체용 힙 메모리는 이런 정보가 없음
// 배체구조가 다르다는 말뜻은 다음과 같이 생각하면 됨 ( 여기서 n은 배열의 크기(원소의 개수)임 )

// 한 개의   [   Object   ]
// 객체      [            ]

// 객체의    [  n  |   Object   |   Object   |   Object   |   ...   ]
// 배열      [     |            |            |            |         ]

int main() 
{

}



