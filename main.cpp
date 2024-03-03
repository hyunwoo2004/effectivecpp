#include <iostream>

// C++ STL(Standard Template Library)
// 구성요소
// - 컨테이너(container)
// - 반복자(iterator)
// - 알고리즘(algorithm)
// + 함수 객체(function objection)

class A { // 함수 객체의 기본 구성
public:
	void operator()(int n)
	{ 
		std::cout << "데이터 - " << n << "을 처리함" << '\n';
	}
};

int main() {
	std::vector<int> vec{1,4,3,2,5}; // container
	
	for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) // iterator
		std::cout << *itr << ' ';
	std::cout << '\n';

	std::sort(vec.begin(), vec.end()); // algorithm

	A a;
	a(3); // function object
}
