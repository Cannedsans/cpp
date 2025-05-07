#include <iostream>

using namespace std;

int main(){
    int *pont; // criação do ponteiro
    int num = 200;

    pont = &num; // operador de ponteiro &

    cout << pont << endl; // endereço
    cout << *pont << endl; //valor de num
    return 0;
}
