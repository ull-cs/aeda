#include <iostream>

using namespace std;

class BaseCar {
 public:
  BaseCar() {};
  virtual void WhoAreYou() {
    cout << "I am BaseCar" << endl;
  };
};

class FirstModel : public BaseCar {
 public:
  FirstModel() {};
  virtual void WhoAreYou() {
    cout << "I am a FirstModel car" << endl;
  };
  void WhatIsYourHistory() {
    cout << "I am a child of the BaseCar" << endl;
  };
};

class SecondModel : public FirstModel {
 public:
  SecondModel() {};
  void WhoAreYou() {
    cout << "I am the SecondModel car" << endl;
  };
  void WhatIsYourHistory() {
    cout << "I am a child of the FirstModel car" << endl;
  };
  void HowAreYouBorn() {
    cout << "I am the grand child of the BaseCar" << endl;
  };
};

int main() {
  cout << "==================================================" << endl;
  cout << "Assertion from secondModel car" << endl;
  SecondModel* secondModelCar = new SecondModel;
  secondModelCar->WhoAreYou();
  secondModelCar->WhatIsYourHistory();
  secondModelCar->HowAreYouBorn();
  // The following conversion (upcasting) is permitted because firstDerivedCar is the direct base class
  FirstModel* firstModelCar = dynamic_cast<FirstModel*>(secondModelCar);
  cout << "==================================================" << endl;
  cout << "Assertion from second Model upcast to firstModel" << endl;
  firstModelCar->WhoAreYou();
  // The following conversion (upcasting) is also permitted because baseCar is the indirect base class in the hierarchy
  BaseCar* bCar = dynamic_cast<BaseCar*>(secondModelCar);
  cout << "==================================================" << endl;
  cout << "Assertion from second Model upcast to baseCar" << endl;
  bCar->WhoAreYou();
  // Create an object of the first derived class and assign to base class pointer (downcasting)
  FirstModel* firstModelPtr = new FirstModel;
  BaseCar* baseCarPtr = firstModelPtr;
  cout << "==================================================" << endl;
  cout << "Assertion from BaseCar pointing to first Model car" << endl;
  baseCarPtr->WhoAreYou();
  // The following method invokation is invalid; hence commented.
  // baseCarPtr->WhatIsYourHistory();
  // The following conversion (downcasting) is permitted
  // if the base class has virtual functions
  // CLX event handlers usually pass the base TObject pointer for the
  // Sender parameter. The appropriate (derived) object pointer may be
  // obtained by syntax similar to this.
  FirstModel* anotherFirstModel = dynamic_cast<FirstModel*>(baseCarPtr);
  cout << "==============================================" << endl;
  cout << "Assertion from BaseCar downcast to firstModel" << endl;
  cout << "Accessing both virtual and non-virtual methods" << endl;
  cout << "==============================================" << endl;
  anotherFirstModel->WhoAreYou();
  anotherFirstModel->WhatIsYourHistory();
  cout << "==============================================" << endl;
  // The following conversion is not permitted
  // because base2 does not point to derivedLast object
  // secondModel* anotherSecondModel = dynamic_cast<     //secondModel*>(baseCarPtr);
  // The following conversion is permitted, but we cannot execute the
  // methods of baseCarPtr using the vPtr. The vPtr should be     // converted back
  // to a firstModel or baseCare ptr, in order to make method calls.
  void* vPtr = dynamic_cast<void*>(baseCarPtr);
  return EXIT_SUCCESS;
}