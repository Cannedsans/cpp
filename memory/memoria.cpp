#include <iostream>
#include <cstring> // Para strcpy
using namespace std;

int main()
{
    // 1. Alocação de um único inteiro
    int *numero = new int(10); // Aloca e inicializa com 10
    cout << "Inteiro alocado: " << *numero << endl;
    delete numero; // Libera a memória

    // 2. Alocação de um array de caracteres (string)
    char *texto = new char[50]; // Aloca 50 caracteres
    strcpy(texto, "Alocação dinâmica em C++");
    cout << "Texto: " << texto << endl;
    delete[] texto; // Libera o array

    // 3. Alocação de um array de inteiros
    int tamanho;
    cout << "Digite o tamanho do array: ";
    cin >> tamanho;

    int *array = new int[tamanho]; // Aloca array dinâmico

    // Preenche o array
    for (int i = 0; i < tamanho; i++)
    {
        array[i] = i * 10;
    }

    // Imprime os valores
    cout << "Array: ";
    for (int i = 0; i < tamanho; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array; // Libera o array

    return 0;
}
