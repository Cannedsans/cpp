#include <iostream>
    
void recuo(int n);

int main(){
    int n = 10;
    recuo(n);
}

void recuo(int n){
    std::cout << n << std::endl;
    if (n <= 0){
        return ;
    }else{
        n--;
        recuo(n);
    }
}