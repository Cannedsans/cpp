#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> produtos = {"Banana", "teclado", "boné"};
    vector<string>::iterator interador;

    for (interador = produtos.begin(); interador != produtos.end(); interador++){
        cout << *interador << endl;
    }

        return 0;
}
