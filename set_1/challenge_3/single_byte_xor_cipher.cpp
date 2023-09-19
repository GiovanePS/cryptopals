#include <iostream>

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
		return true;
	} else {
		return false;
	}
}

std::pair<std::string, unsigned char> ScoringSingleByteXor(std::string inputStr) {
	std::string highScoreString = "";
	int highScore = -100;
	int highScoreChar;
	int score;

	unsigned char caractere = 0;
	while (caractere < 255) {
		score = 0;
		std::string xorString = singleByteXor(inputStr, caractere);

		for (int i = 0; i < xorString.length(); i++) {
			if (chars_on_range(xorString[i])) {
				score++;
			} else {
				score--;
			}
		}

		if (score > highScore) {
			highScoreString = xorString;
			highScore = score;
			highScoreChar = caractere;
		}

		xorString.clear();
		caractere++;
	}

	return std::make_pair(highScoreString, highScoreChar);
}