# Final project

(description of our C++ final project)

---

## Getting Started

### Usage

`make build` for compiling and linking
`make run` to run the executable
`make clean` fresh start

### Good to know

SFML version: 2.6.1 32 bits
SFML path: `C:/libs/SFML-2.6.1`

### Como funciona

La clase `Game` maneja el bucle principal `Run()`y `SetScene()` se utilizara para cambiar de escena.

Para agregar escenas (menues, pantallas de juego) al proyecto, crear una clase heredada de `Scene` y agregar todo lo necesario como atributos y programas los metodos `Update()` y `Draw()` para manejar el comportamieto y dibujar todo en pantalla.
