#include <iostream>
#include <stack>

using namespace std;

bool hasDuplicateParenthesis(string expression) {
  // take an empty stack of characters
  stack<char> stack;
  // traverse the input expression
  for (char character : expression) {
    cout << character << endl;
    // if the current char in the expression is not a closing parenthesis
    if (character != ')') {
      stack.push(character);
    }
    // if the current char in the expression is a closing parenthesis
    else {
      // if the stack's top element is an opening parenthesis, the subexpression of the form ((exp)) is found
      if (stack.top() == '(') {
        return true;
      }
      // pop till '(' is found for current ')'
      while (stack.top() != '(') {
        stack.pop();
      }
      // pop '('
      stack.pop();
    }
  }
  // if we reach here, then the expression does not have any duplicate parenthesis
  return false;
}

int main(int argc, char *argv[]) {
  const std::string expression = argv[1];
  if (hasDuplicateParenthesis(expression)) {
    cout << "Expression '" << expression << "' has duplicated parenthesis." << endl;
  } else {
    cout << "Expression '" << expression << "' does not have duplicated parenthesis." << endl;
  }
  return 0;
}
