#include <stdio.h>
#include <stdlib.h>

void aloque(int numA, int numB, char ***matriz){
    *matriz = (char**) malloc(numA * sizeof(char*));
    for(int i = 0; i < numA; i++){
        (*matriz)[i] = (char*) malloc(numB * sizeof(char));
    }
}

void receba(int numA, int numB, char **matriz){
    for (int i = 0; i < numA; i++){
        for (int j = 0; j < numB; j++){
            scanf(" %c", &matriz[i][j]);
        }
    }
}

void imprima(int numA, int numB, char **matriz){
    for (int i = 0; i < numA; i++){
        for (int j = 0; j < numB; j++){
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
}

void escolha(int numA, int numB, char **matriz){
    int vizinhos = 0;
    for (int i = 0; i < numA; i++){
        for (int j = 0; j < numB; j++){
            if (matriz[i][j] == '.'){
                vizinhos = 0;
                if (i > 0 && matriz[i-1][j] == 'X'){
                    vizinhos++;
                }
                if (i < numA - 1 && matriz[i+1][j] == 'X'){
                    vizinhos++;
                }
                if (j > 0 && matriz[i][j-1] == 'X'){
                    vizinhos++;
                }
                if (j < numB - 1 && matriz[i][j+1] == 'X'){
                    vizinhos++;
                }

                if (vizinhos % 2 == 0){
                    matriz[i][j] = '*';
                }
            }
        }
    }
}


int main()
{
    int numA, numB;
    char **matriz;
    scanf("%d %d", &numA, &numB);
    getchar();

    aloque(numA, numB, &matriz);
    receba(numA, numB, matriz);
    escolha(numA, numB, matriz);
    imprima(numA, numB, matriz);

    for (int i = 0; i < numA; i++){
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
