#include <iostream>
#include <fstream>

int main(void) {

    char encode_table[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
    };

    std::string linha;
    std::ifstream base64File("base64.txt");
    std::ofstream outputFile("output.txt");

    int i = 18, inputConcat = 0, indice, contador;
    unsigned int deslocamento = 24, mascara = 0b111111111111111111111111;
    while (getline(base64File, linha)) {
        for (int x = 0; x <= linha.length(); x++) {
            contador = 0;
            while (encode_table[contador] != linha[x]) {
                contador++;
            }

            indice = contador;
            inputConcat |= indice << i;// Unindo 4 caracteres base64.
            i -= 6;

            if (i < 0) {
                i = 18;
                for (int y = 0; y < 3; y++) {
                    deslocamento -= 8;
                    outputFile << (char)(inputConcat >> deslocamento);
                    inputConcat &= mascara >> (24 - deslocamento);
                }

                deslocamento = 24;
                inputConcat = 0;
            }
        }
    }

    return 0;
}