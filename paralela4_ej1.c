#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int n;
    printf("Introduce el tamaño del vector: ");
    scanf("%d", &n);

    int *vector = (int *)malloc(n * sizeof(int));

    #pragma omp parallel for schedule(static)
    for (int i = 0; i < n; i++) {
        vector[i] = omp_get_thread_num();
    }

    printf("Vector inicializado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");

    free(vector);
    return 0;
}
