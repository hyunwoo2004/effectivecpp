#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 16: new 및 delete를 사용할 떄는 형태를 반드시 맞추자

// 어려울 것 하나도 없음 - new 표현식에 []를 썼으면, 여기에 대응하는 delete 표현식에도 []을 써야한다는 아주 간단한 규칙임
// new 표현식에 []을 안썼으면 , 대응되는 delete 표현식에도 []을 안 쓰면 됨

// 동적 할당된 메모리에 대한 포인터를 멤버 데이터로 갖고 있는 클래스를 만드는 중이며 
// 이 클래스에서 제공하는 생성자도 여러 개일 경우에 특히 이 규칙을 뼈속 깊이 간직하자!
// 이유는 포인터 멤버를 초기화하는 부분인 생성자에서 new 형태를 똑같이 맞출 수 밖에 없기 때문임
// 이렇게 하지 않는다면, 소멸자에서 어떤 형태의 delete를 써야 할 지 어떻게 알겠는가?

// 이 규칙은 typedef 애호가들도 알아둘 가치가 있음
// typedef로 정의된 어떤 타입의 객체(배열)을 메모리에 생성라혀고 new를 썼을 때,
// 나중에 어떤 형태의 delete를 적어줘야 하는가에 대한 언급을 달아주는 책임을 해당 typedef 타입의 작성자가 져야 한다고 압박을 가하는 의미로 볼 수 있음
// 예시: 어떤 typedef 타입이 다음과 같이 되어 있다고 가정
typedef std::string AddressLines[4];                                        // 주소는 네 줄로 되어 있고 
                                                                            // 각각은 string임
// AddressLines는 보다시피 배열임. 따라서 아래처럼 new를 사용하면
std::string* pal = new AddressLines;                                        // "new AddressLines"는 string*을
                                                                            // 반환한다는 점을 잊으면 안됨
                                                                            // "new string[4]"이기 때문

int main() 
{

}



