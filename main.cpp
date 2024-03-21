#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 16: new 및 delete를 사용할 떄는 형태를 반드시 맞추자

// 아래에 적어 놓은 것에서 뭔가 잘못된 점이 보이는가?
std::string* stringArray = new std::string[100];
...
delete stringArray;

int main() 
{

}



