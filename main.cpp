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

class Font {                                                  // RAII 클래스
public:
  explicit Font(FontHandle fh)                                // 자원을 획득함. 여기서
  : f(fh)                                                     // 값에 의한 전달이 수행되는 것에
  {}                                                          // 주의하자. 자원 해제를
  ~Font() { releaseFont(f); }                                 // C API로 하기 때문임

private:
  FontHandle f;                                               // 실제 폰트 자원
};
// 하부 수준 C API는 FontHandle을 사용하도록 만들어져 있으며 규모도 무척 크다고 가정하면,
// Font 객체를 FontHandle로 변환해야 할 경우도 적지 않을 것이라는 예상을 해 볼 수 있음
// Font 클래스에서는 이를 위한 명시적 변환 함수로 get을 제공할 수 있을 것임

class Font {                    
public:
  ...
  FontHandle get() const { return f; }                        // 명시적 변환 함수
  ...                                    
};
// 이렇게 해 부면 어쨌든 쓸 수 있긴 한데, 사용자는 하부 수준 API를 쓰고 싶을 때마다 get을 호출해야 함

int main() 
{

}



