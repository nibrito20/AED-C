#include <stdio.h>

int potencia(int base, int exp){
    if(exp == 0){
        return 1;
    }
    exp--;
    return base * potencia(base, exp);
}

int main(){
    printf("%d\n", potencia(5,3));

    return 0;
}