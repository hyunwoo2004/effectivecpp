#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 13: 자원 관리에는 객체가 그만!

// auto_ptr 혹은 tr1::shared_ptr 등 스마트 포인터 이야기를 늘어놓으려고 이번 항목을 준비한 것은 아님
// 자원을 관리하는 객체를 써서 자원을 관리하는 것이 중요하다는 이야기가 진짜임
// auto_ptr과 tr1::shared_ptr(항목14, 18, 54 참고)은 그렇게 하는 여러 가지 방법들 중 몇 가지일 뿐임

// 알아둘 게 하나 더 있음 - auto_ptr 및 tr1::shared_ptr은 소멸자 내부에서 delete 연산자를 사용함
// delete[] 연산자가 아님! (delete와 delete[] 차이는 항목 16 참고)
// 말하자면, 동적으로 할당할 배열에 대해 auto_ptr이나 tr1::shared_ptr을 사용하면 대략 난감하다는 이야기임
// 동적 배열을 써도 컴파일 에러가 나지 않는게 문제
// 예시
int main() 
{
  std::auto_ptr<std::string>                           // 좋지 않은 발상임!
    aps(new std::string[10]);                          // 잘못된 delete가 사용됨
  
  std::tr1::shared_ptr<int> spi(new int[10]);          // 같은 문제가 발생
}



