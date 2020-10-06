#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"

TEST_CASE("Tests encryptCaesar()")
{
	CHECK(encryptCaesar("Alexandros Aidonis!", 7) == "Hslehukyvz Hpkvupz!");
	CHECK(encryptCaesar("Hslehukyvz Hpkvupz!", -7) == "Alexandros Aidonis!");
	CHECK(encryptCaesar("126386901791-2939!#", 15) == "126386901791-2939!#");
}


TEST_CASE("Tests encryptVigenere()")
{
	CHECK(encryptVigenere("Alexandros Aidonis!", "testing") == "Tpwqiajksk Tqqugmk!");
	CHECK(encryptVigenere("126386901791-2939!#", "keyword") == "126386901791-2939!#");
	CHECK(encryptVigenere("AVERYBIGSENTENCEaverybigsentence,!yugaghdajdag hadvdhagdajbdklyayrdafdtadfdhsfhdsvdhs", "encryptalex") == "EIGIWQBGDIKXRPTCpoeccymtuvlixnni,!vytcxfstjoed lnfmbwtgoegfqmcwprroechgcudsasqlawifyq");
	CHECK(encryptVigenere("", "ballon") == "");
}

