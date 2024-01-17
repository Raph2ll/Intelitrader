#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

string descriptografa(const string& mensagem) {
    vector<string> meuArray;
    string semEspacos;
    string ret;

    // Remove os espaços
    for (int i = 0; i < mensagem.length(); i++) {
        if (mensagem[i] != ' ') {
            semEspacos += mensagem[i];
        }
    }

    // Separa a cada 8 caracteres
    for (size_t i = 0; i < semEspacos.length(); i += 8) {
        meuArray.push_back(semEspacos.substr(i, 8));
    }

    for (const auto& num : meuArray) {
        // Converte cada byte de binário para inteiro
        int decimal = bitset<8>(num).to_ulong();

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
