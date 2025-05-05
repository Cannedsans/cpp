#include <iostream>

namespace MeuEspaco
{
    void saudacao()
    {
        std::cout << "Olá do MeuEspaco!" << std::endl;
    }
}

int main()
{
    MeuEspaco::saudacao(); // Acessando a função dentro do namespace
    return 0;
}
