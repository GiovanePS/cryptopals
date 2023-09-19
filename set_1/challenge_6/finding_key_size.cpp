#include <iostream>
#include <fstream>

int hamming_distance(unsigned int, unsigned int);
double find_min_value(double, double, double);

int main(void) {

    std::ifstream inputFile("hex.txt");
    std::string hexInput;
    getline(inputFile, hexInput);
    std::string string;
    std::string hexPair;
    unsigned int hexPairInput[hexInput.length()/2];
    constexpr int BLOCK_LENGTH = 4;

    //Convertendo toda a hexInput, que é uma string em valores ascii, juntando os pares para termos um caractere hexadecimal.
    for (int i = 0; i < hexInput.length()/2; i++) {
        hexPair = hexInput.substr(i*2, 2);
        hexPairInput[i] = std::stoi(hexPair, nullptr, 16);
    }

    double distanceHammingAverage;
    double sum;
    int lowScoresKeys[3] = {0};
    int lowScoresValues[3] = {100, 100, 100}; // Valores que eu considero suficientemente altos.
    int setsMatrix[BLOCK_LENGTH][40]; // 5 blocos de no máximo 40 valores hexadecimais (tamanho da key).
    int keysize = 3;
    int idx;
    int contador;
    while (keysize != 4) {
        idx = 0;
        for (int i = 0; i < BLOCK_LENGTH-1; i++) {
            for (int j = 0; j < keysize; j++) {
                setsMatrix[i][j] = hexPairInput[idx++];
                std::cout << hexPairInput[idx];
            }
        }

        std::cout << '\n';

        distanceHammingAverage = 0;
        for (int i = 0; i < BLOCK_LENGTH-1; i++) {
            sum = 0;
            for (int j = 0; j < keysize; j++) {
                sum += hamming_distance(setsMatrix[i][j], setsMatrix[i+1][j]);
                std::cout << hamming_distance(setsMatrix[i][j], setsMatrix[i+1][j]) << '\n';
            }
            std::cout << "Soma: " << sum << '\n';
            sum /= (float)keysize;
            distanceHammingAverage += sum;
        }

        distanceHammingAverage /= (float)keysize;
        
        // Operações abaixo necessárias para encontrar de fato os 3 menores valores e evitar erros.
        if (distanceHammingAverage < find_min_value(lowScoresValues[0], lowScoresValues[1], lowScoresValues[2])) {
            if (distanceHammingAverage < lowScoresValues[0]) {
                lowScoresValues[0] = distanceHammingAverage;
                lowScoresKeys[0] = keysize;
            } else if (distanceHammingAverage < lowScoresValues[1]) {
                lowScoresValues[1] = distanceHammingAverage;
                lowScoresKeys[1] = keysize;
            } else {
                lowScoresValues[2] = distanceHammingAverage;
                lowScoresKeys[2] = keysize;
            }
        }

        keysize++;
    }

    for (int i = 0; i < 3; i++) {
        std::cout << lowScoresKeys[i] << ": " << lowScoresValues[i] << '\n';
    }

    return 0;
}

int hamming_distance(unsigned int char1, unsigned int char2) {
    unsigned char charXor;
    int contador = 0;
    charXor = char1 xor char2;
        while (charXor != 0) {
            if (charXor & 1) {
                contador++;
            }
            charXor >>= 1;
        }

    return contador;
}

double find_min_value(double n1, double n2, double n3) {
    int min = n1;

    if (n2 < min) {
        min = n2;
    }

    if (n3 < min) {
        min = n3;
    }

    return min;
}