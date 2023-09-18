#include <iostream>
#include <iomanip>

int main(void) {

    std::string strInput = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
    std::string key = "ICE";
    char strOutput[strInput.length()];

    for (int i = 0; i < strInput.length(); i++) {
        strOutput[i] = strInput[i] xor key[i % 3];
    }

    for (int c : strOutput) {
        std::cout << std::hex << std::setfill('0') << std::setw(2) << c;
    }

    std::cout << std::endl;

    return 0;
}