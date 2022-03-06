#include <iostream>

using namespace std;

const std::string kHelpText = "Este programa toma como parámetro un número, solicita al usuario la cantidad de números indicada y calcula la media";

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
    std::cout << argv[0] << " NUMEROS" << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_FAILURE);
  }
}

int main(int argc, char *argv[]) {
  Usage(argc, argv);
  int numberOfElements = std::stoi(argv[1]);
  int *numbers = new int[numberOfElements];
  cout << "Enter " << numberOfElements << " items:" << endl;
  for (int i = 0; i < numberOfElements; i++) {
    cin >> numbers[i];
  }
  double average = 0.0;
  cout << "You entered: ";
  for (int i = 0; i < numberOfElements; i++) {
    average += numbers[i];
    cout << numbers[i] << " ";
  }
  average /= numberOfElements;
  cout << endl;
  cout << "Average: " << average << endl;
  delete[] numbers;
  return 0;
}
