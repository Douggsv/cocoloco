// EstructProyecto2.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>


#define PI 3.14159265
#define G 9.8

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
	int op = 0;
	int num1, num2;



	while (op != 4)
	{
		printf("1.- Calcular trayectoria de reemplazo de un satelite nuevo con uno existente\n");
		printf("2.- Calcular antenas receptoras en tierra a un satelite especifico\n");
		printf("3.- Calcular antenas receptoras en tierra segun su posicion geográfica\n");
		printf("4.- Salir\n");
		printf("Indica la opcion: ");
		scanf_s("%d", &op);

		if ((op != 4) && (op<4)) {
			printf("Elige la ubicación de lanzamiento del satélite= ");
			scanf_s("%d", &num1);
			printf("Introduce ubicación del nuevo satélite: ");
			scanf_s("%d", &num2);
		}
		else { printf("\nIntroduce una opcion valida!!!\n"); }

		switch (op)
		{
		case 1: opsum();
			system("pause");
			system("cls");

			break;

		case 4: break;
		}
	}
}
