#include <iostream>
#include <cstring>

int main(int argc, char* argv[]) {

    // |- "I'm killing your brain like a poisonous mushroom" in ASCII.
    std::string hexInput = argv[1];

    int caracteresHexa[hexInput.length()/2];

    std::string hexPair;
    for (int i = 0; i < sizeof(caracteresHexa)/sizeof(int); i++) {
        hexPair = hexInput.substr(i*2, 2);
        caracteresHexa[i] = std::stoi(hexPair, nullptr, 16);
    }

    for (char a : caracteresHexa) {
        std::cout << a;
    }
    std::cout << std::endl;

    return 0;
}