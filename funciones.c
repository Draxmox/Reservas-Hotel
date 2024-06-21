#include <stdio.h>
#include <string.h>
#include "funciones.h"

void buscarPorTamano(int *numHabitacion, char habitaciones[9][3][40], double precios[9]) {
    char tipo[40];
    printf("Ingrese el tamaño de habitacion que desea buscar: ");
    scanf("%s", tipo);
    printf("#\tTamaño\tHotel\tPrecio\n");
    for (int i = 0; i < 9; i++) {
        if (strcmp(habitaciones[i][1], tipo) == 0) {
            printf("%s\t%s\t%s\t%lf\n", habitaciones[i][0], habitaciones[i][1], habitaciones[i][2], precios[i]);
        }
    }
    printf("Elija la habitacion que desea reservar: ");
    scanf("%d", numHabitacion);
}

void buscarHotel(int *numHabitacion, char habitaciones[9][3][40], double precios[9]) {
    char hotel[40];
    printf("Ingrese el nombre del hotel que desea buscar: ");
    scanf("%s", hotel);
    printf("#\tTamaño\tHotel\tPrecio\n");
    for (int i = 0; i < 9; i++) {
        if (strcmp(habitaciones[i][2], hotel) == 0) {
            printf("%s\t%s\t%s\t%lf\n", habitaciones[i][0], habitaciones[i][1], habitaciones[i][2], precios[i]);
        }
    }
    printf("Elija la habitacion que desea reservar: ");
    scanf("%d", numHabitacion);
}

void realizarReserva(int numHabitacion, char habitaciones[9][3][40], char clientes[5][2][40], int reservas[10][4]) {
    char cedula[40], nombre[40];
    printf("Ingrese la cédula del cliente: ");
    scanf("%s", cedula);
    printf("Ingrese el nombre del cliente: ");
    scanf("%s", nombre);

    for (int i = 0; i < 5; i++) {
        if (clientes[i][0][0] == '\0') {
            strcpy(clientes[i][0], nombre);
            strcpy(clientes[i][1], cedula);
            break;
        }
    }

    for (int i = 0; i < 10; i++) {
        if (reservas[i][0] == -1) {
            reservas[i][0] = numHabitacion;
            for (int j = 0; j < 5; j++) {
                if (strcmp(clientes[j][1], cedula) == 0) {
                    reservas[i][1] = j;
                    break;
                }
            }
            reservas[i][2] = 0; // Reserva no pagada
            printf("Reserva realizada con éxito.\n");
            break;
        }
    }
}

void buscarReservaPorCedula(int *numReserva, char clientes[5][2][40], int reservas[10][4]) {
    char cedula[40];
    printf("Ingrese la cédula del cliente: ");
    scanf("%s", cedula);

    *numReserva = -1; // Inicializar como no encontrado

    for (int i = 0; i < 10; i++) {
        if (reservas[i][0] != -1 && strcmp(clientes[reservas[i][1]][1], cedula) == 0) {
            *numReserva = i;
            break;
        }
    }

    if (*numReserva == -1) {
        printf("Cédula no registrada.\n");
    }
}

void imprimirReserva(int numReserva, int reservas[10][4], char habitaciones[9][3][40], double precios[9]) {
    if (numReserva != -1 && reservas[numReserva][0] != -1) {
        int habitacionIndex = reservas[numReserva][0];
        printf("Reserva número %d:\n", numReserva);
        printf("Habitación: %s, Hotel: %s, Tamaño: %s, Precio: %.2lf\n",
               habitaciones[habitacionIndex][0], habitaciones[habitacionIndex][2], habitaciones[habitacionIndex][1], precios[habitacionIndex]);
        printf("Estado de pago: %s\n", reservas[numReserva][2] ? "Pagada" : "No pagada");
    }
}

void pagarReserva(int numReserva, int reservas[10][4], char habitaciones[9][3][40], double precios[9]) {
    if (numReserva != -1 && reservas[numReserva][0] != -1) {
        reservas[numReserva][2] = 1; // Marcar como pagada
        printf("Reserva pagada con éxito.\n");
    } else {
        printf("Cédula no registrada.\n");
    }
}
