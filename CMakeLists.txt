cmake_minimum_required(VERSION 3.16)

# Forzamos la ruta del IDF a tu carpeta vendor
set(ENV{IDF_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/vendor/espidf-v5.2.1")

# Incluimos el sistema de construcción de Espressif
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# Nombre de tu proyecto
project(prueba)