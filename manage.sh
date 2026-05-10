#!/bin/bash

# --- CONFIGURACIÓN ---
IDF_PATH_LOCAL="./vendor/espidf-v5.2.1"
PORT="/dev/ttyACM0"
BAUD="460800"

# --- LÓGICA DE ENTORNO ---
# Esta función carga el entorno de Espressif si idf.py no está en el PATH
load_env() {
    if ! command -v idf.py &> /dev/null; then
        echo "🔧 Cargando entorno de ESP-IDF..."
        . $IDF_PATH_LOCAL/export.sh > /dev/null 2>&1
    fi
}

case "$1" in
    build)
        load_env
        idf.py build
        ;;
    flash)
        load_env
        idf.py -p $PORT -b $BAUD flash
        ;;
    monitor)
        load_env
        idf.py -p $PORT monitor
        ;;
    all)
        load_env
        idf.py build && idf.py -p $PORT -b $BAUD flash monitor
        ;;
    clean)
        load_env
        idf.py fullclean
        ;;
    menu)
        load_env
        idf.py menuconfig
        ;;
    *)
        echo "Uso: ./manage.sh {build|flash|monitor|all|clean|menu}"
        exit 1
        ;;
esac