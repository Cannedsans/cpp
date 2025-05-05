#include <iostream>
#include <fstream>

int main() {
    // Cria um objeto ofstream e abre o arquivo "exemplo.txt" para escrita
    std::ofstream arquivo("exemplo.txt");

    // Verifica se o arquivo foi aberto com sucesso
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para escrita!" << std::endl;
        return 1;
    }

    // Escreve no arquivo
    arquivo << "Olá, mundo!" << std::endl;
    arquivo << "Este é um exemplo de escrita em arquivo." << std::endl;

    // Fecha o arquivo
    arquivo.close();

    std::cout << "Dados escritos no arquivo com sucesso!" << std::endl;

    return 0;
}