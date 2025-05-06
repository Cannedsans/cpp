#include <iostream>
#include <list>

using namespace std;

int main(){
    list<int> lista;

    int tam = 10;

    for (size_t i = 0; i < tam; i++)
    {
        lista.push_front(i); // comportamento de pilha
    }

    cout << "Tamanho da lista" << lista.size() << endl;

    tam = lista.size();

    for (size_t i = 0; i < tam; i++)
    {
        cout << lista.front() << endl;
        lista.pop_front(); // comportamento de fila
    }

    return 0;
}
