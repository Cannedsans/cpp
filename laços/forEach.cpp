#include <iostream>

int main(){
    int nums[] = {1,2,3,4,5,6,7,8,9,10};

    for (int num :nums){
        std::cout << "num:" << num << std::endl;
    }
    
    return 0;
}