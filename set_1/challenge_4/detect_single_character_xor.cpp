#include <iostream>
#include <fstream>

std::string singleByteXor(std::string, char);
bool chars_on_range(int);

int main(void) {

    std::string linha;
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Arquivo não pôde ser aberto." << std::endl;
        exit(1);
    }

    unsigned char caractere;
    std::string highscoreString;
    int highScore = -100;
    int score;
    while (getline(inputFile, linha)) {
        caractere = 32;
        while (caractere <= 126) {
            score = 0;
            std::string xorString = singleByteXor(linha, caractere);
            for (int i = 0; i < xorString.length(); i++) {
                if (chars_on_range(xorString[i])) {
                    score++;
                } else {
                    score--;
                }
            }

            if (score > highScore) {
                highscoreString = xorString;
                highScore = score;
            }

            caractere++;
            xorString.clear();
        }
    }

    std::cout << highscoreString;

    inputFile.close();

    return 0;
}

std::string singleByteXor(std::string input, char byte_ascii) {

	std::string strInput = input;
	char mascara = byte_ascii;

	std::string xorChars;
	std::string hexPair;
	for (int i = 0; i < strInput.length()/2; i++) {
		hexPair = strInput.substr(i*2, 2);
		xorChars.append(1, std::stoi(hexPair, nullptr, 16) xor mascara);
	}

	return xorChars;
}

bool chars_on_range(int hex) {
	if (hex == 32 || hex >= 65 && hex <= 90 || hex >= 97 && hex <= 122) {
        //Verificando se o caractere é de 'A' a 'Z', de 'a' a 'z' ou se é um espaço.
		return true;
	} else {
		return false;
	}
}