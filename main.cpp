#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 15: 자원 관리 클래스에서 관리되는 자원은 외부에서 접근할 수 있도록 하자

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
// 그렇다고 마냥 좋은 것은 아님. 암시적 변환이 들어가면 실수를 저지를 여지가 많아짐
// 진짜 Font를 쓰려고 한 부분에서 원하지도 않았는데 FontHandle로 덜커덕 바뀔 수 있음

Font f1(getFont());

FontHandle f2 = f1;                                               // 허걱! 원래 의도는 Font 객체를
                                                                  // 복사하는 것이었는데, 엉뚱하게도
                                                                  // f1이 FontHandle로 바뀌고 나서
                                                                  // 복사되어 버림
// 이렇게 되면 Font 객체인 f1이 관리하고 있는 폰트(FontHandle)rk f2를 통해서도 직접 사용할 수 있는 상태가 됨
// 하나의 자원이 양다리를 걸치고 있는 이와 같은 상황은 좋지 않음
// f1이 소멸될 시점을 생각해 보자
// 당연히 폰트가 해제될 텐데, 그럼 f2는 해제된 폰트에 달랑달랑 매달려 있는 꼴이 됨...

int main() 
{

}



