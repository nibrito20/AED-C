#include <stdio.h>

int potencia(int base, int exp){
    if(exp == 0){
        return 1;
    }

    if(exp % 2 == 0){
        return potencia(base*base, exp/2);
    } else{
        return base * potencia(base, exp-1);
    }
    
}

int main(){
    printf("%d\n", potencia(5,3));

    return 0;
}