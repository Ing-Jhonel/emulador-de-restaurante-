#include <windows.h>
#include <iostream>

using namespace std;

void setColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

void resetColor() {
    setColor(7, 0); // Texto gris claro sobre fondo negro
}

int main() {
    setColor(2, 1); // Texto verde sobre fondo azul

    cout << "Texto con color de texto verde y fondo azul" << endl;

    resetColor();
    
        setColor(2, 1); // Texto verde sobre fondo azul

    cout << "Texto con color de texto verde y fondo azul" << endl;

    resetColor();
    return 0;
}



