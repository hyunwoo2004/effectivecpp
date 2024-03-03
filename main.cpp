#include<iostream>

// 미정의 동작(undefined behavior) <대표적으로>
// 1. null pointer를 역참조(*)할 때
// 2. 유효하지 않은 배열의 원소지정 번호를 참조하려 할 때
//	-> 미정의 동작은 매우 위험하므로 하지 않도록 주의하자!

int main() {
	int* p = nullptr; // p는 nullptr이다.
	std::cout << *p; // 경우 1
	
	char name[] = "Darla"; // 배열의 범위: 0 ~ 5

	char c = name[10]; // 경우 2
}
