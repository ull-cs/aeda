#include <iostream>

using namespace std;

struct MyException : public std::exception {
  const char* what() const throw() {
    return "C++ Exception";
  }
};

int main() {
  try {
    throw MyException();
  } catch (MyException& exception) {
    std::cout << "MyException caught" << std::endl;
    std::cout << exception.what() << std::endl;
  } catch (std::exception& exception) {
    std::cerr << "Other exception caught" << std::endl;
  }
}