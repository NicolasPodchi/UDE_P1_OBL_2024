#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>

const int MAX = 80;
const int TAM = 4;
const int TAM_PARTIDOS = 6;

typedef char cadena[MAX];
typedef cadena grupo[TAM];
typedef int arreglo[TAM_PARTIDOS];

typedef int matriz[TAM][TAM];

int main()
{
    int f, k;        // filas y columnas
    int i, x, j = 0; // i > for / x > while / j > iteración a mano
    char c;

    // Variables
    cadena nombre;
    char eligegrupo;

    grupo group{};
    arreglo partidos{};

    int golesIngresados;
    matriz resultadosIngresados{};
    matriz resultadosReales{};

    int ptosObtenidos = 0;
    int ganadorReal, ganadorIngresado;

    // Carga el nombre
    printf("Ingrese su nombre: ");

    x = 0;
    fflush(stdin);
    scanf("%c", &c);
    while (c != '\n' && x < MAX - 1)
    {
        nombre[x] = c;
        scanf("%c", &c);
        x++;
    }
    nombre[x] = '\0';
    system("cls");

    // Ingresa grupo de la copa
    printf("Ingrese el grupo de la copa (A,B,C,D): ");

    fflush(stdin);
    scanf("%c", &eligegrupo);
    while ((eligegrupo < 97 || eligegrupo > 100) && (eligegrupo < 65 || eligegrupo > 68))
    {
        printf("\nGrupo incorrecto. Ingrese el grupo nuevamente: ");
        fflush(stdin);
        scanf("%c", &eligegrupo);
    }
    system("cls");

    // Ingresa el pais
    for (i = 0; i < TAM; i++)
    {
        printf("Ingrese el pais %d: ", i + 1);

        x = 0;
        fflush(stdin);
        scanf("%c", &c);
        while (c != '\n' && x < MAX - 1)
        {
            group[i][x] = c;
            scanf("%c", &c);
            x++;
        }
        group[i][x] = '\0';
    }
    system("cls");

    // Rellenar diagonal principal con -1
    for (f = 0; f < TAM; f++)
    {
        resultadosIngresados[f][f] = -1;
    }

    // Recorrer el triangulo superior para ingresar resultados
    for (f = 0; f < TAM - 1; f++)
    {
        for (k = 1 + f; k < TAM; k++)
        {
            // TITULO PARTIDO
            // Mostrar nombre local
            x = 0;
            while (x < MAX && group[f][x] != '\0')
            {
                printf("%c", group[f][x]);
                x++;
            }

            printf(" VS. ");

            // Mostrar nombre visitante
            x = 0;
            while (x < MAX && group[k][x] != '\0')
            {
                printf("%c", group[k][x]);
                x++;
            }
            // TITULO PARTIDO

            // EQUIPO LOCAL
            printf("\nIngrese los goles de ");

            // Mostrar nombre local
            x = 0;
            while (x < MAX && group[f][x] != '\0')
            {
                printf("%c", group[f][x]);
                x++;
            }
            printf(": ");
            // Mostrar nombre visitante
            // x = 0;
            // while (x < MAX && group[k][x] != '\0')
            // {
            //     printf("%c", group[k][x]);
            //     x++;
            // }
            // printf(": ");

            scanf("%d", &golesIngresados);
            resultadosIngresados[f][k] = golesIngresados;

            // EQUIPO VISITANTE
            printf("Ingrese los goles de ");

            // Mostrar nombre visitante
            x = 0;
            while (x < MAX && group[k][x] != '\0')
            {
                printf("%c", group[k][x]);
                x++;
            }
            printf(": ");
            // Mostrar nombre local
            // x = 0;
            // while (x < MAX && group[f][x] != '\0')
            // {
            //     printf("%c", group[f][x]);
            //     x++;
            // }
            // printf(": ");

            scanf("%d", &golesIngresados);
            resultadosIngresados[k][f] = golesIngresados;

            printf("\n");
        }
    }
    system("cls");

    // MATRIZ ALEATORIA
    for (f = 0; f < TAM - 1; f++)
    {
        for (k = 1 + f; k < TAM; k++)
        {
            resultadosReales[f][k] = (rand() % 10);
            resultadosReales[k][f] = (rand() % 10);
        }
    }

    // Calculo de puntos
    for (f = 0; f < TAM - 1; f++)
    {
        for (k = 1 + f; k < TAM; k++)
        {
            ptosObtenidos = 0;
            if (resultadosIngresados[f][k] == resultadosReales[f][k] && resultadosIngresados[k][f] == resultadosReales[k][f])
            {
                // Acierta resultado exacto
                ptosObtenidos = 5;
            }
            else
            {
                // Se define ganador ingresado
                if (resultadosIngresados[f][k] > resultadosIngresados[k][f])
                {
                    ganadorIngresado = f;
                }
                else
                {
                    if (resultadosIngresados[k][f] > resultadosIngresados[f][k])
                    {
                        ganadorIngresado = k;
                    }
                    else
                    {
                        ganadorIngresado = -1;
                    }
                }

                // Se define ganador real
                if (resultadosReales[f][k] > resultadosReales[k][f])
                {
                    ganadorReal = f;
                }
                else
                {
                    if (resultadosReales[k][f] > resultadosReales[f][k])
                    {
                        ganadorReal = k;
                    }
                    else
                    {
                        ganadorReal = -1;
                    }
                }

                if (ganadorIngresado == ganadorReal)
                {
                    // Acierta equipo ganador
                    ptosObtenidos = 3;
                }
            }

            partidos[j] = ptosObtenidos;
            j++;
        }
    }

    // IMPRESION FINAL
    printf("****************************************\nPenca Copa America 2024 - UDE\n****************************************\n\n");

    // Imprime nombre
    printf("Apuesta de ");
    x = 0;
    while (x < MAX && nombre[x] != '\0')
    {
        printf("%c", nombre[x]);
        x++;
    }

    // Imprime grupo
    printf(" - GRUPO: %c", eligegrupo);
    printf("\n=============================================\n\nPARTIDO - RESULTADO APOSTADO - RESULTADO REAL - PUNTOS OBTENIDOS\n\n");

    j = 0;
    for (f = 0; f < TAM - 1; f++)
    {
        for (k = 1 + f; k < TAM; k++)
        {
            // Nombre equipo local
            x = 0;
            while (x < MAX && group[f][x] != '\0')
            {
                printf("%c", group[f][x]);
                x++;
            }
            printf(",");

            // Nombre equipo visitante
            x = 0;
            while (x < MAX && group[k][x] != '\0')
            {
                printf("%c", group[k][x]);
                x++;
            }

            // Resultado apostado
            printf(" - Apostado: %d,%d", resultadosIngresados[f][k], resultadosIngresados[k][f]);
            // Resultado real
            printf(" - Real: %d,%d", resultadosReales[f][k], resultadosReales[k][f]);
            // Puntos obtenidos del partido
            printf(" - Ptos obtenidos: %d\n", partidos[j]);

            j++;
        }
    }
}
