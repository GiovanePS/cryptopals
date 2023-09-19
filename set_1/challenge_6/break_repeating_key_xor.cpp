#include <iostream>
#include <fstream>
#include "../challenge_3/single_byte_xor_cipher.cpp"
#include "../challenge_5/repeating_key_xor.cpp"

//Keysize is 29, 31 or 32.

int main(void) {

    std::ifstream inputFile("hex.txt");
    std::string hexInput;
    getline(inputFile, hexInput);
    std::string hexPair;
    int hexInputLength = hexInput.length()/2;
    unsigned int hexPairInput[hexInputLength];
    std::string strPairInput;
    std::string finalKey;
    std::string finalOutput;

    for (int i = 0; i < hexInput.length()/2; i++) {
        hexPair = hexInput.substr(i*2, 2);
        hexPairInput[i] = std::stoi(hexPair, nullptr, 16);
        strPairInput.append(1, hexPairInput[i]);
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
        finalKey.append(1, ScoringSingleByteXor(block).second);
        block.clear();
    }

    // finalOutput = repeating_key_xor(strPairInput, finalKey);

    // std::cout << finalOutput << std::endl;

    return 0;
}