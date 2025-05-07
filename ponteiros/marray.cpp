#include <iostream>

using namespace std;

int main(){

    int *p;
    int array[10];

    p = array; // recebe o endereço do primeiro elemento &array[0] em outras palavra.

    cout << p << endl;

    *(p++); // incremento de posição do array
    
    cout << p << endl; // endereço com 4 bytes de diferença

    return 0;
}
