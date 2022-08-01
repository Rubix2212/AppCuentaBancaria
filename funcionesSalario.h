#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void depositar() {
  system("cls");
  float deposito;
  float saldo;
  FILE *archivo = fopen("./assets/cuenta.txt", "r");
  fscanf(archivo, "%f", &saldo);
  printf("Que cantidad desea depositar?: $");
  scanf("%f", &deposito);
  fclose(archivo);
  saldo += deposito;
  archivo = fopen("./assets/cuenta.txt", "w");  
  fprintf(archivo, "%f", saldo);
  fclose(archivo);
  printf("Operacion realizada con exito\n");
  printf("Su saldo actual es: $%.2f\n", saldo);
}

void retirar() {
  inicioRetirar:
  system("cls");
  float retiro;
  float saldo;
  FILE *archivo = fopen("./assets/cuenta.txt", "r");
  fscanf(archivo, "%f", &saldo);
  printf("Que cantidad desea retirar?: $");
  scanf("%f", &retiro);
  fclose(archivo);
  float saldoActual = saldo;
  saldo -= retiro;
  if (saldo < 0) {
    printf("No tiene suficiente saldo para realizar esta operacion, su saldo actual es de %.2f\n", saldoActual);
    system("pause");
    system("cls");
    goto inicioRetirar;
  }
  archivo = fopen("./assets/cuenta.txt", "w");  
  fprintf(archivo, "%f", saldo);
  fclose(archivo);
  printf("Operacion realizada con exito\n");
  printf("Su saldo actual es: $%.2f y retiro $%.2f\n", saldo, retiro);
}

float leerSaldo() {
  FILE *archivo = fopen("./assets/cuenta.txt", "r");
  float saldo;
  fscanf(archivo, "%f", &saldo);
  fclose(archivo);
  return saldo;
}
