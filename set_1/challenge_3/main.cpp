#include <iostream>
#include "single_byte_xor_cipher.cpp"

int main(void) {
	
	std::string inputString = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
	
	std::cout << ScoringSingleByteXor(inputString).first << std::endl;

	return 0;
}