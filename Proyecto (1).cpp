// Solución proyecto

/**
* \fn void aFunction(void)
* \brief This function is a function
*/

// Importar librerías
#include<iostream>
using namespace std;

// Declaración de constantes
int const FILAS=4;
int const COLUMNAS=5;

// Declaración de procedimientos
void inicializarMatrices(bool disponibilidad[FILAS][COLUMNAS],int peso[FILAS][COLUMNAS]);
void mostrarDisponibilidadBarco(bool disponibilidad[FILAS][COLUMNAS]);
void imprimirMatrizTexto(string matriz[FILAS][COLUMNAS]);
void CantidadDeContenedores (bool disponibilidad[FILAS][COLUMNAS]);
void OrdenamientoContenedoresPorPuerto (int cantidadContenedores[],string  nombresPuertos[],int numPuertos);
//Declaración de funciones
string marcaMasPesada(int pesos[FILAS][COLUMNAS],string marcas[FILAS][COLUMNAS]);
float PromedioDePeso (int pesos[FILAS][COLUMNAS]);
int FilaMasCarga (int pesos[FILAS][COLUMNAS]);
int ColumnaMenosCarga (int pesos[FILAS][COLUMNAS]);
int CantidadContenedoresClase (string claseArticulo[FILAS][COLUMNAS],string ArticuloAOperar);
float PromedioPesoPorPuerto (string puerto[FILAS][COLUMNAS],string PuertoAOperar, int pesos[FILAS][COLUMNAS]);
string NombreEmpresaMasPeso (string marca[FILAS][COLUMNAS], int peso[FILAS][COLUMNAS]);
int PesoContenedorMasLiviano (int peso[FILAS][COLUMNAS]);


