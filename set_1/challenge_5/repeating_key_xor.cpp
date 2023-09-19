#include <iostream>

std::string repeating_key_xor(std::string strInput, std::string inputKey) {

    std::string strOutput;

    for (int i = 0; i < strInput.length(); i++) {
        strOutput.append(1, strInput[i] xor inputKey[i % inputKey.length()]);
    }

    return strOutput;
}