#include <iostream>

int main(){
    float n1,n2,med = 0;
    std::cout << "Digite o primeiro número.:";
    std::cin >> n1;

    std::cout << "Digite o segundo número.:";
    std::cin >> n2;

    med = (n1+n2)/2;

    std::cout << "Sua média é .:" << med;
    return 0;
}