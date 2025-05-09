#include <iostream>
#include <vector> // biblioteca de vetor

using namespace std;

int main(){
    vector<string> produtos = {"Banana", "teclado", "boné"};
    vector<string>::iterator interador; // declaração

    interador = produtos.begin(); // passa o primeiro elemento
    cout << *interador << endl; // sai banana

    interador = produtos.end()-1; // passa o ultimo elemento

    cout << *interador << endl; // sai boné

    return 0;
}
