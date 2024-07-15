#define color SetConsoleTextAttribute
#include <iostream>
#include <windows.h>
using namespace std;

int main(){
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for(int i=0; i<243; i++){
		color(hConsole, i);
		cout << i << " Prueba de color" << endl;
	}
	return 0;
}

