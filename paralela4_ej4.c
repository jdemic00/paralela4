#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int n;
    printf("Introduce el número de alumnos: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("El número de alumnos debe ser positivo.\n");
        return 1;
    }

    int *vector1 = (int *)malloc(n * sizeof(int));
    int *vector2 = (int *)malloc(n * sizeof(int));

    srand(omp_get_wtime());
    for (int i = 0; i < n; i++) {
        vector1[i] = rand() % 11;
        vector2[i] = rand() % 11;
    }

    int min1 = 10, max1 = 0, suma1 = 0;
    int min2 = 10, max2 = 0, suma2 = 0;

    #pragma omp parallel for reduction(+:suma1, suma2) reduction(min:min1, min2) reduction(max:max1, max2) nowait
    for (int i = 0; i < n; i++) {
        suma1 += vector1[i];
        suma2 += vector2[i];
        if (vector1[i] < min1) min1 = vector1[i];
        if (vector1[i] > max1) max1 = vector1[i];
        if (vector2[i] < min2) min2 = vector2[i];
        if (vector2[i] > max2) max2 = vector2[i];
    }

    printf("Parcial 1 - Media: %.2f, Mínimo: %d, Máximo: %d\n", (float)suma1 / n, min1, max1);
    printf("Parcial 2 - Media: %.2f, Mínimo: %d, Máximo: %d\n", (float)suma2 / n, min2, max2);

    free(vector1);
    free(vector2);

    return 0;
}
