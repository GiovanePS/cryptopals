#include <iostream>
#include <cstring>

int main(int argc, char* argv[]) {
    char encode_table[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
    };

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