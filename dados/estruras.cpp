#include <iostream>
#include <string> // Para usar strings com mais segurança

using namespace std;

struct Pessoa
{
    int id;
    string nome;
    int idade;

    // Método para imprimir os dados
    void imprimir()
    {
        cout << "ID.....: " << id << endl
             << "Nome...: " << nome << endl
             << "Idade..: " << idade << endl;
    }

    // Método para inicializar os dados (opcional)
    void inicializar(int novo_id, string novo_nome, int nova_idade)
    {
        id = novo_id;
        nome = novo_nome;
        idade = nova_idade;
    }
};

int main()
{
    Pessoa pessoa;

    // Usando o método para inicializar (opcional)
    pessoa.inicializar(1, "João", 18);

    // Chamando o método para imprimir
    pessoa.imprimir();

    return 0;
}
