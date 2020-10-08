#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

TEST_CASE("Tests shiftChar"){
  CHECK(shiftChar('g',5) == 'l');
  CHECK(shiftChar('B',-1) == 'A');
  CHECK(shiftChar('K',0) == 'K');
  CHECK(shiftChar('E',-4) == 'A');
  CHECK(shiftChar('a',32) == 'g');
  CHECK(shiftChar('a',60) == 'i');
  CHECK(shiftChar('a',-25) == 'b');
}

TEST_CASE("Tests encryptCaesar()")
{
	CHECK(encryptCaesar("Alexandros Aidonis!", 7) == "Hslehukyvz Hpkvupz!");
	CHECK(encryptCaesar("Hslehukyvz Hpkvupz!", -7) == "Alexandros Aidonis!");
	CHECK(encryptCaesar("126386901791-2939!#", 15) == "126386901791-2939!#");
	CHECK(encryptCaesar("This is a sentence with $#%@& symbols,?12 TEsting!", 49) == "Qefp fp x pbkqbkzb tfqe $#%@& pvjylip,?12 QBpqfkd!");
	CHECK(encryptCaesar("Hello, World Part #2 TEstinG!3", -37) == "Wtaad, Ldgas Epgi #2 IThixcV!3");
}


TEST_CASE("Tests encryptVigenere()")
{
	CHECK(encryptVigenere("Alexandros Aidonis!", "testing") == "Tpwqiajksk Tqqugmk!");
	CHECK(encryptVigenere("126386901791-2939!#", "keyword") == "126386901791-2939!#");
	CHECK(encryptVigenere("AVERYBIGSENTENCEaverybigsentence,!yugaghdajdag hadvdhagdajbdklyayrdafdtadfdhsfhdsvdhs", "encryptalex") == "EIGIWQBGDIKXRPTCpoeccymtuvlixnni,!vytcxfstjoed lnfmbwtgoegfqmcwprroechgcudsasqlawifyq");
	CHECK(encryptVigenere("", "ballon") == "");
	CHECK(encryptVigenere("Private, message!&^)&*&Encrypt", "passcode") == "Eranchh, qtsksis!&^)&*&Hrrrqhv");
}


TEST_CASE("Tests decryptCaesar()")
{
	CHECK(decryptCaesar("Hslehukyvz Hpkvupz!", 7) == "Alexandros Aidonis!");
	CHECK(decryptCaesar("Alexandros Aidonis!", -7) == "Hslehukyvz Hpkvupz!");
	CHECK(decryptCaesar("126386901791-2939!#", 15) == "126386901791-2939!#");
	CHECK(decryptCaesar("Qefp fp x pbkqbkzb tfqe $#%@& pvjylip,?12 QBpqfkd!", 49) == "This is a sentence with $#%@& symbols,?12 TEsting!");
	CHECK(decryptCaesar("Wtaad, Ldgas Epgi #2 IThixcV!3", -37) == "Hello, World Part #2 TEstinG!3");
}


TEST_CASE("Tests decryptVigenere()")
{
	CHECK(decryptVigenere("Tpwqiajksk Tqqugmk!", "testing") == "Alexandros Aidonis!");
	CHECK(decryptVigenere("126386901791-2939!#", "keyword") == "126386901791-2939!#");
	CHECK(decryptVigenere("EIGIWQBGDIKXRPTCpoeccymtuvlixnni,!vytcxfstjoed lnfmbwtgoegfqmcwprroechgcudsasqlawifyq", "encryptalex") == "AVERYBIGSENTENCEaverybigsentence,!yugaghdajdag hadvdhagdajbdklyayrdafdtadfdhsfhdsvdhs");
	CHECK(decryptVigenere("", "ballon") == "");
	CHECK(decryptVigenere("Eranchh, qtsksis!&^)&*&Hrrrqhv", "passcode") == "Private, message!&^)&*&Encrypt");
	CHECK(decryptVigenere("Keelsn amdlbss , clpss", "value") == "Petros abjhgsh , ihush");
}