#include <iostream>
#include <string>

struct User {
  std::string name;
  std::string surname;
  int age;
};

void PrintUser(const User& user) {
  std::cout << "Name=" << user.name << ", ";
  std::cout << "surname=" << user.surname << ", ";
  std::cout << "age= " << user.age;
  std::cout << std::endl;
}

int main() {
  User user1{"Antonio", "Pérez", 27};
  PrintUser(user1);
  User user2;
  user2.name = "Juana";
  user2.surname = "Moreno";
  user2.age = 31;
  PrintUser(user2);
  PrintUser({"Luisa", "Acosta", 24});
  return 0;
}
