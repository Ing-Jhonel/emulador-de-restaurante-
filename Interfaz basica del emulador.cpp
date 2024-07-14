#include <iostream>
#include <windows.h>
#include <locale.h> //libreria para incluir el idioma español
#define color SetConsoleTextAttribute

using namespace std;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
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

void enjaular(string text, char c){
	
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
	cout << endl;
	
	for(int i=0; i<espaciado; i++){
		cout << " ";
	}
	
	cout << c << " " << text << " " << c;
	cout << endl;
	
	for(int i=0; i<espaciado; i++){
		cout << " ";
	}
	for(int i=0; i<anchojaula; i++){
		cout << c;
	}

}

void subrayar(string text, char c){
	
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

}

int main(){
	
	system("pause");

	setlocale(LC_ALL, ""); //parte de la liberia locale.h
	string texto;
	char s;
	int modalidad;
	do{
		color(hConsole, 79);
		cout << endl;
		s= '*';
		separador(s);
		texto = "ESIS'S RESTAURANT";
		centrar(texto);
		s = '*';
		separador(s); cout << endl;
		
		color(hConsole, 224);
		cout << endl << endl;
		texto = "Elije el modo de juego";
		s = '*';
		enjaular(texto, s); cout << endl << endl;
		
		texto = "Quiero ser el:";
		centrar(texto);
		s= '=';
		subrayar(texto, s); cout << endl << endl;
		
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
		
		char opcion;
		switch(modalidad){
			case 1:
				texto = "¡AHORA ERES EL DUEÑO DEL RESTAURANTE!";
				s= '*';
				enjaular(texto, s); cout << endl << endl;
				texto = "¿Que quieres hacer?";
				centrar(texto); cout << endl << endl;
				do{
					texto = "A) Administrar cocina";
					centrar(texto); cout << endl << endl;
					cin >> opcion;
				} while(opcion == 'E');
				break;
				
			case '2':
				break;
			case '3':
				break;
			Default:
				cout << "Indique el numero de las modalidades disponibles.";
				break;
		}

	} while (modalidad != 4);
	return 0;
}

