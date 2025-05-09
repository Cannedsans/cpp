#include <fstream>
#include <iostream>

using namespace std;

int main(){
    fstream arquivo;
    string linha;
    arquivo.open("texto.txt", ios::app | ios::in);

    if (!arquivo.is_open())
    {
        cerr << "Falha ao abrir o arquivo \n";
        return 1;
    }
    while (getline(arquivo, linha))
    {
        cout << linha << endl;
    }

    arquivo.close();

    return 0;
}
