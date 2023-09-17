#include <iostream>

int hexCharToInt(char letter);
char hexIntToChar(int number);

int main(void) {

    std::string hexInput1 = "1c0111001f010100061a024b53535009181c";
    std::string hexInput2 = "686974207468652062756c6c277320657965";

    int output[hexInput1.length()] = {};
    for (int i = 0; i < hexInput1.length(); i++) {
        output[i] = hexCharToInt(hexInput1[i]) xor hexCharToInt(hexInput2[i]);
    }

    for (auto a : output) {
        if (a > 9) {
            std::cout << hexIntToChar(a);
        } else {
            std::cout << a;
        }
    }

    std::cout << std::endl;

    return 0;
}

// conversões com base em ASCII.
int hexCharToInt(char letter) {
    if (letter >= '0' && letter <= '9') {
        return letter - '0';
    } else {
        return letter - 'a' + 10;
    }
}

// conversões com base em ASCII.
char hexIntToChar(int number) {
    return 'a' + (number - 10);
}