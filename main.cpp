#include<iostream>
#include <list>

// Effective C++
// 1. C++에 왔으면 C++ 법을 따릅시다.
// 항목 4: 객체를 사용하기 전에 반드시 그 객체를 초기화하자

// 남은 걱정거리는 하나 
// 비지역 정적 객체의 초기화 순서는 개별 번역 단위에서 정해진다는 사실 
//        -> 별개의 번역 단위에서 정의된 비지역 정적 객체들의 초기화 순서는 정해지지 않는다
// 예제 - 인터넷에 있는 파일을 마치 로컬 컴퓨터에 있는 것처럼 보이게 하는 파일 시스템을 나타내는 FileSystem클래스
// 파일 1
class FileSystem {                  // 여러분의 라이브러리에 포함된 클래스
public:
  ...
  std::size_t numDisks() const;     // 많고 많은 멤버들 중 하나
  ...
};

extern FileSystem tfs;              // 사용자가 쓰게 될 객체
                                    // "tfs" = "the file system"
// FileSystem 객체가 그리 가볍지 않다는 점은 알것이기에 초기화되기 전에 사용하는 것은 대재앙일 것
//------------------------------------------------------------------------
// 파일 2
class Dictionary {                     // 라이브러리의 사용자가 만든 클래스
public:
  Dictionary( params );
  ...
};

Dictionary::Dictionary( params )
{
  ...
  std::size_t disks = tfs.numDisks();  // tfs 객체를 여기서 사용함
  ...
}
// + 만약 사용자가 Dictionary 클래스를 사용해서 임시 파일을 담는 디렉토리 객체 하나를 생성하기로 함
Dictionary tempDir( params );          // 임시 파일을 담는 디렉토리
//------------------------------------------------------------------------
// 정적 객체의 초기화 순서 때문에 문제가 심각해질 수 있는 상황
//   tfs가 tempDir보다 먼저 초기화되지 않으면, tempDir의 생성자는 
// tfs가 초기화되지도 않았는데 tfs를 사용하려고 할 것임
// 그러나 tfs와 tempDir은 제작자도 다르고 만들어진 시기도 다른데다가 소재지(소스 파일)도 다름 
// -> 다른 번역 단위 안에서 정의된 비지역 정적 객체임.
// 그러면 tempDir 전에 tfs가 초기화되게 만드는 방법이 있을까?




int main() {

} 