// PROGRAMA PRINCIPAL
int main()
{	
	// Variables locales	
	string PuertoAOperar="";
	string ArticuloAOperar="";
	bool disponibilidad[FILAS][COLUMNAS]; // Controla cuales celdas del barco están disponibles
	string marca[FILAS][COLUMNAS];
	int peso[FILAS][COLUMNAS];
	string puertoOrigen[FILAS][COLUMNAS];
	char tipoArticulo[FILAS][COLUMNAS];
	

	string marcaPesada="";
	
	//Variables costos
	int valorRecaudado=0;
	int contadorContenedores=0;
	
	
	

	// Inicializar valores en matrices
	inicializarMatrices(disponibilidad,peso);
	
	/**********
	* LLENADO DE BARCO
	***********/
		
	// Pedir número de puertos (N)
	int numPuertos=0;
	cout<<"Ingrese el numero de puertos"<<endl;
	cin>>numPuertos;
	
	
	// Pedir nombre para cada puerto
	string  nombresPuertos[numPuertos]={""};
	for (int i=0;i<numPuertos;i++){
		cout<<"Ingrese el nombre del puerto " <<i+1<<endl;
		cin>>nombresPuertos[i];
	}
	
	// Preguntar la cantidad de contenedores por puerto (cantidadContenedores)
	int cantidadContenedores[numPuertos];
	for (int i=0;i<numPuertos;i++)
	{
		
		// Mostrar coordenadas de celdas disponibles en el barco
		mostrarDisponibilidadBarco(disponibilidad);
		
		// Detallar cantidad de contenedores a ingresar
		cout<<"Ingrese la cantidad de contenedores para el puerto " << i+1 << " llamado " <<nombresPuertos[i] << endl;
		cin>>cantidadContenedores[i];
		
		
		// Preguntar por la posición de cada contenedor
		for (int c=0;c<cantidadContenedores[i];c++)
		{
			
			int posicionFila = 0, posicionColumna = 0;
			
			// Preguntar hasta que las coordenadas sean válidas
			do{
				cout << "Ingrese FILA del contenedor " << c+1 << " del puerto " << nombresPuertos[i] << ": " ;
				cin >> posicionFila;
				cout << "Ingrese COLUMNA del contenedor " << c+1 << " del puerto " << nombresPuertos[i] << ": " ;
				cin >> posicionColumna;
				
			} while( posicionFila >= 4 || posicionFila < 0 ||
					 posicionColumna >= 5 || posicionColumna < 0 ||
					 disponibilidad[posicionFila][posicionColumna] == 0 );
			
			
			
				 
					 
			
			// La celda está disponible
			cout << "La posicion del contendor es valida." << endl;
			
			// Asignar el contenedor como ocupado
			disponibilidad[posicionFila][posicionColumna] = 0;
			
			// Preguntar por marca
			marca[posicionFila][posicionColumna]="";
			
			cout<<"Ingrese la marca del contenedor en la posicion: "<<posicionFila<<","<<posicionColumna<<endl;
		    cin>>marca[posicionFila][posicionColumna];
		    	
				
			
			
			
			// Preguntar por peso (Corregir)
			peso[posicionFila][posicionColumna]=0;
		
			cout<<"Ingrese el peso del contenedor en la posicion: "<<posicionFila<<","<<posicionColumna<<endl;
			cin>>peso[posicionFila][posicionColumna];
				
			
					
			
			
			
			
			// Preguntar por puerto origen (Corregir)
			puertoOrigen[posicionFila][posicionColumna]="";
			
			cout<<"Ingrese el puerto de origen del contenedor en la posicion: "<<posicionFila<<","<<posicionColumna<<endl;
			cin>>puertoOrigen[posicionFila][posicionColumna];
			
			
			
			// Preguntar por tipo articulo(Corregir)
			tipoArticulo[posicionFila][posicionColumna];
			
			cout<<"Ingrese el tipo de articulo (A,B o C) del contenedor en la posicion: "<<posicionFila<<","<<posicionColumna<<endl;
			cout<<"Tipo A (Alimentos)"<<endl;
			cout<<"Tipo B (Dispositivos electronicos)"<<endl;
			cout<<"Tipo C (Ropa y demas textiles)"<<endl;
			cin>>tipoArticulo[posicionFila][posicionColumna];

// Mostrar información con porcentaje de ocupación
            float acumulador=0;
            float porcentajeOcupacion=0.0;
		    for(int i=0;i<FILAS;i++){
		  	    for(int j=0;j<COLUMNAS;j++){
		  		
		  	    	if(disponibilidad[i][j]==0)
				    {
				   		acumulador=acumulador+1;	
				    }
				}
		  	}
//Calcular porcentaje de ocupación	
           	porcentajeOcupacion=(acumulador/(FILAS*COLUMNAS))*100;
		 	cout<<"El porcentaje de ocupacion actual es de: "<<porcentajeOcupacion<<"%"<<endl; 
		 	
		 	

            
            
		    		
		}
	
//Valor recaudado por puerto
               valorRecaudado=0;
		       for(int i=0;i<FILAS;i++){
		  	    	for(int j=0;j<COLUMNAS;j++){
		  			   
		  	    		if((i==1 or i==2) and (j>=1 and j<=3) and disponibilidad[i][j]==0){
		  	    			valorRecaudado=valorRecaudado+300;
					  	}
					  	else if((i==0 or i>2) and (j==0 or j==4) and disponibilidad[i][j]==0 ){
					  		valorRecaudado=valorRecaudado+100;
					  	}
					}	
		  		}
		  	cout<<"El valor recaudado en el puerto actual es de: $"<<valorRecaudado<<endl;
		
			

	}
     
	//Cantidad de contenedores ingresados 
	
	for(int i=0;i<FILAS;i++){
		for (int j=0;j<COLUMNAS;j++){
			if(disponibilidad[i][j]==0){
				contadorContenedores=contadorContenedores+1;
				
			}
		}
	}
	cout<<"Cantidad de contenedores ingresados al barco fueron: "<<contadorContenedores<<endl;
	
	
	
	//Marcas con contenedores en zona economica
	 
    
	for(int i=0;i<FILAS;i++){
		for(int j=0; j<COLUMNAS;j++){
			if((i==0 or i>2) and (j==0 or j==4) and disponibilidad[i][j]==0){
				cout<<"Marcas con contenedores en la zona ECONOMICA "<<marca[i][j]<<endl;
			}
		}
	}
	//marcas con contenedores en zona PREMIUM
	for(int i=0;i<FILAS;i++){
		for(int j=0;j<COLUMNAS;j++){
			if((i==1 or i==2) and (j>=1 and j<=3) and disponibilidad[i][j]==0){
				cout<<"Marcas con contenedores en la zona PREMIUM "<<marca[i][j]<<endl;
			}
		}
	}
	
	// Nombre de empresa con contenedores y valor a pagar
	string empresa="";
	int contadorEconomico=0;
	int contadorPremium=0;
	int precioEconomico=0;
	int precioPremium=0;
	int valorTotal=0;
	cout<<"Ingrese el nombre de la empresa de la cual desea ver la posición de los contenedores y el valor recaudado"<<endl;
	cin>>empresa;
	for(int i=0;i<FILAS;i++){
		for(int j=0;j<COLUMNAS;j++){
			if(empresa==marca[i][j]){
				if((i==1 or i==2) and (j>=1 and j<=3) and disponibilidad[i][j]==0){
		  	    			contadorPremium++;
		  	    			
					  	}
					  	else if((i==0 or i>2) and (j==0 or j==4) and disponibilidad[i][j]==0 ){
					  		contadorEconomico++;
					  		
					  	}
			}
			
		}
	}
	precioPremium=contadorPremium*300;
	cout<<"La cantidad de contenedores en zona premium: "<<contadorPremium<<" Con un valor de: $"<<precioPremium<<endl;
	precioEconomico=contadorEconomico*100;
	cout<<"La cantidad de contenedores en zona economica: "<<contadorEconomico<<" Con un valor de: $"<<precioEconomico<<endl;
	valorTotal=precioPremium+precioEconomico;
	cout<<"El valor total a pagar es de: $"<<valorTotal<<endl;

	
	
	
	/**********
	* INFORMACIÓN DE CADA PUERTO
	***********/
	
	// 
	
	//
	
	
	/**********
	* INFORMACIÓN DE CADA PUERTO
	***********/
	OrdenamientoContenedoresPorPuerto (cantidadContenedores,nombresPuertos,numPuertos);
	CantidadDeContenedores (disponibilidad);
	
	//Determine la marca del contenedor mas pesado

	
	cout<<"El promedio de peso del barco en los lugares ocupados es: "<<PromedioDePeso (peso)<<endl;
	
	cout<<"La fila donde hay mas carga es: "<<FilaMasCarga (peso)<<endl;
	
	cout<<"La columna con menos carga es: "<<ColumnaMenosCarga (peso)<<endl;
	
	cout<<"Ingrese la clase de la que desea saber cuantos contenedores hay en el barco"<<endl;
	cin>>ArticuloAOperar;

	cout<<"La cantidad de contenedores para la clase ingresada es "<<CantidadContenedoresClase<<endl;

	cout<<"Ingrese el nombre del puerto que desea saber su promedio de peso"<<endl;
	cin>>PuertoAOperar;
	cout<<"El promedio de peso de "<<PuertoAOperar<<" es :"<<PromedioPesoPorPuerto<<endl;
	
	cout<<"La marca mas pesada es: "<< NombreEmpresaMasPeso (marca,peso)<<endl;
	
	cout<<"El contenedor mas liviano pesa: "<<PesoContenedorMasLiviano (peso)<<endl;
	
	
	return 0;
}


