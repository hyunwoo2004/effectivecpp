#include<iostream>

// Effective C++
// 2. 생성자, 소멸자 및 대입 연산자
// 항목 11: operator=에서는 자기대입에 대한 처리가 빠지지 않도록 하자

// 다행히도 operator=을 예외에서 안전하게 구현하면 대개 자기대입에도 안전한 코드가 나오게 되어 있음
// 즉, 예외 안전성에만 집중하면 자기대입 문제는 무시하더라도 무사히 넘어갈 확률이 높아짐!
//   일단 이번 항목에서는 "많은 경우에 문장 순서를 세심하게 바꾸는 것만으로 예외를 안전한(+자기대입에 안전한) 코드가 만들어진다"
// 라는 법칙 한 가지를 여기서 써보자
// 해결법
Widget& operator=(const Widget& rhs)
{
  Bitmap* pOrig = pb;                      // 원래의 pb를 어딘가에 기억해 두자
  pb = new Bitmap(*rhs.pb);                // 다음, pb가 *pb의 사본을 가리키게 만듦
  delete pOrig;                            // 원래의 pb를 삭제함

  return *this;
}

int main() 
{

}


