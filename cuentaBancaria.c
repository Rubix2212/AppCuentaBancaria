#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesSalario.h"
#include "funcionesCuenta.h"

void operacionesCuenta() {
  int opcion;
  inicioOp:
  printf("\nQue desea hacer?");
  printf("\n1. Depositar saldo");
  printf("\n2. Retirar");
  printf("\n3. Ver saldo");
  printf("\n4. Volver");
  printf("\nOpcion: ");
  scanf("%d", &opcion);
  switch(opcion) {
    case 1:
      depositar();
      system("pause");
      system("cls");
      goto inicioOp;
      break;
    case 2:
      retirar();
      system("pause");
      system("cls");
      goto inicioOp;
      break;
    case 3:
      system("cls");
      printf("Su saldo actual es: $%.2f\n", leerSaldo());
      system("pause");
      system("cls");
      goto inicioOp;
      break;
    case 4:
      system("cls");
      break;
    default:
      system("cls");
      printf("Opcion invalida\n");
      system("pause");
      system("cls");
      break;
  }
}

void modificarDatos() {
  int opcion;
  printf("\nQue desea hacer?");
  printf("\n1. Modificar nombre");
  printf("\n2. Modificar clave");
  printf("\n3. Volver");
  printf("\nOpcion: ");
  scanf("%d", &opcion);
  switch(opcion) {
    case 1:
      cambiarNombre();
      break;
    case 2:
      cambiarPassword();
      break;
    case 3:
      system("cls");
      break;
    default:
      printf("\nOpcion no valida\n");
      break;
  }
}

int main() {
  startProgram:
  if (fopen("./assets/cuenta.txt", "r") == NULL || 
  fopen("./assets/usuario.txt", "r") == NULL || 
  fopen("./assets/password.txt", "r") == NULL) {
    crearCuenta();
    goto startProgram;
  }
  comprobarCuenta();
  int opcion;
  pos:
  printf("Seleccione una opcion: ");
  printf("\n1. Modificar datos de la cuenta");
  printf("\n2. Operaciones con la cuenta");
  printf("\n3. Salir");
  printf("\nOpcion: ");
  scanf("%d", &opcion);
  switch (opcion) {
    case 1:
      modificarDatos();
      system("cls");
      goto pos;
      break;
    case 2:
      operacionesCuenta();
      system("cls");
      goto pos;
      break;
    case 3:
      printf("\nGracias por usar el programa");
      return 0;
    default:
      printf("\nOpcion no valida\n");
      break;
  }
}