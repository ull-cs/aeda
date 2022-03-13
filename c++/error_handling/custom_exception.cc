#include <exception>
#include <iostream>

using namespace std;

class MyException : public std::exception {
 public:
  MyException(const char* msg, const char* file, int line, const char* function) : std::exception(),
                                                                                   msg_(msg),
                                                                                   file_(file),
                                                                                   function_(function),
                                                                                   line_(line) {}

  const char* file() const {
    return file_;
  }
  int line() const {
    return line_;
  }
  const char* function() const {
    return function_;
  }
  const char* msg() const {
    return msg_;
  }

 private:
  const char* file_;
  int line_;
  const char* function_;
  const char* msg_;
};

void SomeFunction() {
  throw MyException("Exception thrown by SomeFunction", "customer_exception.cc", 35, "SomeFunction");
}

int main() {
  try {
    SomeFunction();
  } catch (MyException& exception) {
    std::cout << exception.what() << std::endl;
    std::cout << "File: " << exception.file() << std::endl;
    std::cout << "Function: " << exception.function() << std::endl;
    std::cout << "Line: " << exception.line() << std::endl;
    std::cout << "Message: " << exception.msg() << std::endl;
  }
  return 0;
}
