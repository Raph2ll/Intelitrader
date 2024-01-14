#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

// Verifique se o primeiro elemento é igual a "acao"
bool verificarRepeticao(const string& acao) {
    ifstream leituraArquivo("ofertas.txt");
    string linha;
    
    while (getline(leituraArquivo, linha)) {
        istringstream iss(linha);
        vector<string> elementos;

        // Use ',' como delimitador para obter todos os elementos
        while (getline(iss, linha, ',')) {
            elementos.push_back(linha);
        }

        // Verifique se o primeiro elemento é igual a "acao"
        if (!elementos.empty() && elementos[0] == acao) {
            leituraArquivo.close();
            return true; // Encontrado, é repetido
        }
    }

    leituraArquivo.close();
    return false;
}

void inserir(string acao) {

    if (verificarRepeticao(acao)) {
        cout << "Ação repetida. Não será inserida novamente." << endl;
        return;
    }

    ofstream arquivo("ofertas.txt", ios::app);
    string userInput;
    double valor;
    string ret = acao + ",";
    int quantidade;

    cout << "Digite o valor da sua oferta. [0.0]\n" << endl;

    while (true) {
        try {
            getline(cin, userInput);
            valor = stod(userInput);
            if(valor < 0.0){
                cout << "Digite um valor maior que: 0.0\n" << endl;
            }   
                ret += to_string(valor) + ",";
                break;
        } catch (const invalid_argument& e) {
            cerr << "Erro de conversão: " << "\nDigite um valor válido.\n" << endl;
        }
    }

    cout << "Digite a quantidade da oferta. [0]\n" << endl;

    while (true) {
        try {
            getline(cin, userInput);
            quantidade = stoi(userInput);
            if (quantidade < 0) {
                cout << "Digite um valor maior que: 0\n" << endl;
            }
                ret += to_string(quantidade) + ",";
                break;
        } catch (const invalid_argument& e) {
            cerr << "Erro de conversão: " << "\nDigite um valor válido.\n" << endl;
        }
        
    }
    arquivo << ret << endl;
    
}
void modificar() {

}
void deletar() {

}

void encerrar() {

}

bool arquivoExiste(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo.c_str());
    return arquivo.good();
}

void criarOuAbrirArquivo(ofstream& arquivo, const string& nomeArquivo) {
    if (arquivoExiste(nomeArquivo)) {
        cout << "O arquivo já existe. Continuando o programa." << endl;
    } else {
        cout << "O arquivo não existe. Criando um novo arquivo." << endl;
        arquivo.open(nomeArquivo.c_str());
        arquivo.close();
        cout << "Novo arquivo criado com sucesso." << endl;
    }
}

int main() {

    string nomeArquivo = "ofertas.txt";
    ofstream meuArquivo;

    criarOuAbrirArquivo(meuArquivo, nomeArquivo);

    cout << "Bem-vindo ao livro de ofertas.\n" << endl;
    while (true) {
        int numero = 0;
        string ret = "";
        string userInput = "";
        while (true) {
            cout << "Insira o número da oferta:\n" << endl;
            try {
                getline(cin, userInput);
                numero = stoi(userInput);

                if (numero < 0) {
                    cout << "Digite um valor maior que 0.\n" << endl;
                } else {
                    ret += to_string(numero);
                    break;
                }
            } catch (const invalid_argument& e) {
                cerr << "Erro de conversão: " << "\nDigite um valor válido.\n" << endl;
            }
        }
        while (true) {
            cout << "Selecione uma das opções abaixo:\n"
                << "0: Inserir\n"
                << "1: Modificar\n"
                << "2: Deletar\n"
                << "3: Encerrar\n"
                << endl;

            getline(cin, userInput);

            cout << "Você digitou: " << userInput << "\n" << endl;

            if (userInput == "0") {
                inserir(ret);
                break;
            } else if (userInput == "1") {
                modificar();
            } else if (userInput == "2") {
                deletar();
            } else if (userInput == "3") {
                encerrar();
            } else {
                cout << "Digite um valor válido entre [0,1,2,3].\n" << endl;
            }
        }
    }
    

    


    return 0;
}
