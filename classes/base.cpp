#include <iostream>

using namespace std;

class Pessoa
{
public:
    int idade = 1;

    void ini(int i)
    {
        idade += i;
    }
};

int main()
{
    Pessoa *av = new Pessoa();
    av->ini(40);
    cout << av->idade << endl;
    return 0;
}
