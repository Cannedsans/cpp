#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> fila;

    fila.push(10);
    fila.push(20);
    fila.push(30);
    cout << "Ultima carta.:" << fila.back() << endl;

    while (!fila.empty())
    {
        cout << "Proximo da fila:" << fila.front() << endl;
        fila.pop();
    }

    return 0;
}
