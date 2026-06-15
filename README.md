#  get_next_line

**get_next_line** es una función en C desarrollada como parte del plan de estudios de [42 School](https://42.fr).  
El objetivo del proyecto es implementar una función capaz de **leer líneas completas desde un descriptor de archivo**, gestionando buffers internos y múltiples descriptores de manera eficiente.


##  Objetivos del Proyecto

- Comprender el manejo de **descriptores de archivos** en C.
- Trabajar con **buffers dinámicos** y controlar su tamaño mediante `BUFFER_SIZE`.
- Implementar una función que devuelva una línea completa en cada llamada.
- Gestionar memoria correctamente para evitar **leaks**.
- Manejar múltiples descriptores de archivos a la vez.


##  Estructura del Proyecto
```
get_next_line/
├── get_next_line.c # Implementación principal de get_next_line
├── get_next_line_utils.c # Funciones auxiliares
├── get_next_line.h # Cabecera principal
├── main.c # Programa de prueba
└── README.md # Documentación del proyecto
```



##  Funcionalidades Implementadas

- Lectura de un archivo línea por línea.
- Manejo de **BUFFER_SIZE** para controlar la lectura parcial.
- Soporte para múltiples descriptores de archivo abiertos a la vez.
- Uso de funciones auxiliares para trabajar con cadenas y memoria dinámica.

---

##  Compilación

Compilar con:
```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```
Donde BUFFER_SIZE puede ajustarse según las necesidades (ejemplo: -D BUFFER_SIZE=1 o -D BUFFER_SIZE=10000).

 Uso
Incluye el archivo de cabecera en tu proyecto:
```
#include "get_next_line.h"
```
Ejemplo de uso:
```
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```
