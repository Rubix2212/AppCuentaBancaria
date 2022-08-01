#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesSalario.h"
#include "funcionesCuenta.h"

int main() {
  start:
  if (fopen("./assets/cuenta.txt", "r") == NULL || 
  fopen("./assets/usuario.txt", "r") == NULL || 
  fopen("./assets/password.txt", "r") == NULL) {
    crearCuenta();
    goto start;
  }

  comprobarCuenta();
  int opcion;
  inicio:
  printf("\nQue desea hacer?");
  printf("\n1. Depositar saldo");
  printf("\n2. Retirar");
  printf("\n3. Ver saldo");
  printf("\n4. Cambiar password");
  printf("\n5. Salir");
  printf("\nOpcion:\t");
  scanf("%d", &opcion);
  switch(opcion) {
    case 1:
      depositar();
      system("pause");
      system("cls");
      goto inicio;
      break;
    case 2:
      retirar();
      system("pause");
      system("cls");
      goto inicio;
      break;
    case 3:
      system("cls");
      printf("Su saldo actual es: $%.2f\n", leerSaldo());
      system("pause");
      system("cls");
      goto inicio;
      break;
    case 4:
      cambiarPassword();
      system("pause");
      system("cls");
      goto inicio;
      break;
    case 5:
      printf("\nGracias por usar nuestro servicio");
      return 0;
      break;
    default:
      system("cls");
      printf("Opcion invalida\n");
      system("pause");
      system("cls");
      goto inicio;
      break;
  }
}