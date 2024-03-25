#include<iostream>

// Effective C++
// 4. 설계 및 선언
// 항목 18: 인터페이스 설계는 제대로 쓰기엔 쉽게, 엉터리로 쓰기엔 어렵게 하자

// 일단 적절한 타입만 제대로 준비되어 있으면, 각 타입의 값에 제약을 가하더라도 괜찮은 경우가 생기게 됨
// 예를 들어 월(月)이 가질 수 있는 유효한 값은 12개뿐이므로, Month 타입은 이 사실을 제약으로 사용할 수 있음
// 한 가지 방법으로 월 표시 값을 나타내는 enum을 넣는 방법이 있는데 enum은 수많은 프로그래머의 용감하고 씩씩한 친구로서 시대를 풍미하고 있긴 하지만
// 타입 안전성은 그리 믿음직하지 못함
// 때로는 int처럼 쓰일 수 있다는 사실을 이미 본 바 있음(항목 2 참조)
// 타입 안전성이 신경 쓰인다면 유효한 Month의 집합을 미리 정의해 두어도 괜찮음
class Month {
public:
  static Month Jan() { return Month(1); }                    // 유효한 Month 값을 반환하는 함수들.
  static Month Feb() { return Month(2); }                    // 이들이 어쨰서 함수로 되어 있으며
  ...                                                        // 객체가 되면 안 되는지에 대한
  static Month Dec() { return Month(12); }                   // 이야기는 아래를 보시면 있음.

  ...                                                        // 다른 멤버 함수들
private:
  explicit Month(int m);                                     // Month 값이 새로 생성되지 않도록
                                                             // 명시호출 생성자가 private 멤버임.

  ...                                                        // 월 표현을 위한 내부 데이터
};

Date d(Month::Mar(), Day(30), Year(1995));

int main() 
{
}


