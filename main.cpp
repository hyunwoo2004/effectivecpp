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

// 위의 그림은 그냥 예제임. 컴파일러마다 꼭 저런 식으로 구현할 필요는 없음
// 사실 대다수의 경우에 그렇긴 함

// 어떤 포인터에 대해 delete를 적용할 때, delete 연산자로 하여금 '배열 크기 정보가 있다'는 것을 알려 줄 칼자루는 바로 우리에게 있음
// 우리가 입을 다물면 아무도 모름
// 이때 대괄호 쌍([])을 delete 뒤에 붙여 주는 것임
// 그제야 delete가 '포인터가 배열을 가리키고 있구나'라고 가정하게 됨
// 그렇지 않으면 그냥 단일 객체라고 간주하게 됨
// 예시
std::string* stringPtr1 = new std::string;

std::string* stringPtr2 = new std::string[100];

...

delete stringPtr1;                                            // 객체 한 개를 삭제함
delete[] stringPtr2;                                          // 객체의 배열을 삭제함
// stringPtr1에 '[]' 형태를 사용하면 어떤 일이 생기는가?
// 딱 정해진 것은 아니지만, 결과가 별로 아름답지 않을 것 같음

int main() 
{

}



