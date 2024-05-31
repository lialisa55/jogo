#include <stdio.h>
#include <stdlib.h>

void aloque(int numA, int numB, int **matriz){
    printf("aloque");
    *matriz = (int**) malloc(numA * sizeof(int*));
    for(int i = 0; i < numA; i++){
        matriz[i] = (int*) malloc(numB * sizeof(int));
    }
    printf("endaloque");
}

void receba(int numA, int numB, int **matriz){
    printf("receba");
    for (int i = 0; i < numA; i++){
        for (int j = 0; j < numB; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("endreceba");
}

void imprima(int numA, int numB, int **matriz){
    printf("imprima");
    for (int i = 0; i < numA; i++){
        for (int j = 0; j < numB; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("endimprima");
}

int main()
{
    int numA, numB, **matriz;
    scanf("%d %d", &numA, &numB);
    getchar();

    aloque(numA, numB, &matriz);
    receba(numA, numB, matriz);
    imprima(numA, numB, matriz);

    return 0;
}