/****************************
* Implementación de funciones
****************************/

/*
Inicializar los valores de las matrices
*/
void inicializarMatrices(bool disponibilidad[FILAS][COLUMNAS],int peso[FILAS][COLUMNAS]){
	for(int i=0;i<FILAS;i++){
		for(int j=0;j<COLUMNAS;j++){
			disponibilidad[i][j]=1;
			peso[i][j]=0;
		}
	}
}

/*
Función para mostrar el barco, y qué posiciones están disponibles.
*/
void mostrarDisponibilidadBarco(bool disponibilidad[FILAS][COLUMNAS])
{
	// Imprimir barco
	cout << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "\t DISPONIBILIDAD BARCO: [fila,col]=estado" << endl;
	cout << "-------------------------------------------------" << endl;
	for(int i=0; i<FILAS; i++)
	{
		cout << "|";
		for(int j=0; j<COLUMNAS; j++)
		{
			cout << "\t[" << i << "," << j << "]=" << disponibilidad[i][j] ;
		}
		cout << "\t|" << endl;
	}
	cout << "-------------------------------------------------" << endl;
	cout << "  Estado >>  1=Disponible \t 0=Ocupado" << endl;
}


string marcaMasPesada(int pesos[FILAS][COLUMNAS],string marcas[FILAS][COLUMNAS]){
	int mayor=INT_MIN;
	string respuesta="";
	for(int i=0;i<FILAS;i++){
		for(int j=0;j<COLUMNAS;j++){
			if(pesos[i][j]>mayor){
				mayor=pesos[i][j];
				respuesta=marcas[i][j];
			}
		}
	}
	return respuesta;
}



