#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include <string>
#include <iostream>

class Pessoa
{
private:
    int idade;
    std::string nome;

public:
    // Construtor com lista de inicialização
    Pessoa(int idade, const std::string &nome) : idade(idade), nome(nome) {}

    // Método de saudação
    void saudacao() const
    {
        std::cout << "Olá " << nome << "!" << std::endl;
    }
};

#endif
