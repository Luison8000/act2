#include <mpi.h>
#include <stdio.h>
// MPI segunda pparte 
int es_primo(int n) {
    int i;
    if (n < 2) return 0;
    for (i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int main(int argc, char** argv) {
    int rank, size, i, count = 0, total = 0;
    int inicio, fin;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    inicio = rank * (500000 / size);
    fin = inicio + (500000 / size);

    for (i = inicio; i < fin; i++)
        if (es_primo(i)) count++;

    MPI_Reduce(&count, &total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
        printf("Total de primos (MPI): %d\n", total);

    MPI_Finalize();
    return 0;
}
