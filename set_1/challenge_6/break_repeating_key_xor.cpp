#include <iostream>
#include <fstream>
#include "../challenge_3/single_byte_xor_cipher.cpp"

//Keysize is 29, 31 or 32.

int main(void) {

    std::ifstream inputFile("hex.txt");
    std::string hexInput;
    getline(inputFile, hexInput);
    std::string hexPair;
    unsigned int hexPairInput[hexInput.length()/2];

    for (int i = 0; i < hexInput.length()/2; i++) {
        hexPair = hexInput.substr(i*2, 2);
        hexPairInput[i] = std::stoi(hexPair, nullptr, 16);
    }

    int keysize = 3;
    int idx = 0;
    std::string block;
    for (int i = 0; i < keysize; i++) {
        for (int j = 0; j <= keysize; j++) {
            block += hexPairInput[keysize*j+i];
            std::cout << block;
        }
        std::cout << std::endl;
        std::cout << ScoringSingleByteXor(block) << '\n';
        block.clear();
    }

    return 0;
}