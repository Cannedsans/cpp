#include <iostream>

using namespace std;

void somar(float *n1, float n2); // prototipação

int main()
{
    float num = 0;
    somar(&num, 15); // enviando o endereço de num

    cout << num << endl; // saída: 15
    return 0;
}

void somar(float *n1, float n2){
    *n1 += n2; // modifica a var num somando n2
}
