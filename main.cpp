#include<iostream>

// Effective C++
// 4. 설계 및 선언
// 항목 18: 인터페이스 설계는 제대로 쓰기엔 쉽게, 엉터리로 쓰기엔 어렵게 하자

// '제대로 쓰기에 쉽고 엉터리로 쓰기에 어려운' 인터페이스를 개발하려면 우선 사용자가 저지를 만한 실수의 종류를 머리에 넣어두고 있어야 함
// 예시: 날짜를 나타내는 어떤 클래스에 넣을 생성자를 설계하고 있다고 가정하자
class Date {
public:
  Date(int month, int day, int year);
  ...
};
// 첫인상이 그리 고약하지 않은 인터페이스임
// 별 문제는 없을 것 같음(최소한 미합중국에서는 말임)
// 그런데 여기에는 사용자가 쉽게 저지를 수 있는 오류 구멍이 적어도 두 개나 나 있음
// 우선 매개변수의 전달 순서가 잘못될 여지가 열려 있는 것이 첫 번쨰임
Date d(30, 3, 1995);                                                    // 허걱! "3, 30"이어야 하는데 "30, 3"을 넣음
// 두 번째는 월과 일이 해당하는 숫자가 어이없는 숫자일 수 있음
Date d(3, 40, 1995);                                                    // 쩝, "3, 30"이어야 하는데 "3, 40"을 넣음
// (마지막 예제로 든 코드는 사실 어이없어 보일 수 있겠지만, 키보드에서 3 옆에 4가 있다는 점을 떠올려 보념 꼭 그런 것은 아님.
//  키를 처다 보면 '하나 살짝 비껴가는' 타자 실수는 드물지 않음)

// 새로운 타임을 들여와 인터페이스를 강화하면 상당수의 사용자 실수를 막을 수 있음
// 살다 보면 몸으로 느끼겠지만, 어처구니없는 코드가 컴파일되는 부조리로부터 우리를 지켜주는 오른팔이 바로 타입 시스템임
// 지금의 경우, 일, 월, 연을 구분하는 간단한 랩퍼(wrapper) 타입을 각각 만들고 이 타입을 Date 생성자 안에 둘 수 있을 것임
struct Day {
  explicit Day(int d)
    : val(d) {}
  int val;
};

struct Month {
  explicit Month(int m)
    : val(m) {}
  int val;
};

struct Year {
  explicit Year(int y)
    : val(y) {}
  int val;
};

class Date {
public:
  Date(const Month& m, const Day& d, const Year& y);
  ...
};

int main() 
{
  Date d(30, 3, 1995);                                                  // 에러! 타입이 틀림

  Date d(Day(30), Month(3), Year(1995));                                // 에러! 타입이 틀림

  Date d(Month(3), Day(30), Year(1995));                                // 옳지, 타입이 전부 맞음
}
// 물론, Day 및 Month, Year에 데이터를 이것저것 숨겨 넣어 제몫을 하는 온전한 클래스로 만들면 위의 단순한 구조체보다는 확실히 낫긴 하겠지만(항목 22 참조),
// 타입을 적절히 새로 준비해 두지만 해도 인터페이스 사용 에러를 막는 데는 약발이 통한다는 점을 보여주기에는 이 정도도 충분함

// 일단 적절한 타입만 제대로 준비되어 있으면, 각 타입의 값에 제약을 가하더라도 괜찮은 경우가 생기게 됨
// 예를 들어 월(月)이 가질 수 있는 유효한 값은 12개뿐이므로, Month 타입은 이 사실을 제약으로 사용할 수 있음


