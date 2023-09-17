#include <iostream>

int main(void) {
    char encode_table[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
    }; // Tabela dos valores possíveis em base64, com cada valor na posição de seu índice correspondente.

    std::string strInput = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    std::string strOutput;
    std::string hexPair;
    for (int i = 0; i < strInput.length()/2; i++) {
        hexPair = strInput.substr(i*2, 2);
        strOutput += (int)std::stoi(hexPair, nullptr, 16); // Conversão dos pares de caracteres ascii para hexadecimal em si.
        // Quando são guardados em um vetor do tipo std::string, o inteiro é convertido em char, resultando na saída abaixo.
    }   // strOutput: "I'm killing your brain like a poisonous mushroom" em ASCII.

    std::string finalOutput;
    int i = 16, inputConcat = 0;
    unsigned int deslocamento = 24, mascara = 0b111111111111111111111111; // 24 números 1. 
    for (int x = 0; x <= strOutput.length(); x++) {
        inputConcat |= (strOutput[x] << i); // Unindo os 3 caracteres hexadecimais necessários para a conversão em base64.
        // A união é feita através de um OR, que concatena bit a bit os 3 caracteres em inputConcat.
        i -= 8;
        // i começa em 16 e vai diminuindo de 8 em 8 pois quando i for negativo, sabe-se que 3 caracteres hexadecimais estão em inputConcat.
        // Mas i não é apenas um contador, pois ele também serve como valor de deslocamento na concatenação dos caracteres hexadecimais.
        if (i < 0) {
            i = 16;
            for (int j = 0; j < 4; j++) {
                deslocamento -= 6; // O deslocamento vai diminuindo de 6 em 6 pois os caracteres em base64 possuem apenas 6 bits.
                finalOutput += encode_table[inputConcat >> deslocamento];
                // O resultado de inputConcat >> deslocamento é exatamente o índice do caractere na encode_table.
                inputConcat &= mascara >> (24 - deslocamento);
                // O objetivo da linha acima é ir limpando os caracteres em inputConcat através do AND.
                // Exemplo:
                // InputConcat:       11111111 11111111 11111111 // 3 conjuntos de 8 bits, 3 caracteres ascii.
                // São convertidos em 111111 111111 111111 111111 // para base64.
            }

            deslocamento = 24;
            inputConcat = 0;
        }
    }

    std::cout << finalOutput << std::endl;

    return 0;
}