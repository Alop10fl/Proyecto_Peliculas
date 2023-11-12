#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<stdbool.h>

struct fecha{
	int dia;
	char mes[12];
	int anio;
};

struct actor{
	char nombre[15];
	char apellido[20];
	char nacionalidad[20];
	struct fecha fecha_nacim;
};

struct pelicula{
	char clave[5];
	char titulo[30];
	char pais[30];
	int anio_estreno;
	char duracion[15];
	char genero[30];
	int num_actores;
	struct actor actores[5];
};

struct pelicula lista[11];


void NuevaPelicula(struct pelicula lista[], int cont){
	int i = 0;
	fflush(stdin);
	
	printf("\nClave: ");
	gets(lista[cont].clave);
	fflush(stdin);
	
	printf("\nTítulo: ");
	gets(lista[cont].titulo);
	fflush(stdin);
	
	printf("\nPaís: ");
	gets(lista[cont].pais);
	fflush(stdin);
	
	printf("\nAño de estreno: ");
	scanf("%d", &lista[cont].anio_estreno);
	fflush(stdin);
	
	printf("\nDuración: ");
	gets(lista[cont].duracion);
	fflush(stdin);
	
	printf("\nGenero: ");
	gets(lista[cont].genero);
	fflush(stdin);
	
	printf("\nNúmero de actores: ");
	scanf("%d", &lista[cont].num_actores);
	fflush(stdin);
	
	for(i = 0; i < lista[cont].num_actores; i++){
		fflush(stdin);
		printf("\n\n Nombre: ");
		gets(lista[cont].actores[i].nombre);
		
		fflush(stdin);		
		printf("\n Apellido (solo el paterno): ");
		gets(lista[cont].actores[i].apellido);
		
		fflush(stdin);
		printf("\n Nacionalidad: ");
		gets(lista[cont].actores[i].nacionalidad);
		
		fflush(stdin);
		printf("\n Fecha de nacimiento ");	
		printf("\n Día: ");
		scanf("%d", &lista[cont].actores[i].fecha_nacim.dia);
		
		fflush(stdin);		
		printf("\n Mes: ");
		gets(lista[cont].actores[i].fecha_nacim.mes);
		
		fflush(stdin);
		printf("\n Año: ");
		scanf("%d", &lista[cont].actores[i].fecha_nacim.anio);
		fflush(stdin);	
	}
	
}


void NuevoActor(struct pelicula lista[], int cont){
	char clave_usua[5];
	int act = 0;
	fflush(stdin);
	
	printf("\nInserte la clave de la película en donde se añadirá el actor: ");
	gets(clave_usua);
	fflush(stdin);
	
	bool ban = false;
	
	int i = 0;
	for(i = 0; i < cont; i++){
		if(strcmp(lista[i].clave, clave_usua) == 0){
			ban = true;
		}	
		if(ban){
			printf("\t La pelicula %s se encuentra en la Base de datos ", lista[i].titulo);
			printf("\n¿Cuántos actores desea añadir? ");
			scanf("%d", &act);
			
			if(act < lista[i].num_actores){
				printf("\n\n INGRESE LOS DATOS DEL NUEVO ACTOR ");
				fflush(stdin);
				
				int j=lista[0].num_actores;
				printf("\n\n x %d",j);
				
				for(j=lista[0].num_actores; j < (lista[0].num_actores + act); j++){
					printf("\n\n Nombre: ");
					gets(lista[i].actores[j].nombre);
					fflush(stdin);
				
					printf("\n Apellido (solo el paterno): ");
					gets(lista[i].actores[j].apellido);
					fflush(stdin);
					
					printf("\n Nacionalidad: ");
					gets(lista[i].actores[j].nacionalidad);
					fflush(stdin);
					
					printf("\n Fecha de nacimiento ");	
					printf("\n Día: ");
					scanf("%d", &lista[i].actores[j].fecha_nacim.dia);
					fflush(stdin);
					
					printf("\n Mes: ");
					scanf("%d", &lista[i].actores[j].fecha_nacim.mes);
					fflush(stdin);
					
					printf("\n Año: ");
					scanf("%d", &lista[i].actores[j].fecha_nacim.anio);
					fflush(stdin);	
				}			
			}else{
				printf("ERROR: Solo se puede agregar un máximo de 5 actores ");
			}
			lista[0].num_actores = lista[0].num_actores + act;
		}
		else{
		printf(" ERROR: No existe ninguna película con esa clave ");
		}	
	}
			
} 

void MostrarCatalogo(struct pelicula lista[], int cont){
	int i = 0;
	int n = 1;
	
	for(i = 0; i < cont; i++){
		printf("\n\n Clave: %s \n", lista[i].clave);
		printf("\n Título: %s \n", lista[i].titulo);
		printf("\n País: %s \n", lista[i].pais);
		printf("\n Año de estreno: %d \n", lista[i].anio_estreno);
		printf("\n Duración: %s \n", lista[i].duracion);
		printf("\n Genero: %s \n", lista[i].genero);
		printf("\n Número de actores: %d \n", lista[i].num_actores);
		printf("\n Actores \n");
		
		int j = 0;
		for(j = 0; j < lista[i].num_actores; j++){
			printf("\t%d. %s %s \n", n, lista[i].actores[j].nombre, lista[i].actores[j].apellido);
			n++;
		}
	}
	
}


void MostrarActores(struct pelicula lista[], int cont){
	int i = 0, j = 0, n = 1;
	
	for(i = 0; i < cont; i++){
		printf("\n Actores ");
		
		for(j = 0; j < lista[i].num_actores; j++){
			printf("\n\t %d. %s %s \n", n, lista[i].actores[j].nombre, lista[i].actores[j].apellido);
			printf("\t Nacionalidad: %s \n", lista[i].actores[j].nacionalidad);
			printf("\t Fecha de nacimiento: %d del %s de %d \n", lista[i].actores[j].fecha_nacim.dia, lista[i].actores[j].fecha_nacim.mes, lista[i].actores[j].fecha_nacim.anio);
		}	
	}

}


//FUNCIÓN PRINCIPAL
main(){
	setlocale(LC_CTYPE, "Spanish");
	//Declaración de variables
	int cont = 0, n = 0, opcion=0;
	char resp=0;	
	
	do{
		
		printf("\nMenú de opciones ");
		printf("\nOpción 1. Agregar nueva película ");
		printf("\nOpción 2. Agregar nuevo actor a una película ");
		printf("\nOpción 3. Mostrar catálogo de películas ");
		printf("\nOpción 4. Mostrar todos los actores ");
		printf("\nOpción 5. Salir ");
	
		printf("\n\nEliga una opcion: ");
		scanf("%d", &opcion);
	

		switch(opcion){
			case 1: 	
				NuevaPelicula(lista, cont);
				cont++;
			break;
			
			case 2: 
				NuevoActor(lista, cont);
			break;
			
			case 3: 
				MostrarCatalogo(lista, cont);
				n++;
			break;
			
			case 4: 
				MostrarActores(lista, cont);
				n++;
			break;
			
			case 5: 
				
			break;
			
			default:
				printf("\n Opción Incorrecta ");
				printf("\n Intente de nuevo ");
			break;
		}
		
		printf("\n\n ¿Desea seleccionar otra opción del menú? (S/N): ");
		scanf("%s", &resp);
		
	} while (resp == 'S' || resp == 's');
}
