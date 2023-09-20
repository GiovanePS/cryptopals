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

int charScores(int hex) {
	if (hex == 32) { return 2; }
	if (hex == 'A' || hex == 'a' || hex == 'E' || hex == 'e' || hex == 'O' || hex == 'o' || hex == 'I' || hex == 'i') { return 3; }
	if (hex == 'T' || hex == 't' || hex == 'N' || hex == 'n' || hex == 'S' || hex == 's' || hex == 'R' || hex == 'r') { return 2; }

	if (hex > 65 && hex <= 90 || hex > 97 && hex <= 122) { return 1; }
		
	return 0;
}

std::pair<std::string, unsigned char> ScoringSingleByteXor(std::string inputStr) {
	std::string highScoreString = "";
	int highScore = -100;
	int highScoreChar;
	int score;

	unsigned char caractere = 32;
	while (caractere < 127) {
		score = 0;
		std::string xorString = singleByteXor(inputStr, caractere);

		for (int i = 0; i < xorString.length(); i++) {
			if (charScores(xorString[i])) {
				score += charScores(xorString[i]);
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