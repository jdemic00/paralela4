#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int es_primo(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n, cuenta = 0;
    printf("Introduce el valor de n: ");
    scanf("%d", &n);

    #pragma omp parallel for reduction(+:cuenta) schedule(dynamic)
    for (int i = 1; i <= n; i++) {
        if (es_primo(i)) {
            cuenta++;
        }
    }

    printf("Cantidad de números primos entre 1 y %d: %d\n", n, cuenta);
    return 0;
}
