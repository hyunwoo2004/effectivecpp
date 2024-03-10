#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 6: 컴파일러가 만들어낸 함수가 필요 없으면 확실히 이들의 사용을 금해 버리자

// 이걸 해결하려면 어떻게 해야 하는가?
// 2. private에 선언한다.
// + 링크 시점 오류에서 컴파일 시점 오류로 바꿀 수 있음
// 별도의 클래스에서 복사 생성자/대입 연산자를 private에 선언하고 이를 상속받으면 됨
// 예시
class Uncopyable {
protected:                                  // 파생된 객체에 대해서
  Uncopyable();                             // 생성과 소멸을
  ~Uncopyable();                            // 허용함

private:
  Uncopyable(const Uncopyable&);            // 하지만 복사는 방지함
  Uncopyable& operator=(const Uncopyable&);
};

class HomeForSale : private Uncopyable {    // 복사 생성자도,
  ...                                       // 복사 대입 연산자도
};                                          // 이제는 선언되지 않음
// 원하는 바를 깔끔하게 만든 코드


int main() {

} 

