#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 12: 객체의 모든 부분을 빠짐없이 복사하자

// 서론
// 프로그래밍 분야에서 자원(resource)이란, 사용을 일단 마치고 난 후엔 시스템에 돌려주어야 하는 모든 것을 일컫음
// 돌려주지 않은 순간부터 암울한 일들이 뽀송뽀송 피어나기 시작할 것임
// C++ 프로그램에서 가장 흔하게 눈에 밝히는 자원이라면 동적 할당한 메모리를 들 수 있는데 
// -> 사실 메모리는 여러분이 관리해야 하는 많고 많은 자원 중 한가지일 뿐임
// 자원에는 파일 서술자 (file descriptor), 뮤텍스 잠금 (mutex lock)
// 그래픽 유저 인터페이스(GUI: Graphical User Interface)에서 쓰이는 폰트(font)와 브러시(brush)
// 이들 모두 자원에 해당됨 (뿐만 아니라 데이터베이스 연결, 네트워크 소켓도 자원에 해당함)


int main() 
{

}


