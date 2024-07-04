#include <stdio.h>
#include <stdlib.h>
const int MAX = 80;
const int TAM = 4;
typedef char cadena[MAX];
typedef cadena grupo[TAM];

int main()
{
    cadena nombre;
    int i,x;
    char c, eligegrupo;
    grupo group;

    //Carga el nombre
    printf("Ingrese su nombre: ");
    fflush(stdin);
    scanf("%c",&c);
    i=0;
    while(c!='\n' && i<MAX-1)
    {
        nombre[i]=c;
        scanf("%c",&c);
        i++;
    }
    nombre[i]='\0';

    //Ingresa grupo de la copa
    printf("\nIngrese el grupo de la copa (A,B,C,D): ");
    fflush(stdin);
    scanf("%c",&eligegrupo);

    //Ingresa el pais
    for(i=0;i<TAM;i++)
    {
        x=0;
        printf("\nIngrese un pais: ");
        scanf("%c",&c);
        while(c!='\0' && x<MAX-1)
        {
            group[i][x]=c;
            scanf("%c",&c);
            x++;
        }
        group[i][x]='\0';
        int x;
    }
}
