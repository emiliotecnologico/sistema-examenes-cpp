# Sistema de Exámenes en C++

## Descripción
Programa de consola que simula un examen de 10 preguntas.  
- Lee las preguntas desde `preguntas.txt` y las respuestas correctas desde `respuestas.txt`.  
- El usuario debe autenticarse (usuario: `admin`, contraseña: `1234`).  
- Calcula la nota final (10 puntos por pregunta) y la muestra en pantalla.  
- Proyecto realizado en los primeros semestres de la carrera como introducción a C++ y manejo de archivos.

## Tecnologías
- C++ (estándar C++11 o superior)
- Librerías: `<iostream>`, `<fstream>`, `<conio.h>` (Windows), `<windows.h>`

## Archivos necesarios para ejecutar
- `algoritmo.cpp` (código fuente)
- `preguntas.txt` (una pregunta por línea)
- `respuestas.txt` (una respuesta correcta por línea, en el mismo orden que las preguntas)

Opcionalmente, si el código original usa `usuarios.txt`, también debe incluirse.

## Compilación y ejecución (Windows)
```bash
g++ algoritmo.cpp -o examen.exe
./examen.exe
