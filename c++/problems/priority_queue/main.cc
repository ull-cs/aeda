#include <stdlib.h>

#include <iostream>

#include "priority_queue.h"

using namespace std;

const std::string kHelpText = "Este programa toma como parámetro un número y crea una cola de prioridad con dicho número de elementos y prioridades aleatorias para luego vaciarla";

void Usage(int argc, char* argv[]) {
  if (argc == 2) {
    std::string parameter{argv[1]};
    if (parameter == "--help") {
      std::cout << kHelpText << std::endl;
      exit(EXIT_FAILURE);
    }
  } else {
    std::cout << "El programa requiere un parámetro." << std::endl;
    std::cout << "Modo de uso:" << std::endl;
    std::cout << argv[0] << " NUMERO" << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_FAILURE);
  }
}

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  const int kElements = stoi(argv[1]);
  srand(time(NULL));
  PriorityQueue queue;
  for (int i = 0; i < kElements; i++) {
    const int randomNumber = rand() % 100 + 1;
    const int randomPriority = rand() % 10 + 1;
    queue.enqueue(randomNumber, randomPriority);
    cout << randomNumber << " with priority " << randomPriority << " has been queued" << endl;
  }
  cout << "Elements present in queue: " << endl;
  while (!queue.isEmpty()) {
    const int element = queue.peek();
    cout << element << " has the highest priority" << endl;
    queue.dequeue();
  }
  return 0;
}
