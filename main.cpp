#include<iostream>
#include <list>

// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 4: 객체를 사용하기 전에 반드시 그 객체를 초기화하자

// 아까의 방법으로 적용한 tfs와 tempDir의 결과
class FileSystem {};                // 이전과 다를 것 없는 클래스

FileSystem& tfs()                   // tfs 객체를 이 함수로 대신함. 이 함수는
{                                   // 클래스 안에 정적 멤버로 들어가도 됨
  
  static FileSystem fs;             // 지역 정적 객체를 정의하고 초기화합니다.
  return fs;                        // 이 객체에 대한 참조자를 반환함
}
//------------------------------------------------------------------------------
// 파일 2
class Dictionary {                     // 역시 이전과 다를 것 없는 클래스
public:
  Dictionary( params );
  ...
};

Dictionary::Dictionary( params )       // 이전과 동일합니다. tfs의 참조자였던 것이
{                                      // 지금은 tfs()로 바뀐 것만 다름
  ...
  std::size_t disks = tfs().numDisks(); 
  ...
}

Dictionary& tempDir( )                 // tenoDir 객체를 이 함수로 대신함. 이 함수는
{                                      // Dictionary 클래스의 정적 멤버로 들어가도 됨
 
  static Dictionary td;                // 지역 정적 객체를 정의/초기화함
  return td;                           // 이 객체에 대한 참조자를 반환함
}  
//------------------------------------------------------------------------------
int main() {

} 