void CantidadDeContenedores (bool disponibilidad[FILAS][COLUMNAS]){
	int contadorDeContenedores=0;
	for(int i=0;i<FILAS;i++){
		for(int j=0;j<COLUMNAS;j++){
			if(disponibilidad[i][j]==0){
			contadorDeContenedores=contadorDeContenedores+1;
			}
		}
	}
	cout<<"La cantidad de contenedores ingresados en todos los puertos es: "<<contadorDeContenedores<<endl;
}

void OrdenamientoContenedoresPorPuerto (int cantidadContenedores[],string  nombresPuertos[],int numPuertos){
	for(int i=0;i<numPuertos;i++)
	{
		for(int j=0;j<numPuertos;j++)
		{
			if(cantidadContenedores[i]>cantidadContenedores[j]){
				int aux=cantidadContenedores[i];
				cantidadContenedores[i]=cantidadContenedores[j];
				cantidadContenedores[j]=aux;
				string auxStr=nombresPuertos[i];
				nombresPuertos[i]=nombresPuertos[j];
				nombresPuertos[j]=auxStr;
			}
		}
	}
	cout<<"El orden de puertos por su cantidad de contenedores es: "<<endl;
	for(int i=0;i<numPuertos;i++){
		cout<<cantidadContenedores[i]<<" contenedores en "<<nombresPuertos[i]<<endl;
	}
	
}

float PromedioDePeso (int peso[FILAS][COLUMNAS]){
	float promedio=0.0;
	float suma=0;
	float contador=0;
	for(int i=0;i<FILAS;i++){
		for(int j=0;j<COLUMNAS;j++){
			if(peso[i][j]>0){
			suma=suma+peso[i][j];
			contador=contador+1;
			}
		}
	}
	promedio=suma/contador;
	return promedio;
}

int FilaMasCarga (int peso[FILAS][COLUMNAS]){
	int sumaFila=0;
	int filaMasPesada=INT_MIN;
	for(int i=0;i<FILAS;i++){
		for(int j=0;j<COLUMNAS;j++){
			sumaFila=sumaFila+peso[i][j];
		}
		if (sumaFila>filaMasPesada){
			filaMasPesada=i;	
		}
	}
	return filaMasPesada;
}

int ColumnaMenosCarga (int pesos[FILAS][COLUMNAS]){
	int sumaColumna=0;
	int columnaMenosPesada=INT_MAX;
	for(int i=0;i<COLUMNAS;i++){
		for(int j=0;j<FILAS;j++){
			sumaColumna=sumaColumna+pesos[i][j];
		}
		if (sumaColumna<columnaMenosPesada){
			columnaMenosPesada=i;	
		}
	}
	return columnaMenosPesada;
}

int CantidadContenedoresClase (string claseArticulo[FILAS][COLUMNAS],string ArticuloAOperar){
	int Contador;
	for(int i=0;i<FILAS;i++){
		for(int j=0;j<COLUMNAS;j++){
			if(ArticuloAOperar==claseArticulo[i][j]){
				Contador=Contador+1;
			}
		}
	}
	return Contador;
}

float PromedioPesoPorPuerto (string puerto[FILAS][COLUMNAS],string PuertoAOperar, int pesos[FILAS][COLUMNAS]){
	float pesoDePuerto=0.0;
	float contador=0.0;
	float promedioPesoPuerto=0.0;
	for(int i=0;i<FILAS;i++){
		for(int j=0;j<COLUMNAS;j++){
			if(PuertoAOperar==puerto[i][j]){
				pesoDePuerto=pesoDePuerto+pesos[i][j];
				contador=contador+1;
			}
		} 
	}
	promedioPesoPuerto=pesoDePuerto/contador;
	return promedioPesoPuerto;
}

string NombreEmpresaMasPeso (string marca[FILAS][COLUMNAS], int peso[FILAS][COLUMNAS]){
	string masPesada="";
	int PesoMasPesada=INT_MIN;
	for(int i=0;i<FILAS;i++){
		for(int j=0;j<COLUMNAS;j++){
			if (peso[i][j]>PesoMasPesada) {
				PesoMasPesada=peso[i][j];
				masPesada=marca[i][j];
			}
		}
	}
	return masPesada;
}

int PesoContenedorMasLiviano (int peso[FILAS][COLUMNAS]){
	int PesoMasLiviano=INT_MAX;
	for(int i=0;i<FILAS;i++){
		for(int j=0;j<COLUMNAS;j++){
			if (peso[i][j]<PesoMasLiviano) {
				PesoMasLiviano=peso[i][j];
			}
		}
	}
	return PesoMasLiviano;
}
