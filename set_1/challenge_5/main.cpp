#include <iostream>
#include <iomanip>
#include "repeating_key_xor.cpp"

int main(void) {

    std::string strInput = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
    std::string key = "ICE";

    std::string output = repeating_key_xor(strInput, key);

    for (int c : output) {
        std::cout << std::hex << std::setfill('0') << std::setw(2) << c;
    }

    std::cout << std::endl;

    return 0;
}