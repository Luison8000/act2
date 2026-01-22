Aquí tienes el texto **sin emojis**, listo para **copiar y pegar** tal cual:

---

## Explicación de los comandos utilizados en la terminal


Este poderisismo md describe **cada comando utilizado durante el desarrollo del proyecto**, explicando **qué hace**, **por qué se utiliza** y **en qué etapa del trabajo se aplica**.

---

## Comandos de verificación del entorno

### `uname -a`

```bash
uname -a
```

**Qué poronga hace:**
Muestra información del sistema operativo, incluyendo el kernel, la arquitectura y la distribución.

**Por qué se usa:**
Permite verificar que el entorno de ejecución corresponde a un sistema Linux basado en Red Hat Enterprise Linux, cumpliendo con los requisitos del proyecto.

---

### `gcc --version`

```bash
gcc --version
```

**Qué poronga hace:**
Muestra la versión del compilador GNU C Compiler (GCC).


---

## Comandos de gestión de directorios

### `mkdir`

```bash
mkdir parte1_multihilo
```

**Qué poronga hace:**
Crea un nuevo directorio en el sistema de archivos.

**Parak:**
Permite organizar el proyecto separando los archivos por partes, facilitando la gestión y documentación del trabajo.

---

### `cd`

```bash
cd parte1_multihilo
```

**Qué poronga hace:**
Cambia el directorio de trabajo actual.

**Parak:**
Permite trabajar directamente dentro del directorio donde se encuentran los archivos fuente y ejecutables del proyecto.

---

### `ls`

```bash
ls
```

**Qué poronga hace:**
Lista los archivos y directorios del directorio actual.

**parak:**
Permite verificar qué archivos existen, comprobar que los archivos fuente y ejecutables fueron creados correctamente y detectar errores de nombres o rutas.

---

## Edición de archivos

### `nano`

```bash
nano primos_secuencia1.c
```

**Qué poronga hace:**
Abre el editor de texto `nano` para crear o modificar archivos.

para el codigo fuente 
---

### Guardar y salir de `nano`

```
CTRL + O  → Guardar cambios  
ENTER     → Confirmar nombre del archivo  
CTRL + X  → Salir del editor
```
todo para almacenar jodido codigo 
---

## Compilación de programas

### `gcc archivo.c -o ejecutable`

```bash
gcc primos_secuencia1.c -o primos_secuencias1
```


Compila el archivo fuente en C y genera un archivo ejecutable.

**Por qué se usa:**
Transforma el código escrito en lenguaje C en un programa ejecutable por el sistema operativo.

---

### Compilación con Pthreads

```bash
gcc primos_multihilo.c -o primos_multihilo -lpthread
```

**Qué hace:**
Compila un programa que utiliza la biblioteca `pthread` para multihilos.

**Por qué se usa:**
Es necesario enlazar explícitamente la biblioteca pthread para que el programa pueda crear y gestionar hilos correctamente.

---

## Ejecución de programas

### `./nombre_ejecutable`

```bash
./primos_secuencias1
```

**Qué hace:**
Ejecuta un programa ubicado en el directorio actual.

**Por qué se usa:**
Permite correr el programa compilado y observar su comportamiento y resultados.

---

### `time`

```bash
time ./primos_secuencias1
```

**Qué hace:**
Mide el tiempo de ejecución de un programa.

**Por qué se usa:**
Permite comparar el rendimiento entre la versión secuencial y la versión multihilo del programa.

---

## Planificación de procesos

### `nice`

```bash
nice -n 10 ./primos_multihilo
```

**Qué hace:**
Ejecuta un proceso con menor prioridad de CPU.

**Por qué se usa:**
Permite simular algoritmos de planificación por prioridad y observar su impacto en el tiempo de ejecución.

---

```bash
nice -n -5 ./primos_multihilo
```

**Qué hace:**
Ejecuta un proceso con mayor prioridad de CPU.

**Por qué se usa:**
Permite analizar cómo la asignación de mayor prioridad afecta el tiempo de respuesta del proceso.

---

### `top`

```bash
top
```

**Qué hace:**
Muestra en tiempo real los procesos en ejecución y el uso de recursos del sistema.

**Por qué se usa:**
Permite observar cómo el sistema operativo planifica los procesos y distribuye el uso de CPU entre ellos.

Salir de `top`:

```
q
```

---

## Computación distribuida (Clúster simulado)

### `mpicc`

```bash
mpicc primos_mpi.c -o primos_mpi
```

**Qué hace:**
Compila un programa que utiliza la biblioteca MPI.

**Por qué se usa:**
Es necesario para crear programas capaces de ejecutarse en múltiples procesos simulando nodos de un clúster.

---

### `mpirun`

```bash
mpirun -np 4 ./primos_mpi
```

**Qué hace:**
Ejecuta el programa MPI usando múltiples procesos.

**Por qué se usa:**
Permite simular un clúster de varios nodos y evaluar el rendimiento del cómputo distribuido.

---

## Entrada y salida del sistema

### `lsblk`

```bash
lsblk
```

**Qué hace:**
Lista los dispositivos de almacenamiento del sistema.

**Por qué se usa:**
Permite identificar los dispositivos de entrada y salida disponibles en el sistema.

---

### `lspci`

```bash
lspci
```

**Qué hace:**
Muestra los dispositivos conectados al bus PCI.

**Por qué se usa:**
Permite identificar controladores de almacenamiento, red y otros dispositivos de entrada/salida.

---

### `lsusb`

```bash
lsusb
```

**Qué hace:**
Lista los dispositivos conectados por USB.

**Por qué se usa:**
Permite identificar dispositivos de entrada y salida externos.

---

## Conclusión

El uso de estos comandos permitió desarrollar, compilar, ejecutar y analizar una aplicación multihilo y distribuida en un entorno basado en Red Hat Enterprise Linux, comprendiendo tanto el funcionamiento del sistema operativo como el impacto del paralelismo y la planificación de procesos.

---


