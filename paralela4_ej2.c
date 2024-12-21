#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int n, m;
    printf("Introduce el número de filas (n): ");
    scanf("%d", &n);
    printf("Introduce el número de columnas (m): ");
    scanf("%d", &m);

    int **matriz = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(m * sizeof(int));
    }

    #pragma omp parallel for collapse(2) schedule(static)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matriz[i][j] = omp_get_thread_num();
        }
    }

    printf("Matriz inicializada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
