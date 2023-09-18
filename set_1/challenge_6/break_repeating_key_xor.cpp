#include <iostream>

int main(void) {

    // definindo keysize.
    std::string str1 = "this is a test";
    std::string str2 = "wokka wokka!!!";

    char charXor;
    int contador = 0;
    for (int i = 0; i < str1.length(); i++) {
        charXor = str1[i] xor str2[i];
        while (charXor != 0) {
            if (charXor & 1 == 1) {
                contador++;
            }
            charXor >>= 1;
        }
    }

    std::cout << contador << std::endl;

    return 0;
}