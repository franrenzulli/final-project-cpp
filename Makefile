# Configuración del compilador
# Ruta sfml: C:/libs/SFML-2.6.1

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -IC:/libs/SFML-2.6.1/include
LDFLAGS = -LC:/libs/SFML-2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system

# Nombres de los archivos fuente y objetos
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:src/%.cpp=build/%.o)

# Nombre del ejecutable de salida
OUTPUT = app

# Target principal: build
build: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(OUTPUT) $(LDFLAGS)

# Target para compilar archivos en build/
build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Target para ejecutar el programa
run: build
	./$(OUTPUT)

# Regla para limpiar archivos generados
clean:
	del /Q .\build\* $(OUTPUT).exe
