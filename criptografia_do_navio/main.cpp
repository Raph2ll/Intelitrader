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
        // Converte cada byte de binário para inteiro
        int decimal = bitset<8>(meuArray[i]).to_ulong();

        // Inverte os dois últimos bits
        int inverteDoisbits = decimal ^ 0b11;

        // Troca os 4 bits com os próximos 4
        int inverteQuatrobits = ((inverteDoisbits & 0b11110000) >> 4) | ((inverteDoisbits & 0b00001111) << 4);

        // Adiciona o caractere correspondente à tabela ASCII ao resultado
        ret += static_cast<char>(inverteQuatrobits);
    }

    return ret;
}

int main() {
    string mensagem = "10010110 11110111 01010110 00000001 00010111 00100110 01010111 00000001 00010111 01110110 01010111 00110110 11110111 11010111 01010111 00000011";
    string resultado = descriptografa(mensagem);

    cout << "Mensagem descriptografada: " << resultado << endl;

    return 0;
}