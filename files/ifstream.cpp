#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream arquivo;
    string linha;
    arquivo.open("texto.txt");

    if(!arquivo.is_open()){
        cerr << "Falha ao abrir o arquivo \n";
        return 1;
    }
    while(getline(arquivo, linha)){
        cout << linha << endl;
    }

    arquivo.close();

    return 0;
}
