#include <iostream>
#include <string>

class Person {
 public:
  Person(const std::string& name = "", int age = 0)
      : name_{name}, age_{age} {
  }
  const std::string& getName() const { return name_; }
  int getAge() const { return age_; }

 private:
  std::string name_;
  int age_{};
};

class BaseballPlayer : public Person {
 public:
  BaseballPlayer(const std::string& name = "", int age = 0,
                 double battingAverage = 0.0, int homeRuns = 0)
      : Person{name, age},  // call Person(const std::string&, int) to initialize these fields
        battingAverage_{battingAverage},
        homeRuns_{homeRuns} {
  }

  double getBattingAverage() const { return battingAverage_; }
  int getHomeRuns() const { return homeRuns_; }

 private:
  double battingAverage_{};
  int homeRuns_{};
};

int main() {
  BaseballPlayer pedro{"Pedro Serrano", 32, 0.342, 42};
  std::cout << pedro.getName() << '\n';
  std::cout << pedro.getAge() << '\n';
  std::cout << pedro.getHomeRuns() << '\n';
  return 0;
}
