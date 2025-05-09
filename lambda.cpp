#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int y = 20;

    auto multiplica_e_soma = [x, &y](int z) -> int
    {
        y = y * 2;    // Captura 'y' por referência (modificável)
        return x * z; // Captura 'x' por valor (cópia)
    };

    cout << "Resultado: " << multiplica_e_soma(3) << endl; // Saída: 30 (10 * 3)
    cout << "Novo y: " << y << endl;                       // Saída: 40 (20 * 2)
    return 0;
}
