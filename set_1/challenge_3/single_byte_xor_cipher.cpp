#include <iostream>

int hexCharToInt(char);
char hexIntToChar(int);

int main(int argc, char* argv[]) {

	std::string strInput = argv[1];
	char mascara = argv[2][0];

	int hexInput[strInput.length()/2];
	int xorChars[strInput.length()/2];
	std::string hexPair;
	for (int i = 0; i < strInput.length()/2; i++) {
		hexPair = strInput.substr(i*2, 2);
		xorChars[i] = std::stoi(hexPair, nullptr, 16) xor mascara;
	}

	for (char a : xorChars) {
        std::cout << a;
    }

	std::cout << std::endl;

	return 0;
}