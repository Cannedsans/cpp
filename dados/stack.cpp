#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<string> cartas;

    cout << "Vazio? .:" << cartas.empty() << endl;
    cout << "Então iremos adicionar elementos" << endl;
    cartas.push("Valetes"); // fundo
    cartas.push("Copas");
    cartas.push("Paus");
    cartas.push("ouros"); // topo
    cout << "Vazio? .:" << cartas.empty() << endl;
    cout << "Tamanho do baralho .:" << cartas.size() << " cartas\n"
         << endl;

    cout << "Carta do topo.: " << cartas.top() << endl;
    cartas.pop();
    cout << "nova Carta do topo.: " << cartas.top() << endl;

    cout << "Esvaziando o baralho" << endl;

    while (!cartas.empty()){
        cout << cartas.top();
        cartas.pop();
    }
    cout << "Vazio? .:" << cartas.empty() << endl;
    return 0;
}
