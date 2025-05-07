#include <iostream>
#include "Pessoa.h"

int main(){
    Pessoa *p = new Pessoa(18,"João");

    p->saudacao();

    return 0;
}
