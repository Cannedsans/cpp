#include <iostream>

int main(){
    enum DiaSemana
    {
        Segunda,
        Terca = 300,
        Quarta
    };
    DiaSemana hoje = Terca;

    std::cout << hoje << std::endl;
}
