#!/bin/bash

# Script de lanzamiento para BibliotecaMagicaEDDPro1
# Configura el entorno y ejecuta la aplicación

# Obtener el directorio donde está este script
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Configurar variables de entorno para Qt
export LD_LIBRARY_PATH="$DIR/lib:$LD_LIBRARY_PATH"
export QT_PLUGIN_PATH="$DIR/plugins"
export QT_QPA_PLATFORM_PLUGIN_PATH="$DIR/plugins/platforms"

# Ejecutar la aplicación con todos los argumentos pasados
"$DIR/BibliotecaMagicaEDDPro1" "$@"
