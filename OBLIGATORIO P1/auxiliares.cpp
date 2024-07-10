/* MOSTRAR RESULTADOS INGRESADOS
   for (f = 0; f < TAM; f++)
   {
       for (k = 0; k < TAM; k++)
       {
           if (resultadosIngresados[f][k] < 10)
           {
               printf("[%d]", resultadosIngresados[f][k]);
           }
           else
           {
               printf("[%d]", resultadosIngresados[f][k]);
           }
       }

       printf("\n");
   }
   printf("\n\n");

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
               printf("[%d]", resultadosReales[f][k]);
           }
           else
           {
               printf("[%d]", resultadosReales[f][k]);
           }
       }

       printf("\n");
   } */


   // Mostrar paises
    // for (i = 0; i < TAM; i++)
    // {
    //     x = 0;
    //     while (x < MAX && group[i][x] != '\0')
    //     {
    //         printf("%c", group[i][x]);
    //         x++;
    //     }
    //     printf("\n");
    // }