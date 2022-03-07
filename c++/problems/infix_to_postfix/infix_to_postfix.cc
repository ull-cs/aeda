#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char character) {
  if (character == '^') {
    return 3;
  } else if (character == '/' || character == '*') {
    return 2;
  } else if (character == '+' || character == '-') {
    return 1;
  } else {
    return -1;
  }
}

string infixToPostfix(string expression) {
  stack<char> stack;
  string result;
  for (int i = 0; i < expression.length(); i++) {
    char character = expression[i];
    if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z') || (character >= '0' && character <= '9')) {
      result += character;
    } else if (character == '(') {
      stack.push('(');
    } else if (character == ')') {
      while (stack.top() != '(') {
        result += stack.top();
        stack.pop();
      }
      stack.pop();
    } else {
      while (!stack.empty() && precedence(expression[i]) <= precedence(stack.top())) {
        result += stack.top();
        stack.pop();
      }
      stack.push(character);
    }
  }
  while (!stack.empty()) {
    result += stack.top();
    stack.pop();
  }
  return result;
}

int main(int argc, char *argv[]) {
  const std::string expression = argv[1];
  std::string postfixExpression = infixToPostfix(expression);
  cout << postfixExpression << endl;
  return 0;
}
