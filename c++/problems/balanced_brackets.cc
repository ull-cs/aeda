#include <bits/stdc++.h>

using namespace std;

bool areBracketsBalanced(string expression) {
  stack<char> stack;
  char toCheck;
  for (int i = 0; i < expression.length(); i++) {
	char character = expression[i];
    if (character == '(' || character == '[' || character == '{') {
      stack.push(character);
      continue;
    }
    if (stack.empty()) {
      return false;
    }
    switch (character) {
      case ')':
        toCheck = stack.top();
        stack.pop();
        if (toCheck == '{' || toCheck == '[') {
          return false;
		}
        break;
      case '}':
        toCheck = stack.top();
        stack.pop();
        if (toCheck == '(' || toCheck == '[') {
          return false;
		}
        break;
      case ']':
        toCheck = stack.top();
        stack.pop();
        if (toCheck == '(' || toCheck == '{') {
          return false;
		}
        break;
    }
  }
  return (stack.empty());
}

int main(int argc, char *argv[]) {
  const std::string expression = argv[1];
  if (areBracketsBalanced(expression)) {
    cout << "Expression is balanced" << endl;
  } else {
    cout << "Expression is not balanced" << endl;
  }
  return 0;
}
