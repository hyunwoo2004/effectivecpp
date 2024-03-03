#include<iostream>

// 초기화(initialization)
class A {
public:
	A() {} // 기본 생성자(default constructor)
};

class B {
public:
	explicit B(int n = 0, bool b = true) {} // 기본 생성자(default constructor)
};

class C {
public:
	explicit C(int x) {} // 기본 생성자 아님
};

void dosomething(B bObject) {}

int main() {
	B bObj1;
	dosomething(bObj1); // 문제 없는 코드
	
	B bobj2(28);	// 괜찮은 코드, x인자가 0대신 28이 들어감 (bool은 그대로 true가 들어감)
	dosomething(28);	//컴파일 에러! -> int에서 B로 전환활 생성자가 없음.
				// >>> 다른 자료형으로의 암시적인 변환을 막는 키워드 - explicit

	dosomething(B(28)); // 괜찮은 코드 int -> B로 명시적인 변환을 함!
}
