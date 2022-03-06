#include <stdlib.h>

#include <iostream>

#include "associationlist.h"
#include "pair.h"

using namespace std;

const std::string kHelpText = "Este programa toma como parámetro un número y crea una cola con dicho número de elementos para luego vaciarla";

void Usage(int argc, char *argv[]) {
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

int main(int argc, char *argv[]) {
  Usage(argc, argv);
  const int kElements = stoi(argv[1]);
  srand(time(NULL));
  AssociationList<Pair<int>> list;
  for (int i = 0; i < kElements; i++) {
    const int randomNumber1 = rand() % 10 + 1;
    const int randomNumber2 = rand() % 100 + 1;
    Pair<int> pair(randomNumber1, randomNumber2);
    list.add(pair);
    cout << pair << " has been added" << endl;
  }
  cout << "Elements present in list: ";
  list.displayAll();
  return 0;
}
