#include <iostream>
#include <string>

class Person {
 public:
  Person(const std::string& name = "", int age = 0)
      : m_name{name}, m_age{age} {
  }
  const std::string& getName() const { return m_name; }
  int getAge() const { return m_age; }

 private:
  std::string m_name;
  int m_age{};
};

class BaseballPlayer : public Person {
 public:
  BaseballPlayer(const std::string& name = "", int age = 0,
                 double battingAverage = 0.0, int homeRuns = 0)
      : Person{name, age},  // call Person(const std::string&, int) to initialize these fields
        m_battingAverage{battingAverage},
        m_homeRuns{homeRuns} {
  }

  double getBattingAverage() const { return m_battingAverage; }
  int getHomeRuns() const { return m_homeRuns; }

 private:
  double m_battingAverage{};
  int m_homeRuns{};
};

int main() {
  BaseballPlayer pedro{"Pedro Serrano", 32, 0.342, 42};
  std::cout << pedro.getName() << '\n';
  std::cout << pedro.getAge() << '\n';
  std::cout << pedro.getHomeRuns() << '\n';
  return 0;
}
