// EstructProyecto2.cpp: define el punto de entrada de la aplicación de consola.
// LA POSICIÓN UTILIZADA ES BASADA EN EL "Sistema de coordenadas universal transversal de Mercator" EL CUAL CONVIERTE LA LATITUD Y LONGITUD EN METROS.

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

#define PI 3.14159265
#define G 9.8
#define VT 11070 //velocidad
#define ALT 35786 //Distancia de un punto de la tierra al satélite Km


/*En esta funcion hacemos dividir dos valores en registro de pila en asm con fdivp y mantener unico valor st(1)*/
float dividir(float a, float b) {
	float c;
	float d = a;
	float e = b;
	_asm {
		fld d
		fld e
		fdivp st(1), st // Divide Real and Pop
		fstp c
	}
	return c;
}
/*En esta funcion hacemos sumar dos valores en registro de pila en asm con faddp y mantener unico valor st(1)*/
float suma(float a, float b) {
	float a1 = a;
	float b1 = b;
	float c;

	_asm {
		fld a1
		fld b1
		faddp st(1), st // Floating-point Add Pairwise
		fstp c // copia el valor del st

	}
	return c;
}
/*En esta funcion hacemos multiplicar dos valores en registro de pila en asm con fmulp y mantener unico valor st(1)*/
float multiplicar(float a, float b) {
	float numero3;
	float numero1 = a;
	float numero2 = b;
	_asm {
		fld numero1
		fld numero2
		fmulp st(1), st // Multiply Real and Pop
		fstp numero3 // copia el valor del st 
	}
	return numero3;
}
/*En esta funcion hacemos restar dos valores en registro de pila en asm con fsubp y mantener unico valor st(1)*/
float resta(float a, float b) {
	float resultado = 0;
	float valor1 = a;
	float valor2 = b;

	_asm {
		fld valor1
		fld valor2 //guarda variables
		fsubp st(1), st //Subtract Real 
		fstp resultado // copia el valor del st
	}

	return resultado;
}




int opsum() {
	int a = 2;
	int suma = 0;
	suma = ((a) * (10));
	printf("suma= %d\n\n", suma);
	return suma;
	system("cls");

}



void main()
{
	setlocale(LC_ALL, "spanish");
	int p = 0;
	int op = 0; int op2 = 0;
	int num1 = 0;



	while (op != 4)
	{
		printf("\n		1.- Calcular trayectoria de reemplazo de un satelite nuevo con uno existente\n");
		printf("		2.- Calcular antenas receptoras en tierra a un satelite especifico\n");
		printf("		3.- Calcular antenas receptoras en tierra segun su posicion geográfica\n");
		printf("		4.- Salir\n");
		printf("		Indica la opcion: ");

		scanf_s("%d", &op);
		system("cls");

		if ((op != 4) && (op<4)) {
			printf("\n\n		Elige la ubicación del satélite= \n");
			printf("\n		1- Cabo Cañaveral\n");
			printf("\n		2- Puerto espacial Kourou\n");
				printf("\n		Introduce la opción= ");

				scanf_s("%d", &op2);
				 
			switch (op2)    //SWITCH DE LA UBICACIÓN.
			{
			case 1: num1 = op2;
				//system("pause");
				system("cls");

				break;

			case 2: num1 = op2;
				system("cls");
				break;
			}
			if (op2 > 2)
			{
				printf("\n\n		La ubicación no existe! Intentalo de nuevo\n\n");
			}
			
			//scanf_s("%d", &num2);
		}
		else { printf("\nIntroduce una opcion valida!!!\n");
		system("pause");
		system("cls");
		}

		switch (op)
		{
		case 1:            //SWITCH DEL MENÚ

			if (num1 == 1) {											//UBICACIÓN 2
				float posx = 546014.15; //este
				float posy = 3148250.58; //norte

				printf("\n\n		El satélite se lanzará desde Cabo Cañaveral\n\n");
				printf("\n		Se lanzará desde la posición= ( %f . %f ) \n",posx,posy);
				int cmk = 0;
				while (cmk<1) {
					printf("\n		Preparando lanzamiento...\n");
					printf("\n		PRESIONE ENTER PARA DESPEGAR!");
					cmk = cmk + 1;
					system("pause>NULL");
					system("cls");
				}

				int kmre = 0;


					while (kmre <= 1200) {
						kmre = kmre + 10;
						printf("\n\n\n\n\n		El cohete se está elevando una distancia de 1200 km para agarrar suficiente impulso\n");
						printf("\n\n		Altura recorrida= %d \n", kmre);
						system("cls");
					}


				
				printf("\n\n		Altura recorrida= 1200km");

				system("pause>NULL");
				system("cls");
			}
			if (num1 ==2) {                                               // UBICACIÓN 1
				    float posx = 304920.19; // ESTE
					float posy = 572831.86; //NORTE
				printf("\n\n		El satélite se lanzará desde el Puerto Espacial Kourou\n\n");
				printf("\n		Se lanzará desde la posición= ( %f . %f ) \n", posx, posy);
				int cmk = 0;
				while (cmk<1) {
					printf("\n		Preparando lanzamiento...\n");
					printf("\n		PRESIONE ENTER PARA DESPEGAR!");
					cmk = cmk + 1;
					system("pause>NULL");
					system("cls");
				}

				int kmre = 0;


				while (kmre <= 1200) {
					kmre = kmre + 10;
					printf("\n\n\n\n\n		El cohete se está elevando una distancia de 1200 km para agarrar suficiente impulso\n");
					printf("\n\n		Altura recorrida= %d \n", kmre);
					system("cls");
				}



				printf("\n\n		Altura recorrida= 1200km");

				system("pause>NULL");
				system("cls");
			}


			break;

		case 4: break;
		}
	}
}
