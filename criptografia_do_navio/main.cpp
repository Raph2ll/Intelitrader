#include <iostream>
#include <list>
#include <bitset>
using namespace std;

string descriptografa(string mensagem) {
    string semEspacos;
    string ret;
    
    // Remove os espaços
    for (int i = 0; i < mensagem.length(); i++) {
        if (mensagem[i] != ' ') {
            semEspacos += mensagem[i];
        }
    }

    // Define o tamanho do array
    int tamanhoDoArray = semEspacos.length() / 8;
    string meuArray[tamanhoDoArray];

    // Separa a cada caracteres
    for (int i = 0; i < tamanhoDoArray; i++) {
        string substring;
        for (int j = 0; j < 8; ++j) {
            int contador = i * 8 + j;
            substring += semEspacos[contador];
        }
        meuArray[i] = substring;
    }

    for (int i = 0; i < tamanhoDoArray; i++) {

        char temp = meuArray[i][meuArray[i].length() - 1];
        meuArray[i][meuArray[i].length() - 1] = meuArray[i][meuArray[i].length() - 2];
        meuArray[i][meuArray[i].length() - 2] = temp;

        int teste = bitset<8>(meuArray[i]).to_ulong();
        int inverted_last_two_bits = teste;
        int swapped_nibbles = ((inverted_last_two_bits & 0b11110000) >> 4) | ((inverted_last_two_bits & 0b00001111) << 4);
        ret += swapped_nibbles;
    }

    return ret;
}

int main() {
    string mensagem = "10010110 11110111 01010110 00000001 00010111 00100110 01010111 00000001 00010111 01110110 01010111 00110110 11110111 11010111 01010111 00000011";
    string resultado = descriptografa(mensagem);

    cout << "Mensagem descriptografada: " << resultado << endl;

    return 0;
}