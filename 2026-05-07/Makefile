# Compilador MPI
MPICC = mpicc

# Flags de compilación
CFLAGS = -Wall -Wextra -O2

# Nombre del ejecutable
TARGET = matriz_mpi

# Archivo fuente
SOURCE = matriz_mpi.c

# Número de procesos para ejecutar (8 procesos: 0 al 7)
NP = 8

# Regla por defecto
all: $(TARGET)

# Regla para compilar
$(TARGET): $(SOURCE)
	$(MPICC) $(CFLAGS) -o $(TARGET) $(SOURCE)

# Regla para ejecutar
run: $(TARGET)
	mpirun -np $(NP) ./$(TARGET)

# Regla para ejecutar con más detalles (verbose)
run-verbose: $(TARGET)
	mpirun -np $(NP) --verbose ./$(TARGET)

# Regla para limpiar archivos generados
clean:
	rm -f $(TARGET) *.o

# Regla para limpiar y luego compilar
rebuild: clean all

# Regla para compilar y ejecutar
all-run: all run

# Regla para mostrar ayuda
help:
	@echo "Opciones disponibles:"
	@echo "  make          - Compila el programa"
	@echo "  make run      - Ejecuta el programa con $(NP) procesos"
	@echo "  make clean    - Elimina el ejecutable"
	@echo "  make rebuild  - Limpia y vuelve a compilar"
	@echo "  make all-run  - Compila y ejecuta"
	@echo "  make help     - Muestra esta ayuda"

# Regla para verificar que MPI está instalado
check-mpi:
	@which mpirun > /dev/null || (echo "MPI no está instalado" && exit 1)
	@echo "MPI está instalado correctamente"

.PHONY: all run run-verbose clean rebuild all-run help check-mpi