
---


# Proyecto de Sistemas Operativos en Red Hat Enterprise Linux

**Multihilos, Planificación de Procesos, Clúster Simulado y E/S**

Este proyecto fue desarrollado en **Red Hat Enterprise Linux** utilizando **Red Hat OpenShift Dev Spaces (Sandbox)**.
No se requieren privilegios de superusuario ni suscripción activa.

---

# 🧩 PARTE 1 — Aplicación Multihilo

## 1. Verificación del entorno

```bash
uname -a
```

```bash
gcc --version
```

---

## 2. Creación del directorio de trabajo

```bash
mkdir parte1_multihilo
cd parte1_multihilo
```

---

## 3. Programa secuencial en C

### 3.1 Crear archivo

```bash
nano primos_secuencia1.c
```

### 3.2 Código secuencial

```c
#include <stdio.h>
#include <time.h>

int es_primo(int numero) {
    int divisor;
    if (numero < 2) return 0;
    for (divisor = 2; divisor * divisor <= numero; divisor++) {
        if (numero % divisor == 0) return 0;
    }
    return 1;
}

int main() {
    int inicio = 1, fin = 500000;
    int contador = 0, i;
    clock_t t_ini, t_fin;
    double tiempo;

    t_ini = clock();

    for (i = inicio; i <= fin; i++) {
        if (es_primo(i)) contador++;
    }

    t_fin = clock();
    tiempo = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;

    printf("Primos encontrados: %d\n", contador);
    printf("Tiempo secuencial: %.4f segundos\n", tiempo);
    return 0;
}
```

Guardar y salir:

```
CTRL+O → ENTER → CTRL+X
```

### 3.3 Compilar y ejecutar

```bash
gcc primos_secuencia1.c -o primos_secuencias1
./primos_secuencias1
time ./primos_secuencias1
```

---

## 4. Programa multihilo con Pthreads

### 4.1 Crear archivo

```bash
nano primos_multihilo.c
```

### 4.2 Código multihilo

```c
#include <stdio.h>
#include <pthread.h>
#include <time.h>

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
```

### 4.3 Compilar y ejecutar

```bash
gcc primos_multihilo.c -o primos_multihilo -lpthread
./primos_multihilo
time ./primos_multihilo
```

---

# 🧩 PARTE 2 — Planificación de procesos

## 1. Ejecución con prioridad baja (Round Robin)

```bash
nice -n 10 ./primos_multihilo
```

## 2. Ejecución con prioridad alta

```bash
nice -n -5 ./primos_multihilo
```

## 3. Observación del planificador

```bash
top
```

Salir con:

```
q
```

📌 Se comparan tiempos de respuesta y uso de CPU.

---

# 🧩 PARTE 3 — Clúster simulado (MPI)

## 1. Crear directorio

```bash
mkdir parte3_cluster
cd parte3_cluster
```

## 2. Código MPI

```bash
nano primos_mpi.c
```

```c
#include <mpi.h>
#include <stdio.h>

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
```

## 3. Compilar y ejecutar

```bash
mpicc primos_mpi.c -o primos_mpi
mpirun -np 4 ./primos_mpi
```

---

# 🧩 PARTE 4 — Entrada / Salida en Red Hat

## 1. Identificación de dispositivos

```bash
lsblk
lspci
lsusb
```

## 2. Observación de E/S

```bash
iostat
```

📌 Se analiza el uso de E/S y se concluye que **DMA** es la técnica más eficiente para aplicaciones intensivas en CPU.

---

# ✅ Conclusión general

El proyecto demuestra cómo el paralelismo mediante hilos, la planificación de procesos y la ejecución distribuida mejoran significativamente el rendimiento en sistemas basados en Red Hat Enterprise Linux, incluso en entornos virtualizados y sin privilegios de superusuario.

---

Si quieres, el próximo paso puede ser:

* 📄 **Informe en PDF**
* 🧠 **Conclusiones comparativas**
* 🎤 **Guion para exposición**
* 📊 **Tablas de resultados**

Dime 👉 **qué necesitas ahora** y lo armamos.

