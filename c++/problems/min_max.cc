#include <stdlib.h>

#include <iostream>

using namespace std;

const std::string kHelpText = "Este programa toma como parámetro un número y crea arrays de diferente tipo. Luego muestra el valor mínimo y máximo de cada array";

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

template <class T>
T Maximum(const T* data, int size) {
  T result = data[0];
  for (int i = 1; i < size; i++) {
    if (result < data[i]) {
      result = data[i];
    }
  }
  return result;
}

template <class T>
T Minimum(const T* data, int size) {
  T result = data[0];
  for (int i = 1; i < size; i++) {
    if (result > data[i]) {
      result = data[i];
    }
  }
  return result;
}

template <class T>
void Print(const T* data, int size) {
  for (int i = 0; i < size; i++) {
    cout << data[i] << " ";
  }
  cout << endl;
}

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  const int kElements = stoi(argv[1]);
  srand(time(NULL));
  double data[kElements];
  int numbers[kElements];
  char arrayChar[kElements];
  for (int i = 0; i < kElements; i++) {
    data[i] = (double)rand() / RAND_MAX;
    numbers[i] = rand() % 10 + 1;
    arrayChar[i] = 'a' + rand() % 26;
  }
  cout << "Array of double: ";
  Print(data, kElements);
  cout << "Array of int: ";
  Print(numbers, kElements);
  cout << "Array of char: ";
  Print(arrayChar, kElements);
  cout << "Minimum double is " << Minimum(data, kElements) << endl;
  cout << "Maximum double is " << Maximum(data, kElements) << endl;
  cout << "Minimum integer is " << Minimum(numbers, kElements) << endl;
  cout << "Maximum integer is " << Maximum(numbers, kElements) << endl;
  return 0;
}