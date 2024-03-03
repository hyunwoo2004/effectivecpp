#include<iostream>

class Widget {
public:
	Widget();	// 기본 생성자(default ctor)
	Widget(const Widget& rhs); // 복사 생성자
	Widget& operator=(const Widget& rhs); // 복사 할당(대입) 연산자(copy assignment operator)
};

Widget::Widget() 
{ 
	std::cout << "default ctor" << '\n'; 
}

Widget::Widget(const Widget& rhs) 
{ 
	std::cout << "copy ctor" << '\n'; 
}

Widget& Widget::operator=(const Widget& rhs) 
{ 
	std::cout << "copy assignment operator" << '\n'; return *this; 
}


void dosomething(Widget w) 
{ 
	std::cout << "doing somthing with Widget Object" << '\n'; 
}

int main() {
	Widget w1;

	dosomething(w1); // 값의 의한 전달(pass-by-value) == 복사 생성자 호출(copy ctor calls)
}

