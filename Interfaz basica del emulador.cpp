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

struct PlatosDeComida{
	string nombre;
	string ingredientes;
	float precio;
	float costo;
	int cantidad;
};

// Funcion para imprimir un espacio entre el lado izquierdo de la pantalla hasta donde se indique
void imprimirEspacio(int n){
	for(int i=0; i<n; i++){
		cout << " ";
	}
}
// Función para centrar el texto
void centrar(const string& text) {
    int tamanoconsola = anchoConsola(); // ya que hallamos columnas con la funcion, le asignamos una variable al retorno
    int tamanotexto = text.length(); //"text.lenght()" halla el tamaño del texto en caracteres. le asignamos una variable de tipo int a la anchura del texto
    int espaciado = (tamanoconsola - tamanotexto) / 2; // la diferencia de ambos entre 2 es la distancia para centrar un texto
    // Imprimir espacios en blanco antes del texto
    imprimirEspacio(espaciado);
    // Imprimir el texto
    cout << text;
    
    imprimirEspacio(espaciado);
    
}

// Funcion para centrar una entrada "cin"
void centrarCin(int tamanotexto){

    int tamanoconsola = anchoConsola(); // ya que hallamos columnas con la funcion, le asignamos una variable al retorno
    int espaciado = (tamanoconsola - tamanotexto) / 2; // la diferencia de ambos entre 2 es la distancia para centrar un texto
    // Imprimir espacios en blanco antes del texto
    imprimirEspacio(espaciado);
}

// Funcion para generar una linea larga entre ambos extremos de la pantalla, ideal para separar secciones
void separador(char c){
	int tamanoconsola = anchoConsola();
	cout << endl;
	for(int i=0; i<tamanoconsola; i++){
		cout << c;
	}
}

// Funcion para enjaular un texto (genera un marco alrededor de el), solo una linea de texto, no varias
void enjaular(string text, char c){
	
	int tamanotexto = text.length();
	int anchojaula = tamanotexto+4;
	int tamanoconsola = anchoConsola();
	int espaciado = (tamanoconsola - anchojaula)/2;
	//largo de jaula es 3
	imprimirEspacio(espaciado);
	
	for(int i=0; i<anchojaula; i++){
		cout << c;
	}
	cout << endl;
	
	imprimirEspacio(espaciado);
	
	cout << c << " " << text << " " << c;
	cout << endl;
	
	imprimirEspacio(espaciado);
	
	for(int i=0; i<anchojaula; i++){
		cout << c;
	}

}

// Funcion para subrayar un texto
void subrayar(string text, char c){
	
	cout << endl;
	
	int tamanoconsola = anchoConsola();
	int tamanotexto = text.length();
	int espaciado = (tamanoconsola - tamanotexto)/2;
	
	imprimirEspacio(espaciado);
	
	for(int i=0; i<tamanotexto; i++){
		cout << c;
	}

}

// Funcion para generar una linea de un tamaño, si hay un "salto" de linea, generara entre ambos extremos de la linea un caracter mas, para generar una jaula en ese caso
void linea(int n, char s, int salto){
	int tamanoconsola = anchoConsola();
	int espaciado = (tamanoconsola - n)/2;
	
	imprimirEspacio(espaciado);
	
	for(int i=0; i<n; i++){
		cout << s;
	}
	
	// ej:   ******************	 ; salto = 0
	// 		 *				  *  ; salto = 1
	if(salto>0){
		cout << endl;
		
		imprimirEspacio(espaciado);
		
		cout << s;
		int espaciojaula = n-2;
		
		imprimirEspacio(espaciojaula);
		
		cout << s;
	} 
}

// Funcion para generar el contenido de una jaula, esto funcion se complementa con la funcion "linea"
void contenidoJaula(string text, int n, char s, int salto){
	int tamanoconsola = anchoConsola();
	int espaciado = (tamanoconsola - n)/2;
	
	imprimirEspacio(espaciado);
	
	cout << s;
	
	int tamanotexto = text.length();
	int entrelineas = n-2-tamanotexto;
	int entrelinea1 = (n-2-tamanotexto)/2;
	int entrelinea2 = entrelineas - entrelinea1;
	
	imprimirEspacio(entrelinea1);
	
	cout << text;

	imprimirEspacio(entrelinea2);
	
	cout << s;
	
	imprimirEspacio(espaciado);
	
	// *	texto	*
	if(salto>0){
		for(int i=0; i<salto; i++){
			cout << endl;
			
			imprimirEspacio(espaciado);
			
			cout << s;
			
			int espaciojaula=n-2;
			imprimirEspacio(espaciojaula);
			
			cout << s;
		}
		// *	texto	* ; salto = 0
		// *			* ; salto = 1
	}
	
}

// Funcion para eliminar una comida
void eliminarComida(PlatosDeComida arr[], int &n, int indice){
	if(indice>=0 && indice<n){
		for(int i=indice; i<n-1; i++){
			arr[i]=arr[i+1];
		}
		n--;
	} else {
		cout << "Indice no valido" << endl;
	}
}

