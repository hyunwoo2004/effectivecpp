#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 6: 컴파일러가 만들어낸 함수가 필요 없으면 확실히 이들의 사용을 금해 버리자

// 이걸 해결하려면 어떻게 해야 하는 가?
// 2. private에 선언한다.
// 이 경우라면 막을 수는 있음
class HomeForSale {
  public:
  ...
  private:
  ...
  HomeForSale(const HomeForSale&);  // 선언만 달랑 있음
  HomForSale& operator=(const HomeForSale&);
};
// 단점: private 멤버 함수는 그 클래스의 멤버 함수 밎 프렌드(friend) 함수가 호출 가능함
// 그래서 선언만 하고 정의(define)를 안 함 - 이려면 실수로 호출해도 링크 시점에서 에러를 낼 수 있음
// 이 꼼수는 하나의 '기법'으로 굳어진적 있음(iostream 라이브러리에 속한 몇몇 클래스에서도 방지책으로 사용함)

int main() {

} 

