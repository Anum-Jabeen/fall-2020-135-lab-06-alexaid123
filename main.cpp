#include <iostream>
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

int main()
{
  std::cout << "test_ascii(Cat :3 Dog)" << "\n\n";
  test_ascii("Cat :3 Dog");
  std::cout << "test_ascii(Hunter College CS)" << "\n\n";
  test_ascii("Hunter College CS");
   std::cout << "test_ascii(Tesla:32Apple Stocks)" << "\n\n";
  test_ascii("Tesla:32Apple Stocks");
  std::cout << "test_ascii(Alexandros Aidonis)" << "\n\n";
  test_ascii("Alexandros Aidonis");
  std::cout << "encryptCaesar(Alexandros, 7)" << "\n\n";
  std::cout << encryptCaesar("Alexandros", 7) << "\n\n";
  std::cout << "encryptVigenere(Alexandros Aidonis, crypto)" << "\n\n";
  std::cout << encryptVigenere("Alexandros, Aidonis","crypto") << "\n\n";
  std::cout << "decryptCaesar(Hslehukyvz, 7)" << "\n\n";
  std::cout << decryptCaesar("Hslehukyvz", 7) << "\n\n";
  std::cout << "decryptVigenere(Cccmtbfimh, Twfflxl, crypto)" << "\n\n";
  std::cout << decryptVigenere("Cccmtbfimh, Twfflxl", "crypto") << "\n\n";
  return 0;
}
