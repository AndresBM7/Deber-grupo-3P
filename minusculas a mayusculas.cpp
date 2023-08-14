//trasnformar de minusculas a mayusculas.
#include <stdio.h>
#include <string.h>

void convertirMayusculas(char cadena[100]){
	for (int i = 0; i < strlen(cadena); i++) {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            cadena[i] = cadena[i] - ('a' - 'A');
        }
    }	
}

int main() {
	
    char cadena[100];
    printf("Ingresa el texto en minusculas:\n ");
    scanf("%s", &cadena);
    
    convertirMayusculas(cadena);

    printf("Convertido a mayusculas: %s", cadena);

    return 0;
}


