#include <iostream>

void result(std::string n);

int main(){

    std::cout << "Bem vindo ao pedra papel e tezoura" <<std::endl;
    while (true){
        unsigned int opc = 0;
        std::cout << "Digite uma opção para o jogo" <<std::endl;
        std::cout << "[1] Pedra" <<std::endl;
        std::cout << "[2] Papel" <<std::endl;
        std::cout << "[3] Tezoura" <<std::endl;
        std::cout << "[n] Sair do jogo" <<std::endl;
        std::cin >> opc;
        switch (opc){
        case 1:
            result("Pedra");
            break;
        case 2:
            result("Papel");
            break;
        case 3:
            result("Tezoura");
            break;
        default:
            return 0;
            break;
        }
    }
    
    return 0;
}

void result(std::string resp){
    std::string moves[] = {"Pedra","Papel","Tezoura"};
    unsigned int pc = rand() % 3; 
    std::cout << "voce jogou.:" << resp <<"e..." << std::endl;
    if (resp == moves[pc]){
        std::cout << "Empate!" <<std::endl;
    }else if (resp == "Pedra" && moves[pc] == "Papel"){
        std::cout << "Perdeu!" <<std::endl;
    }else if (resp == "Pedra" && moves[pc] == "Tezoura"){
        std::cout << "Ganhou!" <<std::endl;
    }else if (resp == "Papel" && moves[pc] == "Pedra"){
        std::cout << "Ganhou!" <<std::endl;
    }else if (resp == "Papel" && moves[pc] == "Tezoura"){
        std::cout << "Perdeu!" <<std::endl;
    }else if (resp == "Tezoura" && moves[pc] == "Pedra"){
        std::cout << "Perdeu!" <<std::endl;
    }else if (resp == "Tezoura" && moves[pc] == "Papel"){
        std::cout << "Ganhou!" <<std::endl;
    }
    return;
}