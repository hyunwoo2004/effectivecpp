#include<iostream>

// 선언(declaration)
extern int x; // 객체 선언
std::size_t numDigits(int num); // 함수 선언
class Widget; // 클래스 선언
template<typename T> // 템플릿 선언
class GrapNode; 

// 정의(definition) 
int x; // 객체 정의
std::size_t numDigits(int num) { // 함수 정의
	std::size_t digitsSoFar = 1;

	while ((num /= 10) != 0) ++digitsSoFar;
	return digitsSoFar;
}
class Widget { // 클래스 정의
public:
	Widget();
	~Widget();
};
template<typename T> // 템플릿 정의
class GrapNode {
public:
	GrapNode();
	~GrapNode();
};

int main() {
	
}
