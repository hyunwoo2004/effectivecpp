#include<iostream>

// Effective C++
// 3. 자원 관리
// 항목 16: new 및 delete를 사용할 떄는 형태를 반드시 맞추자

// 아래에 적어 놓은 것에서 뭔가 잘못된 점이 보이는가?
std::string* stringArray = new std::string[100];
...
delete stringArray;                                                 // ???
// 하늘을 우러러 한 점 부끄럼 없을 코드 같음 - 가장 신경 쓰이는 new와 delete가 짝이 맞아 있음
// 하지만 분명히 부끄럼이 한 점, 그것도 대박으로 있으니 어떻해야 하나?

int main() 
{

}



