#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Function to generate binary numbers between 1 and `n` using the queue data structure
void BinaryNumbers(int numbers) {
  queue<string> queue;
  queue.push("1");
  int i = 1;
  while (i <= numbers) {
    // append 0 and 1 to the front element of the queue and enqueue both strings
    queue.push(queue.front() + "0");
    queue.push(queue.front() + "1");
    // dequeue front element after printing it
    cout << queue.front() << ' ';
    queue.pop();
    i++;
  }
}

int main(int argc, char *argv[]) {
  const int kNumbers = stoi(argv[1]);
  BinaryNumbers(kNumbers);
  return 0;
}
