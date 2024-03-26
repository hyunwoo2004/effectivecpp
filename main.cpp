#include<iostream>

// Effective C++
// 4. 설계 및 선언
// 항목 18: 인터페이스 설계는 제대로 쓰기엔 쉽게, 엉터리로 쓰기엔 어렵게 하자

// tr1::shared_ptr의 '그' 생성자는 첫 번째 매개변수로 포인터로 받아야 함
// 그런데 0은 포인터가 아니라 int임 - 물론 0은 포인터로 변환할 수 있지만 지금의 경우에는 이것만으로 부족함
// -> tr1::shared_ptr이 요구하는 포인터는 Investment* 타입의 실제 포인터이기 떄문임
// 그래서 캐스트를 적용하여 사태를 해결함

std::tr1::shared_ptr<Investment>                      // getRidOfInvestment를 삭제자로
  pInv( static_cast<Invest*>(0),                      // 갖는 널 shared_ptr을 생성함
        getRidOfInvestment);                          // 여기서 쓰인 static_cast애 대한
                                                      // 설명은 항목 27에서 확인하자!

// 이제는 createInvestment 함수에서 getRidOfInvestment를 삭제자로 갖는 tr1::shared_ptr을 반환하도록 구현하는 방법이 어렴풋이 정리할 수 있음
// 아마 다음 코드와 비슷할 거임

std::tr1::shared_ptr<Investment> createInvestment()
{
  std::tr1::shared_ptr<Investment> retVal(static_cast<Investment>(0),
                                          getRidOfInvestment());
  retVal = ... ;                                      // retVal은 실제 객체를 가리키도록
                                                      // 만들자!
  return retVal;
}

// 눈치 채신 사람도 있겠지만, retVal로 관리할 실제 객체의 포인터를 결정하는 시점이 retVal을 생성하는 시점보다 앞설 수 있으면, 위의 코드처럼
// retVal을 널로 초기화하고 나서 나중에 대입하는 방법보다 실제 객체의 포인터를 바로 retVal의 생성자에 넘겨버리는 게 나음
// 이유가 궁금하다면 항목 26을 참고하자

int main() 
{
}


