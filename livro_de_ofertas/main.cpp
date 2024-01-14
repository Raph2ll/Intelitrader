#include <iostream>
#include <string>
#include <map>
using namespace std;

// Definindo um alias para facilitar a leitura
using MeuMapaType = map<int, pair<double, int>>;

void inserir(MeuMapaType& meuMapa) {
    string userInput;
    int numero;
    double valor;
    int quantidade;

    cout << "Digite a posição da sua oferta. [0]\n" << endl;

    while (true) {
        try {

            getline(cin, userInput);
            numero = stoi(userInput);

            if (numero < 0) {
                cout << "Digite um valor maior que: 0\n" << endl;
            } if (meuMapa.find(numero) != meuMapa.end()) {
                cout << "Essa chave já existe, digite outra \n" << endl;
            } else {
                break;
            }
                
        } catch (const invalid_argument& e) {
            cerr << "Erro de conversão: " << "\nDigite um valor válido.\n" << endl;
        }
        
    }

    cout << "Digite o valor da sua oferta. [0.0]\n" << endl;

    while (true) {
        try {
            getline(cin, userInput);
            valor = stod(userInput);
            if(valor < 0.0){
                cout << "Digite um valor maior que: 0.0\n" << endl;
            }
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
            if (numero < 0) {
                cout << "Digite um valor maior que: 0\n" << endl;
            }
                break;
        } catch (const invalid_argument& e) {
            cerr << "Erro de conversão: " << "\nDigite um valor válido.\n" << endl;
        }
        
    }

    meuMapa[numero] = make_pair(valor, quantidade);
    cout << "\nChave: "<< numero << "\nValor: "<< valor << "\nQuantidade: "<< quantidade << "\n"<< endl;
}

void modificar(MeuMapaType& meuMapa) {
    string userInput;
    int numero;
    double valor;
    int quantidade;

    cout << "Digite a oferta a ser modificada. [0]\n" << endl;

    while (true) {
        try {
            getline(cin, userInput);
            numero = stoi(userInput);
            if (meuMapa.find(numero) == meuMapa.end()) {
                cout << "Essa oferta não existe, tente outro valor. \n" << endl;
            } else {
                
                break;
            }
                
        } catch (const invalid_argument& e) {
            cerr << "Erro de conversão: " << "\nDigite um valor válido.\n" << endl;
        }
        
    }

    cout << "Selecione uma das opções abaixo para ser modificada [0]:\n"
             << "0: chave\n"
             << "1: valor\n"
             << "2: quantidade\n"
             << endl;

    while (true) {
        getline(cin, userInput);

        if (userInput == "0") {
            cout << "Digite o novo valor para a chave:" << endl;

            while (true) {
                try {
                    getline(cin, userInput);
                    int novaChave = stoi(userInput);

                    if (meuMapa.find(novaChave) != meuMapa.end()) {
                        cout << "Essa chave já existe, digite outra." << endl;
                    } else {
                        meuMapa[novaChave] = meuMapa[numero];
                        meuMapa.erase(numero);
                        break;
                    }
                } catch (const invalid_argument& e) {
                    cerr << "Erro de conversão: Digite um valor válido." << endl;
                }
            }

        } else if (userInput == "1") {
            cout << "Digite o novo valor:" << endl;

            while (true) {
               getline(cin, userInput);
                valor = stod(userInput);
                try {
                    if(valor < 0.0){
                        cout << "Digite um valor maior que: 0.0\n" << endl;
                    } else {
                        meuMapa[numero].first = valor;
                        break;
                    }  
                } catch (const invalid_argument& e) {
                    cerr << "Erro de conversão: Digite um valor válido." << endl;
                }
            }

        } else if (userInput == "2") {
            cout << "Digite o novo valor:" << endl;

            while (true) {
                getline(cin, userInput);
                quantidade = stoi(userInput);
                try {
                    if(valor < 0){
                        cout << "Digite um valor maior que: 0\n" << endl;
                    }
                        meuMapa[numero].second = quantidade;
                        break;
                } catch (const invalid_argument& e) {
                    cerr << "Erro de conversão: Digite um valor válido." << endl;
                }
            }

        }
}
}

void deletar(MeuMapaType& meuMapa) {
    int numero;
    string userInput;

    cout << "Digite a oferta a ser deletada. [0]" << endl;

    while (true) {
        try {
            getline(cin, userInput);
            numero = stoi(userInput);

            if (meuMapa.find(numero) == meuMapa.end()) {
                cout << "Essa oferta não existe, tente outro valor." << endl;
            } else {
                meuMapa.erase(numero);
                break;
            }
        } catch (const invalid_argument& e) {
            cerr << "Erro de conversão: Digite um valor válido." << endl;
        }
    }
}

string encerrar(MeuMapaType& meuMapa) {

    return "encerrado";
}

int main() {
    // Criando o mapa na função main
    MeuMapaType meuMapa;

    string userInput;
    cout << "Bem-vindo ao livro de ofertas.\n" << endl;

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
            inserir(meuMapa);
        } else if (userInput == "1") {
            modificar(meuMapa);
        } else if (userInput == "2") {
            deletar(meuMapa);
        } else if (userInput == "3") {
            encerrar(meuMapa);
            break;
        } else {
            cout << "Digite um valor válido entre [0,1,2,3].\n" << endl;
        }
    }


    return 0;
}
