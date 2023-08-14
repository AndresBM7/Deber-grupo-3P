#include <stdio.h>
#include <string.h>
#include <locale.h>

void CombertirAMinusculas(char cadena[100]){
	for (int i = 0; i < strlen(cadena); i++) {
        if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
            cadena[i] = cadena[i] + ('a' - 'A');
        }
    }	
}

int main() {
	setlocale(LC_ALL,"spanish");
	
    char cadena[100];
    printf("Ingresa el texto que desea cambiar a minúsculas: ");
    fflush(stdin);
    gets(cadena);
    
    CombertirAMinusculas(cadena);

    printf("Cadena con letras minúsculas: %s", cadena);

    return 0;
}
