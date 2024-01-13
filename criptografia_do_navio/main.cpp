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

    // Separa a string em strings de 8 bits
    for (int i = 0; i < tamanhoDoArray; i++) {
        string substring;
        for (int j = 0; j < 8; ++j) {
            int contador = i * 8 + j;
            substring += semEspacos[contador];
        }
        meuArray[i] = substring;
    }

    for (int i = 0; i < tamanhoDoArray; i++) {
        // Inverte a posição dos dois últimos bits
        char temp = meuArray[i][meuArray[i].length() - 1];
        meuArray[i][meuArray[i].length() - 1] = meuArray[i][meuArray[i].length() - 2];
        meuArray[i][meuArray[i].length() - 2] = temp;
        // Troca os 4 bits com os próximos 4.
        int decimal = bitset<8>(meuArray[i]).to_ulong();
        int inverteBits = decimal;
        int trocaPosicao = ((inverteBits & 0b11110000) >> 4) | ((inverteBits & 0b00001111) << 4);
        ret += trocaPosicao;
    }

    return ret;
}

int main() {
    string mensagem = "10010110 11110111 01010110 00000001 00010111 00100110 01010111 00000001 00010111 01110110 01010111 00110110 11110111 11010111 01010111 00000011";
    string resultado = descriptografa(mensagem);

    cout << "Mensagem descriptografada: " << resultado << endl;

    return 0;
}