// Funcion para enlinear un texto en el centro de la pantalla
// ej: 		*********** text ************
void enlinear(string texto, char s){
	int tamanoconsola = anchoConsola();
	int tamanotexto = texto.length();
	int tamanolinea = (tamanoconsola - tamanotexto)/2;
	
	for(int i=0; i<tamanolinea; i++){
		cout << s;
	}
	cout << " " << texto << " ";
	
	for(int i=1; i<tamanolinea; i++){
		cout << s;
	}
}
int main(){
	
	system("pause");
	setlocale(LC_ALL, ""); //parte de la liberia locale.h
	
	string texto;
	char s;
	int modalidad;
	int max= 100;
	PlatosDeComida comida[max];
	do{
		color(hConsole, 79);
		cout << endl;
		s= '*';
		separador(s);
		texto = "ESIS'S RESTAURANT";
		centrar(texto);
		s = '*';
		separador(s); cout << endl;
		
		color(hConsole, 7);
		cout << endl << endl;
		texto = "Elije el modo de juego";
		s = '*';
		enjaular(texto, s); cout << endl << endl;
		
		texto = "Quiero ser el:";
		centrar(texto);
		s= '=';
		subrayar(texto, s); cout << endl << endl;
		
		int anchoJaula=40;
		int salto=2;
		s='*';
		linea(anchoJaula, s, salto); cout << endl;
		texto = "1. DUEÑO";
		contenidoJaula(texto, anchoJaula, s, salto); cout << endl;
		texto = "2. CLIENTE";
		contenidoJaula(texto, anchoJaula, s, salto); cout << endl;
		texto = "3. DELIVERY";
		contenidoJaula(texto, anchoJaula, s, salto); cout << endl;
		texto = "4. ABANDONAR EMULADOR";
		contenidoJaula(texto, anchoJaula, s, salto); cout << endl;
		linea(anchoJaula, s, 0); cout << endl;
		
		texto = "---------------";
		centrar(texto); cout << endl;
		centrarCin(1);
		cin >> modalidad;
		cout << endl;

		char opcion;
		switch(modalidad){
			case 1:
				texto = "¡AHORA ERES EL DUEÑO DEL RESTAURANTE!";
				s= '*';
				enjaular(texto, s); cout << endl << endl;
				texto = "¿Que quieres hacer?";
				centrar(texto); cout << endl << endl;
				do{
					texto = "A) Administrar la cocina";
					centrar(texto); cout << endl << endl;
					texto = "B) Administrar el negocio";
					centrar(texto); cout << endl << endl;
					texto = "C) Administrar personal";
					centrar(texto); cout << endl << endl;
					texto = "D) Cambiar de rol";
					centrar(texto); cout << endl << endl;
					texto = "--------";
					centrar(texto); cout << endl;
					centrarCin(1);
					cin >> opcion;
					
					cout << endl;
					
					switch (opcion){
						case 'A':
							s = '-';
							separador(s);
							texto = "Entrando a la cocina...";
							enlinear(texto, s);
							separador(s); cout << endl << endl;
							texto = "Indique la accion que va a realizar";
							centrar(texto);
							s= '=';
							subrayar(texto, s); cout << endl << endl;
							do{
								anchoJaula = 40;
								salto = 0;
								s = '*';
								linea(anchoJaula, s, 2); cout << endl;
								texto = "a) Agregar una comida";
								contenidoJaula(texto, anchoJaula, s, salto); cout << endl;
								texto = "b) Eliminar una comida";
								contenidoJaula(texto, anchoJaula, s, salto); cout << endl;
								texto = "c) Actualizar una comida";
								contenidoJaula(texto, anchoJaula, s, salto); cout << endl;
								texto = "d) Ver stock del menú";
								contenidoJaula(texto, anchoJaula, s, salto); cout << endl;
								texto = "e) Salir de la cocina";
								contenidoJaula(texto, anchoJaula, s, 1); cout << endl;
								linea(anchoJaula, s, 0); cout << endl << endl;
								texto = "--------";
								centrar(texto); cout << endl;
								centrarCin(1);
								cin >> opcion;
								cout << endl;
								
								int n=0;
								switch(opcion){
									case 'a':
										if(n<=100){
											cout << "\t\t\t\t\t\tNombre: ";
											if(n>=0) cin.ignore();
											getline(cin, comida[n].nombre);
											cout << "\t\t\t\t\t\tIngredientes: ";
											getline(cin, comida[n].ingredientes);
											cout << "\t\t\t\t\t\tPrecio: ";
											cin >> comida[n].precio;
											cout << "\t\t\t\t\t\tCosto: ";
											cin >> comida[n].costo;
											cout << "\t\t\t\t\t\tCantidad: ";
											cin >> comida[n].cantidad;
										} else {
											cout << "Se introdujo el maximo de platos posibles." << endl;
										}
										cout << endl;
										break;
									case 'b':
										if(n==0){
											
										}
										break;
								}
							} while(opcion!='e');
							break;
						case 'B':
							break;
						case 'C':
							break;
						default:
							break;
					}
				} while(opcion != 'D');
				
				break;
				
			case '2':
				break;
			case '3':
				break;
			default:
				cout << "Indique el numero de las modalidades disponibles.";
				break;
		}

	} while (modalidad != 4);
	return 0;
}
