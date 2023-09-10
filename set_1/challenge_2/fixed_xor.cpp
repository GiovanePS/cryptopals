#include <iostream>

int hexCharToInt(char letter);
char hexIntToChar(int number);

int main(int argc, char* argv[]) {

    std::string hexInput1 = argv[1];
    std::string hexInput2 = argv[2];

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