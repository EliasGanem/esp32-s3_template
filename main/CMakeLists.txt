# Primero, buscamos todos los archivos .c dentro de la carpeta src
file(GLOB SOURCES "src/*.c")

# Registramos el componente
idf_component_register(
    SRCS ${SOURCES}           # Usa la lista de archivos que encontramos en src/
    INCLUDE_DIRS "inc"        # Le dice al compilador que busque los .h en inc/
)