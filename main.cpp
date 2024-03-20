#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 15: 자원 관리 클래스에서 관리되는 자원은 외부에서 접근할 수 있도록 하자

// RAII 객체 안에 들어 있는 실제 자원을 얻어낼 필요가 종종 생기기 때문에, RAII 클래스 설계자 중에는
// 암시적 변환 함수를 제공하여 자원 접근을 매끄럽게 할 수 있도록 만드는 사람도 있음
// 예시: 어떤 하부 수준 C API로 직접 조작이 가능한 폰트를 RAII 클래스로 둘러싸서 쓰는 경우를 생각해보자

FontHandle getFont();                                         // C API에서 가져온 함수 - 매개변수가
                                                              // 있으면 복잡하기 때문에 생략함

void releaseFont(FontHandle fh);                              // 역시 같은 C API에서 가져온 함수

int main() 
{

}



