#include <iostream>
#include <fstream>

// fstream é de entrada e saida
// ofstream é de saida
// ifstream é de entrada
using namespace std;

int main(){
    ofstream arquivo;

    arquivo.open("texto.txt",ios::app);

    arquivo << "Olá mundo" << endl;

    arquivo.close();

    return 0;
}
