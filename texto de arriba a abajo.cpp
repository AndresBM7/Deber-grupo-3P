#include <stdio.h>
#include <windows.h>
#include <conio.h>

// Declaración de la función gotoxy
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(){
    int i = 0;
    int Teclapresionada = 0;

    while(1){
        system("cls");
        gotoxy(40, i++); // Mover el cursor a la fila i+1
        printf(" TEXTO EN MOVIMIENTO");

        if (kbhit()) {
            Teclapresionada = getch();
            if (Teclapresionada == 13) // Tecla enter
                break;
        }

        i = (i++) % 20; // Mover hacia arriba y reiniciar en la parte inferior
        Sleep(100); // Esperar 100 ms (0.1 segundos)
    }
    

    return 0;
}
