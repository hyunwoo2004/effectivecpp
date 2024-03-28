#include<iostream>

// Effective C++
// 4. 설계 및 선언
// 항목 20: '값에 의한 전달'보다는 '상수객체 참조자'방식을 택하는 편이 대개 낫다

// 확실한 것부터 뽑자
// plato로부터 매개변수 s를 초기화시키기 위해 Student의 복사 생성자가 호출될 거임. 게다가 s는 validateStudent가 복귀할 때 소멸될 거임
// 이 함수의 매개변수 전달 비용은 Student의 복사 생성자 호출 한 번, 그리고 Student의 소멸자 호출 한 번임

// 이야기가 이렇게 끝나면 얼마나 큰 기쁨이겠습니까만, 끝나려면 좀 멀었음
// Student 객체에는 string 객체 두 개다 멤버로 들어가 있기 때문에, Student 객체가 생성될 때마다 이들 string 형제도 덩달아 생성이 되어야 함
// 게다가 Student 객체는 Person 객체로부터 파생되었기 때문에, Student 객제가 생성되면 Person 객체도 (먼저) 생성되어야 함

int main() 
{

} 




