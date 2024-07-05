#include <stdio.h>
#include <stdlib.h>

const int MAX = 80;
const int TAM = 4;

typedef char cadena[MAX];
typedef cadena grupo[TAM];
typedef int matriz[TAM][TAM];

int main()
{
    int f, k; // filas y columnas
    int i, x; // i > for / x > while
    char c;

    cadena nombre;

    char eligegrupo;

    grupo group{};

    matriz resultadosIngresados{};
    matriz resultadosReales{};

    int golesIngresados;

    // Carga el nombre
    printf("Ingrese su nombre: ");
    fflush(stdin);
    scanf("%c", &c);

    x = 0;
    while (c != '\n' && x < MAX - 1)
    {
        nombre[x] = c;
        scanf("%c", &c);
        x++;
    }
    nombre[x] = '\0';

    // Ingresa grupo de la copa
    printf("\nIngrese el grupo de la copa (A,B,C,D): ");
    fflush(stdin);
    scanf("%c", &eligegrupo);

    // FALTA VALIDAR CUANDO INGRESA UN STRING
    while (eligegrupo != 'a' && eligegrupo != 'A' && eligegrupo != 'B' && eligegrupo != 'b' && eligegrupo != 'c' && eligegrupo != 'C' && eligegrupo != 'd' && eligegrupo != 'D')
    {
        printf("\nGrupo incorrecto. Ingrese el grupo nuevamente: ");
        fflush(stdin);
        scanf("%c", &eligegrupo);
    }

    // Ingresa el pais
    for (i = 0; i < TAM; i++)
    {
        printf("\nIngrese un pais: ");
        fflush(stdin);
        scanf("%c", &c);

        x = 0;
        while (c != '\n' && x < MAX - 1)
        {
            group[i][x] = c;
            scanf("%c", &c);
            x++;
        }
        group[i][x] = '\0';
    }

    // mostrar paises
    for (i = 0; i < TAM; i++)
    {
        x = 0;
        while (x < MAX && group[i][x] != '\0')
        {
            printf("%c", group[i][x]);
            x++;
        }
        printf("\n");
    }

    // RELLENAR DIAGONAL PRINCIPAL CON -1
    printf("diagonal principal\n");
    for (f = 0; f < TAM; f++)
    {
        for (k = 0; k < TAM; k++)
        {
            if (f == k)
            {
                resultadosIngresados[f][k] = -1;
            }
        }
    }

    // RECORRER EL TRIANGULO SUPERIOR PARA INGRESAR RESULTADOS
    for (f = 0; f < TAM - 1; f++)
    {
        for (k = 1 + f; k < TAM; k++)
        {
            // LOCAL
            printf("Ingrese los goles de ");
            // Mostrar nombre local
            x = 0;
            while (x < MAX && group[f][x] != '\0')
            {
                printf("%c", group[f][x]);
                x++;
            }
            printf(" a ");
            // Mostrar nombre visitante
            x = 0;
            while (x < MAX && group[k][x] != '\0')
            {
                printf("%c", group[k][x]);
                x++;
            }
            printf(" - ");

            scanf("%d", &golesIngresados);
            resultadosIngresados[f][k] = golesIngresados;

            // VISITANTE
            printf("\n Ingrese los goles de ");
            // Mostrar nombre local
            x = 0;
            while (x < MAX && group[k][x] != '\0')
            {
                printf("%c", group[k][x]);
                x++;
            }
            printf(" a ");
            // Mostrar nombre visitante
            x = 0;
            while (x < MAX && group[f][x] != '\0')
            {
                printf("%c", group[f][x]);
                x++;
            }
            printf(" - ");

            scanf("%d", &golesIngresados);
            resultadosIngresados[k][f] = golesIngresados;
        }
    }

    // MOSTRAR RESULTADOS INGRESADOS
    for (f = 0; f < TAM; f++)
    {
        for (k = 0; k < TAM; k++)
        {
            if (resultadosIngresados[f][k] < 10)
            {
                printf("[0%d]", resultadosIngresados[f][k]);
            }
            else
            {
                printf("[%d]", resultadosIngresados[f][k]);
            }
        }

        printf("\n");
    }
    printf("\n");

    // MATRIZ ALEATORIA
    for (f = 0; f < TAM - 1; f++)
    {
        for (k = 1 + f; k < TAM; k++)
        {
            resultadosReales[f][k] = (rand() % 10);
            resultadosReales[k][f] = (rand() % 10);
        }
    }

    // MOSTRAR RESULTADOS REALES
    for (f = 0; f < TAM; f++)
    {
        for (k = 0; k < TAM; k++)
        {
            if (resultadosReales[f][k] < 10)
            {
                printf("[0%d]", resultadosReales[f][k]);
            }
            else
            {
                printf("[%d]", resultadosReales[f][k]);
            }
        }

        printf("\n");
    }

    printf("\n");

    // CALCULO DE PUNTOS
    int cantPuntos = 0, ganadorReal, ganadorIngresado;
    for (f = 0; f < TAM - 1; f++)
    {
        for (k = 1 + f; k < TAM; k++)
        {
            if (resultadosIngresados[f][k] == resultadosReales[f][k] && resultadosIngresados[k][f] == resultadosReales[k][f])
            {
                cantPuntos = cantPuntos + 5;
            }
            else
            {
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
                    cantPuntos = cantPuntos + 3;
                }
            }
        }
    }

    printf("cantidad de pts ///// %d", cantPuntos);
}
