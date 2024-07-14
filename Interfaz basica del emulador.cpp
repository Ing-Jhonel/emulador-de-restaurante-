#include <iostream>
#include <windows.h>
#include <locale.h> //libreria para incluir el idioma español

using namespace std;


namespace Console {
    enum Color {
        BLACK = 0,
        BLUE = 1,
        GREEN = 2,
        CYAN = 3,
        RED = 4,
        MAGENTA = 5,
        BROWN = 6,
        LIGHTGRAY = 7,
        DARKGRAY = 8,
        LIGHTBLUE = 9,
        LIGHTGREEN = 10,
        LIGHTCYAN = 11,
        LIGHTRED = 12,
        LIGHTMAGENTA = 13,
        YELLOW = 14,
        WHITE = 15
    };

    void setColor(Color textColor, Color bgColor) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
    }

    void resetColor() {
        setColor(LIGHTGRAY, BLACK);
    }
}


// Función para obtener el ancho de la consola
int anchoConsola() {
    CONSOLE_SCREEN_BUFFER_INFO csbi; //declara variable de tipo CONSOLE_SCREEN_BUFFER_INFO (es una estructura definida en la libreria windows.h)
    // esta contiene info sobre el bufer de la pantalla de consola, como las dimensiones (lo que necesitamos)
    int columnas; //declara una variable "columnas" de tipo int

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi); //con "GetStdHandle(STD_OUTPUT_HANDLE)" obtenemos un identificador para el bufer
    //de
    // Esta función obtiene información detallada sobre el búfer de pantalla de la consola y la guarda en la estructura csbi.
    columnas = csbi.srWindow.Right - csbi.srWindow.Left + 1; //csbi.srWindow.Right y csbi.srWindow.Left: Estas son propiedades de la estructura CONSOLE_SCREEN_BUFFER_INFO. 
	// srWindow es una estructura dentro de csbi que representa la ventana de visualización actual de la consola.
	// csbi.srWindow.Right representa la coordenada más a la derecha de la ventana de la consola.
	// csbi.srWindow.Left representa la coordenada más a la izquierda de la ventana de la consola.
	
	//ej
	
	// si la consola mide 100 caracteres, para que la pc lo sepa, entonces:
	// csbi.srWindow.Right = 99
	// csbi.srWindow.Left = 0
	// 	columnas = 99 +1 = 100, 
    return columnas;
}

// Función para centrar el texto
void centrar(const string& text) {
    int tamanoconsola = anchoConsola(); // ya que hallamos columnas con la funcion, le asignamos una variable al retorno
    int tamanotexto = text.length(); //"text.lenght()" halla el tamaño del texto en caracteres. le asignamos una variable de tipo int a la anchura del texto
    int espaciado = (tamanoconsola - tamanotexto) / 2; // la diferencia de ambos entre 2 es la distancia para centrar un texto

    // Imprimir espacios en blanco antes del texto
    for (int i = 0; i < espaciado; ++i) {
        cout << " ";
    }

    // Imprimir el texto
    cout << text;
    
    for (int i = 0; i < espaciado; ++i) {
        cout << " ";
    }
}

void centrarCin(int tamanotexto){

    int tamanoconsola = anchoConsola(); // ya que hallamos columnas con la funcion, le asignamos una variable al retorno
    int espaciado = (tamanoconsola - tamanotexto) / 2; // la diferencia de ambos entre 2 es la distancia para centrar un texto

    // Imprimir espacios en blanco antes del texto
    for (int i = 0; i < espaciado; ++i) {
        cout << " ";
    }
}

void separador(char c){
	int tamanoconsola = anchoConsola();
	cout << endl;
	for(int i=0; i<tamanoconsola; i++){
		cout << c;
	}
}

void jaulaCentrada(string text, char c){
	
	int tamanotexto = text.length();
	int anchojaula = tamanotexto+4;
	int tamanoconsola = anchoConsola();
	int espaciado = (tamanoconsola - anchojaula)/2;
	//largo de jaula es 3

	for(int i=0; i<espaciado; i++){
		cout << " ";
	}
	for(int i=0; i<anchojaula; i++){
		cout << c;
	}
	for(int i=0; i<espaciado; i++){
		cout << " ";
	}
	cout << endl;
	for(int i=0; i<espaciado; i++){
		cout << " ";
	}
	
	cout << c << " " << text << " " << c;
	
	for(int i=0; i<espaciado; i++){
		cout << " ";
	}
	cout << endl;
	
	for(int i=0; i<espaciado; i++){
		cout << " ";
	}
	for(int i=0; i<anchojaula; i++){
		cout << c;
	}
	for(int i=0; i<espaciado; i++){
		cout << " ";
	}
}

void subrayado(string text, char c){
	
	cout << endl;
	
	int tamanoconsola = anchoConsola();
	int tamanotexto = text.length();
	int espaciado = (tamanoconsola - tamanotexto)/2;
	for(int i=0; i<espaciado; i++){
		cout << " ";
	}
	for(int i=0; i<tamanotexto; i++){
		cout << c;
	}
	
	for(int i=0; i<espaciado; i++){
		cout << " ";
	}
}

int main(){
	
	system("pause");
	
	using namespace Console;

	setlocale(LC_ALL, ""); //parte de la liberia locale.h
	string texto;
	char s;
	int modalidad;
	do{
		setColor(WHITE, RED);
		s= '*';
		separador(s);
		texto = "ESIS'S RESTAURANT";
		centrar(texto);
		s = '*';
		separador(s); cout << endl << endl;
		resetColor();
		
		setColor(BLACK, YELLOW);
		texto = "Elije el modo de juego";
		s = '*';
		jaulaCentrada(texto, s); cout << endl << endl;
		
		texto = "Quiero ser el:";
		centrar(texto);
		s= '=';
		subrayado(texto, s); cout << endl << endl;
		
		texto = "1. DUEÑO";
		centrar(texto); cout << endl << endl;
		texto = "2. CLIENTE";
		centrar(texto); cout << endl << endl;
		texto = "3. DELIVERY";
		centrar(texto); cout << endl << endl;
		texto = "4. ABANDONAR EMULADOR";
		centrar(texto); cout << endl << endl;
		
		texto = "---------------";
		centrar(texto); cout << endl;
		centrarCin(1);
		cin >> modalidad;
		resetColor();

	} while (modalidad != 4);
	return 0;
}

