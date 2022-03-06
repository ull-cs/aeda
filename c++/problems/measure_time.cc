#include <chrono>
#include <iostream>
#include <limits>

const std::string kHelpText = "Este programa mide el tiempo requerido para calcular el factorial de un número pasado como argumento mediante una función convencional y una en línea (inline)";

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

int Factorial(int n) {
  return (n < 2) ? 1 : n * Factorial(n - 1);
}

inline int InlineFactorial(int n) {
  return (n < 2) ? 1 : n * InlineFactorial(n - 1);
}

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  const int kNumberToCheck = std::stoi(argv[1]);

  std::cout << "Midiendo tiempo mediante función convencional:" << std::endl;
  std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
  Factorial(kNumberToCheck);
  std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> elapsedTime = endTime - startTime;
  std::cout << "Tiempo: " << elapsedTime.count() << " ms.\n";

  std::cout << "Midiendo tiempo mediante función en línea:" << std::endl;
  std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
  InlineFactorial(kNumberToCheck);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> elapsedTimeInline = end - start;
  std::cout << "Tiempo " << elapsedTimeInline.count() << " ms.\n";
}
