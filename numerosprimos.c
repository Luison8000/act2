#include <stdio.h>
#include <pthread.h>
#include <time.h>
//multihilos primera parte
#define NUM_HILOS 4
#define LIMITE 500000

int contador[NUM_HILOS];
pthread_t hilos[NUM_HILOS];

int es_primo(int n) {
    int i;
    if (n < 2) return 0;
    for (i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

void* calcular(void* arg) {
    int id = *(int*)arg;
    int inicio = id * (LIMITE / NUM_HILOS);
    int fin = inicio + (LIMITE / NUM_HILOS);
    int i;

    contador[id] = 0;
    for (i = inicio; i < fin; i++) {
        if (es_primo(i)) contador[id]++;
    }
    return NULL;
}

int main() {
    int i, ids[NUM_HILOS], total = 0;
    clock_t t_ini, t_fin;
    double tiempo;

    t_ini = clock();

    for (i = 0; i < NUM_HILOS; i++) {
        ids[i] = i;
        pthread_create(&hilos[i], NULL, calcular, &ids[i]);
    }

    for (i = 0; i < NUM_HILOS; i++) {
        pthread_join(hilos[i], NULL);
        total += contador[i];
    }

    t_fin = clock();
    tiempo = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;

    printf("Primos encontrados: %d\n", total);
    printf("Tiempo multihilo: %.4f segundos\n", tiempo);
    return 0;
}
