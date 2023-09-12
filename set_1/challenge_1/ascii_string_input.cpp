#include <iostream>

int main(int argc, char* argv[]) {
    char encode_table[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
    };

    // input: 49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d

    std::string strInput = argv[1];
    int caracteresHexa[strInput.length()/2];
    std::string hexPair;
    for (int i = 0; i < sizeof(caracteresHexa)/sizeof(caracteresHexa[0]); i++) {
        hexPair = strInput.substr(i*2, 2);
        caracteresHexa[i] = std::stoi(hexPair, nullptr, 16);
    }

    // for (char a : caracteresHexa) {
    //     std::cout << a;
    // }
    // std::cout << std::endl;
    // output: "I'm killing your brain like a poisonous mushroom" in ASCII.

    for (int i = 0; i < sizeof(caracteresHexa)/sizeof(caracteresHexa[0]); i++) {
        strInput[i] = caracteresHexa[i];
    }

    std::string finalOutput = "";
    int i = 16, inputConcat = 0;
    unsigned int deslocamento = 24, mascara = 0b111111111111111111111111;
    for (int x = 0; x <= strInput.length()/2; x++) {
        inputConcat |= (strInput[x] << i);
        i -= 8;
        if (i < 0) {
            i = 16;
            for (int j = 0; j < 4; j++) {
                deslocamento -= 6;
                finalOutput += encode_table[inputConcat >> deslocamento];
                inputConcat &= mascara >> (24 - deslocamento);
            }

            deslocamento = 24;
            inputConcat = 0;
        }
    }

    std::cout << finalOutput << std::endl;

    return 0;
}