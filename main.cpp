#include <iostream>
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"

int main()
{
  test_ascii("Cat :3 Dog");
  test_ascii("Alexandros Aidonis");
  std::cout << encryptCaesar("Alexandros", 7) << "\n";
  std::cout << encryptVigenere("Alexandros, Aidonis","") << "\n";
  return 0;
}
