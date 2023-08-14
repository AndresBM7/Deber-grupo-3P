#include <stdio.h>
#include <iostream>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

int dividir(int, int);
int potencia(int, int);
void CombertirAMinusculas(char[100]);
void gotoxy(int, int);
void convertirMayusculas(char[100]);
void convertirAMayusculas(char[]);
void imprimirMayusculasInterca_ladas(const char[]);

void CombertirAMinusculas(char cadena[100]){
	for (int i = 0; i < strlen(cadena); i++) {
        if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
            cadena[i] = cadena[i] + ('a' - 'A');
        }
    }	
}

void convertirMayusculas(char cadena[100]){
	for (int i = 0; i < strlen(cadena); i++) {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            cadena[i] = cadena[i] - ('a' - 'A');
        }
    }	
}

void convertirAMayusculas(char cadena[]) {
    strupr(cadena);  // Convertir la cadena a mayúsculas
}

void imprimirMayusculasInterca_ladas(const char cadena[]) {
    bool esMayuscula = true;
    for (size_t i = 0; i < strlen(cadena); i++) {
        if (esMayuscula) {
            printf("%c", cadena[i]);
        } else {
            printf("%c", tolower(cadena[i]));
        }
        esMayuscula = !esMayuscula;  // Alternar entre mayúsculas y minúsculas
    }
    printf("\n");
}

int potencia(int base, int exponente){
	if(exponente == 0){
		return 1;
	} 
	else{
		return base * potencia(base, exponente - 1);
	}
}

int dividir(int dividendo, int divisor){
    if(dividendo<divisor){
        return 0;
    }
	else{
        return 1 + dividir(dividendo-divisor,divisor);
    }
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(){
	int opcion;
		
	do{	
		system("color 6");
		printf("___________________________________________________________\n\n");
		printf("\t   ~UNIVERSIDAD DE LAS FUERZAS ARMADAS~\n");
		printf("\t\t\t  ~ESPE~\n");
		printf("\t\t        ~NRC: 9890~\n");
		printf("\t\t     ~DEBER NRO.6 3P~\n");
		printf("-Baraja Milena~\n-Buitron Andres~\n");
		printf("___________________________________________________________\n");
		
	
		printf("\nSe presentan las siguientes opciones:\n\n");
		printf("1. - Transformar de mayusculas a minusculas	  -\n");
		printf("2. - Trasnformar de minusculas a mayusculas	  -\n");
		printf("3. - Transformar mayusculas minusculas alternadas -\n");
		printf("4. - Elevar una base a una potencia		  -\n");
		printf("5. - dividir dos numeros con restas sucesivas  	  -\n");
		printf("6. - Frase que va de arriba hacia abajo		  -\n");
		printf("7. - Salir				  	  -\n");
		
		printf("\nIngrese la opcion a ejecutar: ");
		scanf("%d", &opcion);
	
	
		switch(opcion){
			case 1:{
				system("cls");
				setlocale(LC_ALL,"spanish");
		
	    		char cadena[100];
	    		printf("Ingresa el texto que desea cambiar a minúsculas: ");
			    fflush(stdin);
			    gets(cadena);
			    
			    CombertirAMinusculas(cadena);
			
			    printf("Cadena con letras minúsculas: %s\n", cadena);
				system("pause");
				system("cls");
				break;
			}
			case 2:{
				system("cls");
				char cadena[100];
			    printf("Ingresa el texto en minusculas:\n ");
			    scanf("%s", &cadena);
			    
			    convertirMayusculas(cadena);
			
			    printf("Convertido a mayusculas: %s\n", cadena);
			    system("pause");
				system("cls");
				break;
			}
			case 3:{
				system("cls");
				char cadena[100];
			    printf("Ingrese una frase u oracion: ");
			    scanf("%s", cadena);  // Leer la cadena hasta que se ingrese Enter
			
			    convertirAMayusculas(cadena);
			    imprimirMayusculasInterca_ladas(cadena);
			    system("pause");
				system("cls");
				break;
			}
			case 4:{
				system("cls");
				int base, exponente;
				printf("Ingrese la base: ");
				scanf("%d", &base);
				printf("Ingrese el exponente: ");
				scanf("%d", &exponente);
			
				int resultado = potencia(base, exponente);
				printf("El resultado es: %d\n", resultado);
				system("pause");
				system("cls");
				break;
			}
			case 5:{
				system("cls");
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
			    system("pause");
				system("cls");
				break;
			}
			case 6:{
				system("cls");
				system("color D");
				char cadenamov[50];
				printf("Ingrese la frase que quiera:\n");
				fflush(stdin);
				gets(cadenamov);
				
				int i = 0;
			    int Teclapresionada = 0;
			
			    while(1){
			        system("cls");
			        gotoxy(0,25);
			        printf("\t\t     ~~Presione cualquier tecla para detener~~");
			        gotoxy(40, i++); // Mover el cursor a la fila i+1
			        printf("%s\n\n",cadenamov);
			
			        if (kbhit()) {
			            Teclapresionada = getch();
			            if (Teclapresionada == 13) // Tecla enter
			                break;
			        }
			
			        i = (i++) % 20; // Mover hacia arriba y reiniciar en la parte inferior
			        Sleep(100); // Esperar 100 ms (0.1 segundos)
			    }
			    system("pause");
				system("cls");
				break;
			}
			case 7:{
				system("cls");
				system("color 4");
				printf("\n----------Saliendo del programa, un buen dia----------\n");
				break;
			}
		}
	}while(opcion!=7);
}
