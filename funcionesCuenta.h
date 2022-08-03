#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <direct.h>
#define LONGITUD 20

void hidePassword(char *password) {
  char caracter;
  int i = 0;
  while (caracter = getch()) {
    if (caracter == 13) {
      password[i] = '\0';
      break;
    } else if (caracter == 8) {
      if (i > 0) {
        i--;
        printf("\b \b");
      }
    } else {
      if (i < 20) {
        printf("*");
        password[i] = caracter;
        i++;
      }
    }
  }
}

void cambiarNombre() {
  system("cls");
  char nombre[LONGITUD + 1];
  printf("Ingrese su nuevo nombre: ");
  scanf("%s", nombre);
  FILE *archivo = fopen("./assets/usuario.txt", "w");
  fprintf(archivo, "%s", nombre);
  fclose(archivo);
  printf("Nombre cambiado con exito\n");
}

void cambiarPassword() {
  char password[LONGITUD];
  char newPassword[LONGITUD];
  char passwordActual[LONGITUD];
  FILE *archivo = fopen("./assets/password.txt", "r");
  fscanf(archivo, "%s", passwordActual);
  fclose(archivo);
  inicio:
  printf("Ingrese su clave actual: ");
  hidePassword(password);
  if (strcmp(password, passwordActual) == 0) {
    printf("\nIngrese su nueva clave: ");
    hidePassword(password);
    printf("\nConfirme su nueva clave: ");
    hidePassword(newPassword);
    if (strcmp(password, newPassword) == 0) {
      archivo = fopen("./assets/password.txt", "w");
      fprintf(archivo, "%s", password);
      fclose(archivo);
      printf("\nLa clave ha cambiado con exito\n");
    } else {
      printf("\nLas claves no coinciden\n");
      system("pause");
      system("cls");
      goto inicio;
    }
  } else {
    printf("\nClave incorrecta\n");
    system("pause");
    system("cls");
    goto inicio;
  }
}

void comprobarCuenta() {
  system("cls");
  printf("Login\n");
  char nombre[LONGITUD + 1];
  char password[LONGITUD + 1];
  char nombreCorrecto[LONGITUD + 1];
  char passwordCorrecto[LONGITUD + 1];
  int tries = 3;
  FILE *userFile = fopen("./assets/usuario.txt", "r");
  fscanf(userFile, "%s", nombreCorrecto);
  FILE *passwordFile = fopen("./assets/password.txt", "r");
  fscanf(passwordFile, "%s", passwordCorrecto);
  while (tries > 0) {
    printf("Nombre: ");
    scanf("%s", nombre); 
    printf("Clave: ");
    hidePassword(password);
    if (strcmp(nombre, nombreCorrecto) == 0 && 
    strcmp(password, passwordCorrecto) == 0) {
      system("cls");
      break;
    } else {
      tries--;
      printf("\nNombre o clave incorrecto\nIntentos restantes: %d\n", tries);
    }
    if (tries == 0) {
      printf("Demasiados intentos, cerrando programa\n");
      system("pause");
      exit(0);
    }
  }
}

void crearCuenta() {
  if (_mkdir("./assets") == 0) {
    _mkdir("./assets");
  } 
  char nombre[LONGITUD + 1];
  char password[LONGITUD + 1];
  char caracter;
  int i = 0;
  float saldo;
  system("cls");
  FILE *usuario_file = fopen("./assets/usuario.txt", "w");
  printf("Creacion de Cuenta Bancaria");
  printf("\nNombre: ");
  scanf("%s", &nombre);
  fprintf(usuario_file, "%s", nombre);
  fclose(usuario_file);
  FILE *password_file = fopen("./assets/password.txt", "w");
  printf("Password: ");
  hidePassword(password);
  fprintf(password_file, "%s", password);
  fclose(password_file);
  FILE *archivo = fopen("./assets/cuenta.txt", "w");
  printf("\nIngrese el saldo inicial: $");
  scanf("%f", &saldo);
  fprintf(archivo, "%.2f", saldo);
  fclose(archivo);
  if (fopen("./assets/cuenta.txt", "r") == NULL || 
  fopen("./assets/usuario.txt", "r") == NULL || 
  fopen("./assets/password.txt", "r") == NULL) {
    printf("\nError al crear la cuenta");
    exit(0);
  } else {
    printf("\nCuenta creada con exito");
  }
}