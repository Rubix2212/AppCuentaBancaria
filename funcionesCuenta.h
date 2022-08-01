#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int comprobarCuenta() {
  system("cls");
  printf("Login\n");
  char nombre[20];
  char password[20];
  char nombreCorrecto[20];
  char passwordCorrecto[20];
  FILE *userFile = fopen("./assets/usuario.txt", "r");
  fscanf(userFile, "%s", nombreCorrecto);
  FILE *passwordFile = fopen("./assets/password.txt", "r");
  fscanf(passwordFile, "%s", passwordCorrecto);
  nombre:
  printf("Nombre: ");
  scanf("%s", nombre);
  if (strcmp(nombre, nombreCorrecto) == 0) {
    password:
    printf("Password: ");
    scanf("%s", password);
    if (strcmp(password, passwordCorrecto) == 0) {
      printf("Login correcto! \n");

    } else {
      printf("Password incorrecto\n");
      goto password;
    }
  } else {
    printf("Nombre incorrecto\n");
    goto nombre;
  }
}

void crearCuenta() {
  char nombre[20];
  char password[20];
  FILE *usuario_file = fopen("./assets/usuario.txt", "w");
  FILE *password_file = fopen("./assets/password.txt", "w");
  system("cls");
  printf("Creacion de Cuenta Bancaria");
  printf("\nNombre: ");
  scanf("%s", &nombre);
  printf("Password: ");
  scanf("%s", &password);
  fopen("./assets/usuario.txt", "w");
  fprintf(usuario_file, "%s", nombre);
  fprintf(password_file, "%s", password);
  fclose(usuario_file);
  fclose(password_file);
  printf("Cuenta creada con exito\n");
}