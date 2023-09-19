#include <iostream>
#include <fstream>
#include <string>
#include "../challenge_3/single_byte_xor_cipher.cpp"

//Keysize is 29, 31 or 32.

int main(void) {

    std::ifstream inputFile("hex.txt");
    std::string hexInput;
    getline(inputFile, hexInput);
    std::string hexPair;
    int hexInputLength = hexInput.length()/2;
    unsigned int hexPairInput[hexInputLength];
    std::string finalKey;

    for (int i = 0; i < hexInput.length()/2; i++) {
        hexPair = hexInput.substr(i*2, 2);
        hexPairInput[i] = std::stoi(hexPair, nullptr, 16);
    }

    int keysize = 29;
    int idx = 0;
    std::string block;
    for (int i = 0; i < keysize; i++) {
        for (int j = 0; j <= keysize; j++) {
            if (keysize*j+i < hexInputLength) {
                block.append(std::to_string(hexPairInput[keysize*j+i]));
            }
        }
        std::cout << (int)ScoringSingleByteXor(block).second << '\n';
        finalKey.append(1, ScoringSingleByteXor(block).second);
        block.clear();
    }

    std::cout << finalKey << std::endl;

    return 0;
}