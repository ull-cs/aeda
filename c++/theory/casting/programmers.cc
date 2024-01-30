#include <iostream>

using namespace std;

class Employee {
 public:
  void ShowId() {
    cout << "Id: " << id << endl;
  }

 private:
  int id;
};

class Programmer : public Employee {
 public:
  void Coding() {
      cout << "I know how to code in C++"  << endl;
  }
};

int main() {
  Employee employee;
  Programmer programmer;
  // upcast - implicit upcast allowed
  Employee *pEmp = &programmer;
  // downcast - explicit type cast required
  Programmer *pProg = (Programmer *)&employee;
  // Upcasting: safe - progrommer is an Employee and has his id to do show_id().
  pEmp->ShowId();
  pProg->ShowId();
  // Downcasting: unsafe - Employee does not have the method, coding().
  // compile error: 'coding' : is not a member of 'Employee'
  // pEmp->Coding();
  pProg->Coding();
  return 0;
}