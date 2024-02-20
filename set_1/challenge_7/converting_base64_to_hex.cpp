#include <iostream>
#include <fstream>

int main(void) {

    char encode_table[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/', '='
    };

    std::string linha;
    std::ifstream base64File("base64.txt");
    std::ofstream outputFile("hex.txt");

    bool caractere_equal = false;
    char hexChar[3];
    int i = 18, inputConcat = 0, indice, contador, caractere;
    unsigned int deslocamento = 24, mascara = 0b111111111111111111111111;
    while (getline(base64File, linha)) {
        i = 18, inputConcat = 0, deslocamento = 24;
        for (int x = 0; x <= linha.length(); x++) {
            contador = 0;

            while (encode_table[contador] != linha[x]) {
                contador++;
            }

            if (contador == 64) {
                contador = 0;
                caractere_equal = true;
            }
            indice = contador;
            inputConcat |= indice << i;// Unindo 4 caracteres base64.
            i -= 6;

            if (i < 0) {
                i = 18;
                for (int y = 0; y < 3; y++) {
                    deslocamento -= 8;
                    caractere = inputConcat >> deslocamento;
                    if (caractere_equal == false || caractere != 0) {
                        sprintf(hexChar, "%02x", caractere);
                        outputFile << hexChar;
                    }
                    inputConcat &= mascara >> (24 - deslocamento);
                }

                deslocamento = 24;
                inputConcat = 0;
            }
        }
    }

    return 0;
}