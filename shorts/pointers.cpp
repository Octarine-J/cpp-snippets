#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::string;

// passing a smart pointer to a function and returning it
auto print_len(std::shared_ptr<string> s) -> decltype(s) {
  cout << "length = " << s->length() << endl;  // dereferencing a smart pointer
  return s;
}

int main() {
  // declaring a pointer
  int a = 10;
  int* pa = &a;
  int*& ref = pa;  // a reference to a pointer
  
  // a void* pointer can point to any type
  void* pv = &a;

  // printing a pointer
  cout << (void*)pa << endl;

  // C++11: a unique pointer to int
  // cannot be copied (including passing to a function?)
  auto pi = std::make_unique<double>(3.1415926);
  cout << *pi << endl;

  // C++11: a shared pointer to string
  auto ps = std::make_shared<string>("test");
  print_len(ps);
  
  // C++17: can use shared_ptr with arrays
  std::shared_ptr<int[]> arr(new int[10]);
  cout << arr[0] << endl;

  return 0;
}
