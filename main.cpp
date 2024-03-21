#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 15: 자원 관리 클래스에서 관리되는 자원은 외부에서 접근할 수 있도록 하자

// 변환할 때마다 무슨 함수를 호출해 주어야 한다는 점이 짜증나서 Font 클래스를 안 쓰고 말겠다는 프로그래머도 분명히 나오게 됨.
// 이것 때문에 폰트 자원이 누출될 가능성이 늘어난다면 그것만큼 애석한 일도 없음
// Font 클래스를 설계한 가장 큰 목적이 폰트 자원의 누출을 막는 것임...

// 대안이 없는 것은 아님
// FontHandle로의 암시적 변환 함수를 Font에서 제공하도록 하면 됨
class Font {                    
public:
  ...
  operator FontHandle() const                                     // 암시적 변환 함수
  { return f; }
  ...                                    
};
// 암시적 변환 함수 덕택에 C API를 사용하기가 훨씬 쉬워지고 자연스러워짐
Font f(getFont());
int newFontSize;
...

changeFontSize(f, newFontSize);                                   // Font에서 FontHandle로
                                                                  // 암시적 변환을 수행함

int main() 
{

}



