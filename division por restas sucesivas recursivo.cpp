#include <stdio.h>

int dividir(int dividendo, int divisor){
    if(dividendo<divisor){
        return 0;
    }
	else{
        return 1 + dividir(dividendo-divisor,divisor);
    }
}

int main() {
    int dividendo, divisor;
    
    printf("Ingrese el dividendo:\n");
    scanf("%d", &dividendo);
    
    printf("Ingrese el divisor:\n");
    scanf("%d", &divisor);
    
    if (divisor==0){
        printf("No se puede dividir para cero.\n");
    }
	else{
        int cociente=dividir(dividendo, divisor);
        printf("Resultado: %d\n", cociente);
    }
    
    return 0;
}

