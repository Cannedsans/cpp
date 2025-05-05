#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Cria um objeto ifstream e abre o arquivo "exemplo.txt" para leitura
    std::ifstream arquivo("exemplo.txt");

    // Verifica se o arquivo foi aberto com sucesso
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para leitura!" << std::endl;
        return 1;
    }

    std::string linha;

    // Lê o arquivo linha por linha
    while (std::getline(arquivo, linha)) {
        std::cout << linha << std::endl;
    }

    // Fecha o arquivo
    arquivo.close();

    return 0;
}