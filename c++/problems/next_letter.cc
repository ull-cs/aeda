#include <iostream>

const std::string kHelpText = "Este programa toma como parámetro una cadena y cambia cada letra por la siguiente del alfabeto";

/**
 * Indica el modo correcto de uso del programa
 * El programa requiere dos nombres de ficheros pasados por línea de comandos
 *
 * @param argc Número de parámetros pasado por línea de comandos
 * @param argv Vector de punteros a caracter conteniendo los parámetros pasados
 */
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
    std::cout << argv[0] << " cadena" << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_FAILURE);
  }
}

/**
 * Replaces each letter with the next in the alphabet
 * Non-letter characters remain unaltered
 *
 * @param cadena de entrada para modificar
 */
std::string NextLetter(const std::string& cadena) {
  std::string result = cadena;
  for (int i = 0; i < cadena.length(); i++) {
    auto current_char = cadena.at(i);
    if (isalpha(current_char)) {
      if ((current_char != 'z') && (current_char != 'Z')) {
        result.at(i) = (current_char + 1);
      }
    }
  }
  return result;
}

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  const std::string cadena = argv[1];
  std::cout << NextLetter(cadena) << std::endl;
  return 0;
}
