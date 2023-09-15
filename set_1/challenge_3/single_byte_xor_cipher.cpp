#include <iostream>
#include <string.h>

int* singleByteXor(char*, char);

//LETRA X!

int main(int argc, char* argv[]) {
	char caractere = 'A';
	while (caractere <= 'Z') {
		int* output = singleByteXor(argv[1], caractere);

		std::cout << "Letra: " << caractere << '\n';
		for (int i = 0; i < strlen(argv[1])/2; i++) {
			std::cout << (char)output[i];
		}

		std::cout << "\n\n";

		delete[] output;
		caractere++;
	}

	return 0;
}

int* singleByteXor(char* input, char byte_ascii) {

	std::string strInput = input;
	char mascara = byte_ascii;

	int* xorChars = new int[strInput.length()/2];
	std::string hexPair;
	for (int i = 0; i < strInput.length()/2; i++) {
		hexPair = strInput.substr(i*2, 2);
		xorChars[i] = std::stoi(hexPair, nullptr, 16) xor mascara;
	}

	return xorChars;
}