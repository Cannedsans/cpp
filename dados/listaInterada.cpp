#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> lista;
    list<int>::iterator it;

    int tam = 10;

    for (size_t i = 0; i < tam; i++)
    {
        lista.push_front(i); // comportamento de pilha
    }
    it = lista.begin();
    advance(it, 5);
    advance(it, 2);

    lista.insert(it, 0); // adiciona um 0 entre o 4 e o 5
    lista.erase(it); // apagar o item no lugar do interator
    lista.sort();    // organiza em forma crescente
    lista.reverse(); // inverte a ordem
    cout << "Tamanho da lista" << lista.size() << endl;

    tam = lista.size();

    for (size_t i = 0; i < tam; i++)
    {
        cout << lista.front() << endl;
        lista.pop_front(); // comportamento de fila
    }

    return 0;
}
